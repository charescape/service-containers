Ubuntu 24.04 + Valkey 9.1

容器启动后，runit 会拉起 `/etc/service/valkey/run`。进程以 `www-data` 运行，监听 `0.0.0.0:6379`。无 `requirepass` 时 `protected-mode` 只接受本机 TCP 和 Unix socket。镜像 `PATH` 已包含 `/usr/local/valkey/bin`：

```bash
valkey-server --version
valkey-cli --version
valkey-cli -s /wwwdata/valkey/run/valkey.sock ping
```

初始化必须走 Unix socket。设密码后远程 TCP 才能连（设完密码后 protected-mode 不再拦非本机连接）：

```bash
valkey-cli -s /wwwdata/valkey/run/valkey.sock CONFIG SET requirepass 'yourpass'
valkey-cli -s /wwwdata/valkey/run/valkey.sock -a 'yourpass' CONFIG REWRITE
valkey-cli -s /wwwdata/valkey/run/valkey.sock -a 'yourpass' ping
```

`CONFIG REWRITE` 写的是容器内 `/etc/valkey.conf`，不在 named volume 上。`docker rm` 再创建容器后密码会丢，要重新执行上面三步。

之后客户端用 `valkey-cli -h <host> -p 6379 -a 'yourpass'`，或 PHP 等连 `valkey9v1:6379`。

## 容器内（只停/启 Valkey，容器继续跑）

服务由 runit 管理，不要 `valkey-cli shutdown`（停掉后 runit 约 1 秒会再拉起）。

```bash
sv status valkey
sv stop valkey
sv start valkey
sv restart valkey
```

## 宿主机

`--stop-timeout 360` 给 RDB / AOF 刷盘。未指定时默认 10 秒会被 SIGKILL。`docker stop` / `docker restart` 的 `--timeout 360` 与之相同。

注意事项：

- named volume 首次创建会拷贝镜像内目录；不要对这两个路径 bind mount 空目录；
- 另外，最好也不要事先执行 `docker volume create`；
- `-v vol_wwwdata_valkey_data:/wwwdata/valkey/data` 这种写法是 named volume；
- volume 不存在时，docker run 会自动创建；
- 如果先 `docker volume create vol_wwwdata_valkey_data`，volume 是空的，再挂上去时**不会**再拷镜像内容（空 datadir 一般仍可用，Valkey 会新建 RDB/AOF）；
- 所以正确做法就是直接跑这条 docker run，让 Docker 自己建这两个 volume。

确认 volume 是否已由这次启动创建：`docker volume ls | grep vol_wwwdata_valkey`

```bash
docker network inspect my_shared_net >/dev/null 2>&1 || docker network create my_shared_net
mkdir -p /dockerdata/my_shared_dir

docker run -d \
  --name valkey9v1 \
  --hostname hostvalkey9v1 \
  --network my_shared_net \
  --restart unless-stopped \
  --stop-timeout 360 \
  -p 0.0.0.0:6379:6379 \
  -e TZ=Asia/Shanghai \
  -e KILL_PROCESS_TIMEOUT=300 \
  -e KILL_ALL_PROCESSES_TIMEOUT=300 \
  --ulimit nofile=65535:65535 \
  --ulimit nproc=65535:65535 \
  --log-driver json-file \
  --log-opt max-size=10m \
  --log-opt max-file=3 \
  -v vol_wwwdata_valkey_data:/wwwdata/valkey/data \
  -v vol_wwwdata_valkey_run:/wwwdata/valkey/run \
  -v /dockerdata/valkey9v1/wwwdata_misc:/wwwdata/misc \
  -v /dockerdata/my_shared_dir:/my_shared_dir \
  <镜像>

docker ps
docker logs -f valkey9v1
docker exec -t valkey9v1 tail -f /wwwdata/valkey/run/valkey.log

docker exec -t -i valkey9v1 bash -l

docker stop --timeout 360 valkey9v1
docker start valkey9v1
docker restart --timeout 360 valkey9v1
```

## 注意事项：

进入容器用 `docker exec -t -i valkey9v1 bash -l`。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 Valkey 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起停掉）。

`docker logs` 只有 my_init / runit。Valkey 日志在 `/wwwdata/valkey/run/valkey.log`（随 `vol_wwwdata_valkey_run` 持久）。

`docker rm valkey9v1` 只删容器；data / run volume 里的数据还在。`/etc/valkey.conf`（含 `requirepass`）不在 volume 里，会一起丢掉。
