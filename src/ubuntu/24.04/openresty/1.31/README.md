Ubuntu 24.04 + OpenResty 1.31

容器启动后，runit 会拉起 `/etc/service/openresty/run`。nginx master 以 root 运行，worker 为 `www-data`，默认监听 `80`。镜像 `PATH` 已包含 `/usr/local/openresty/nginx/sbin`：

```bash
nginx -v
nginx -t
```

## 容器内（只停/启 nginx，容器继续跑）

服务由 runit 管理。不要 `nginx -s stop` / `nginx -s quit`（停掉后 runit 约 1 秒会再拉起）。改配置或换证书后用 reload；进程挂了再用 restart。

```bash
sv status openresty
sv stop openresty
sv start openresty
sv restart openresty
nginx -s reload
nginx -t
```

## 宿主机

`--stop-timeout 360` 给 worker 走完 `worker_shutdown_timeout`。未指定时默认 10 秒会被 SIGKILL。`docker stop` / `docker restart` 的 `--timeout 360` 与之相同。

注意事项：

- 配置和证书放 `/wwwdata/openresty/nginxconf/{http.d,rtmp.d,ssl}`；
- named volume 首次创建会拷贝镜像内目录；不要对 logs / run 执行 bind mount 空目录；
- 另外，最好也不要事先执行 `docker volume create`；
- `-v vol_wwwdata_openresty_logs:/wwwdata/openresty/logs` 这种写法是 named volume；
- volume 不存在时，docker run 会自动创建；
- 如果先 `docker volume create vol_wwwdata_openresty_logs`，volume 是空的，再挂上去时**不会**再拷镜像内容（空 logs 目录一般仍可用）；
- `nginxconf` 用 bind mount：空目录会盖住镜像里的 placeholder，启动脚本会补一个 `00-placeholder.conf`，否则 `include *.conf` 会让 `nginx -t` 失败；
- HTTPS `server` 写在 `http.d`，证书放 `ssl/`，例如 `ssl_certificate /wwwdata/openresty/nginxconf/ssl/example.com.crt;`。

`http.d` 站点样例（`root` 必须与 PHP 里的路径一致）：

```nginx
server {
    listen 80;
    listen [::]:80;
    server_name my_website_001.example.com;
    root /my_shared_dir/repos/my_website_001;
    index index.php index.html;
    location / { try_files $uri $uri/ /index.php$is_args$args; }
    location ~ \.php {
        set $php_fastcgi php8v4:9000;
        fastcgi_pass $php_fastcgi;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $realpath_root$fastcgi_script_name;
        fastcgi_param DOCUMENT_ROOT $realpath_root;
    }
}
```

确认 volume 是否已由这次启动创建：`docker volume ls | grep vol_wwwdata_openresty`

```bash
docker network inspect my_shared_net >/dev/null 2>&1 || docker network create my_shared_net
mkdir -p /dockerdata/my_shared_dir

docker run -d \
  --name openresty1v31 \
  --hostname hostopenresty1v31 \
  --network my_shared_net \
  --restart unless-stopped \
  --stop-timeout 360 \
  -p 0.0.0.0:80:80 \
  -p 0.0.0.0:443:443 \
  -e TZ=Asia/Shanghai \
  -e KILL_PROCESS_TIMEOUT=300 \
  -e KILL_ALL_PROCESSES_TIMEOUT=300 \
  --ulimit nofile=65535:65535 \
  --ulimit nproc=65535:65535 \
  --log-driver json-file \
  --log-opt max-size=10m \
  --log-opt max-file=3 \
  -v vol_wwwdata_openresty_logs:/wwwdata/openresty/logs \
  -v vol_wwwdata_openresty_run:/wwwdata/openresty/run \
  -v /dockerdata/openresty1v31/nginxconf:/wwwdata/openresty/nginxconf \
  -v /dockerdata/my_shared_dir:/my_shared_dir \
  <openresty镜像>

docker ps
docker logs -f openresty1v31

docker exec -t -i openresty1v31 bash -l

docker stop --timeout 360 openresty1v31
docker start openresty1v31
docker restart --timeout 360 openresty1v31
```

## 注意事项：

进入容器用 `docker exec -t -i openresty1v31 bash -l`。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 nginx 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起停掉）。

`docker rm openresty1v31` 只删容器；named volume 里的日志还在。bind mount 的 `nginxconf` 和 `/my_shared_dir` 在宿主机上。
