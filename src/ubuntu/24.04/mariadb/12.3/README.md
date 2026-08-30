Ubuntu 24.04 + MariaDB 12.3

容器启动后，runit 会拉起 `/etc/service/mariadb/run`。客户端 `my.cnf` 默认 `host=127.0.0.1` 且 `protocol=tcp`。初始化必须走 Unix socket（unix_socket 认证，OS root 免密），因此要同时覆盖这两项：只加 `--protocol=socket` 仍会连 `127.0.0.1`，在 `skip_name_resolve` 下对不上 `root@localhost`。

```bash
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "CREATE USER 'root'@'%' IDENTIFIED BY 'root12345';"
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;"
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "CREATE DATABASE test0db;"
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "CREATE DATABASE test1db;"
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "CREATE DATABASE test2db;"
/usr/local/mysql/bin/mariadb -h localhost --protocol=socket -u root -e "FLUSH PRIVILEGES;"
```

## 容器内（只停/启 MariaDB，容器继续跑）

服务由 runit 管理，不要用 `mysql.server` 或 `mariadb-admin shutdown`（后者停掉后 runit 约 1 秒会再拉起）。

```bash
sv status mariadb
sv stop mariadb
sv start mariadb
sv restart mariadb
```

## 宿主机

`--stop-timeout 360` 给 InnoDB 刷盘。未指定时默认 10 秒会被 SIGKILL。`docker stop` / `docker restart` 的 `--timeout 360` 与之相同。

注意事项：

- 镜像构建时已在 `/wwwdata/mysql/data` 跑过 `mariadb-install-db`；
- named volume 首次创建会拷贝镜像内已初始化的内容，不要对这两个路径 bind mount 空目录；
- 另外，最好也不要事先执行 `docker volume create`；
- `-v vol_wwwdata_mysql_data:/wwwdata/mysql/data` 这种写法是 named volume；
- volume 不存在时，docker run 会自动创建；
- 如果先 `docker volume create vol_wwwdata_mysql_data`，volume 是空的，再挂上去时**不会**再拷镜像内容，MariaDB 会面对空 datadir，启动会失败或需要重新初始化；
- 所以正确做法就是直接跑这条 docker run，让 Docker 自己建这两个 volume。

确认 volume 是否已由这次启动创建：`docker volume ls | grep vol_wwwdata_mysql`

```bash
docker network create my_shared_net
mkdir -p /dockerdata/my_shared_dir

docker run -d \
  --name mariadb12v3 \
  --hostname hostmariadb12v3 \
  --network my_shared_net \
  --restart unless-stopped \
  --stop-timeout 360 \
  -p 0.0.0.0:3306:3306 \
  -e TZ=Asia/Shanghai \
  -e KILL_PROCESS_TIMEOUT=300 \
  -e KILL_ALL_PROCESSES_TIMEOUT=300 \
  --ulimit nofile=65535:65535 \
  --ulimit nproc=65535:65535 \
  --shm-size=1g \
  --log-driver json-file \
  --log-opt max-size=10m \
  --log-opt max-file=3 \
  -v vol_wwwdata_mysql_data:/wwwdata/mysql/data \
  -v vol_wwwdata_mysql_run:/wwwdata/mysql/run \
  -v /dockerdata/mariadb12v3/wwwdata_misc:/wwwdata/misc \
  -v /dockerdata/my_shared_dir:/my_shared_dir \
  <镜像>

docker ps
docker logs -f mariadb12v3

docker exec -t -i mariadb12v3 bash -l

docker stop --timeout 360 mariadb12v3
docker start mariadb12v3
docker restart --timeout 360 mariadb12v3
```

## 注意事项：

进入容器用 `docker exec -t -i mariadb12v3 bash -l`。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 MariaDB 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起停掉）。

`docker rm mariadb12v3` 只删容器；数据在 volume 里还在。
