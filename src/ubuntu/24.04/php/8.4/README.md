Ubuntu 24.04 + PHP 8.4

容器启动后，runit 会拉起 `/etc/service/php-fpm/run`。php-fpm master 以 root 运行，worker 为 `www-data`，监听 `0.0.0.0:9000`。不要把 `/usr/local/php` 加进 `PATH`，一律用绝对路径：

```bash
/usr/local/php/bin/php -v
/usr/local/php/bin/php -m
/usr/local/php/sbin/php-fpm --fpm-config /usr/local/php/etc/php-fpm.conf -t
/usr/local/bin/composer --version
```

旁路 OpenResty / nginx 把 FastCGI 指到该容器的 `9000` 端口。

## 容器内（只停/启 php-fpm，容器继续跑）

服务由 runit 管理。不要直接 `kill` php-fpm（停掉后 runit 约 1 秒会再拉起）。

```bash
sv status php-fpm
sv stop php-fpm
sv start php-fpm
sv restart php-fpm
```

## 宿主机

`--stop-timeout 360` 给 worker 走完 `request_terminate_timeout`。未指定时默认 10 秒会被 SIGKILL。`docker stop` / `docker restart` 的 `--timeout 360` 与之相同。

注意事项：

- `session.save_path` 为 `/wwwdata/php/sessions`；站点文件放 `/wwwdata/www`；
- named volume 首次创建会拷贝镜像内目录；不要对这两个路径 bind mount 空目录，除非你就是要用宿主机上的站点代码覆盖 `/wwwdata/www`；
- 另外，最好也不要事先执行 `docker volume create`；
- `-v vol_wwwdata_php_sessions:/wwwdata/php/sessions` 这种写法是 named volume；
- volume 不存在时，docker run 会自动创建；
- 如果先 `docker volume create vol_wwwdata_php_sessions`，volume 是空的，再挂上去时**不会**再拷镜像内容（空 sessions 目录一般仍可用）；
- 所以 sessions / run 这类路径，正确做法就是直接跑这条 docker run，让 Docker 自己建 volume。

确认 volume 是否已由这次启动创建：`docker volume ls | grep vol_wwwdata_php`

```bash
docker run -d \
  --name php84 \
  --hostname hostphp84 \
  --restart unless-stopped \
  --stop-timeout 360 \
  -p 0.0.0.0:9000:9000 \
  -e TZ=Asia/Shanghai \
  -e KILL_PROCESS_TIMEOUT=300 \
  -e KILL_ALL_PROCESSES_TIMEOUT=300 \
  --ulimit nofile=65535:65535 \
  --ulimit nproc=65535:65535 \
  --log-driver json-file \
  --log-opt max-size=10m \
  --log-opt max-file=3 \
  -v vol_wwwdata_php_sessions:/wwwdata/php/sessions \
  -v vol_wwwdata_php_run:/wwwdata/php/run \
  -v /dockerdata/php84/wwwdata_www:/wwwdata/www \
  <镜像>

docker ps
docker logs -f php84

docker exec -t -i php84 bash -l

docker stop --timeout 360 php84
docker start php84
docker restart --timeout 360 php84
```

## 注意事项：

进入容器用 `docker exec -t -i php84 bash -l`。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 php-fpm 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起停掉）。

`docker rm php84` 只删容器；named volume 里的数据还在。
