Ubuntu 24.04 + MariaDB 12.3

容器启动后，runit 会拉起 `/etc/service/mariadb/run`。客户端 `my.cnf` 默认走 TCP，初始化必须用 `--protocol=socket`（unix_socket 认证，OS root 免密）：

```bash
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "SET PASSWORD = PASSWORD('root12345');"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "CREATE USER 'root'@'%' IDENTIFIED BY 'root12345';"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "CREATE DATABASE test0db;"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "CREATE DATABASE test1db;"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "CREATE DATABASE test2db;"
/usr/local/mysql/bin/mariadb --protocol=socket -u root -e "FLUSH PRIVILEGES;"
```

## 容器内（只停/启 MariaDB，容器继续跑）

服务由 runit 管理，不要用 `mysql.server` 或 `mariadb-admin shutdown`（后者停掉后 runit 约 1 秒会再拉起）。

```bash
sv status mariadb
sv stop mariadb
sv start mariadb
sv restart mariadb
```

## 宿主机（整台容器）

`--stop-timeout 360` 给 InnoDB 刷盘。未指定时默认 10 秒会被 SIGKILL。`docker stop` / `docker restart` 的 `--timeout 360` 与之相同。

```bash
docker run -d \
  --name mariadb12v3 \
  --hostname hostmariadb12v3 \
  --restart unless-stopped \
  --stop-timeout 360 \
  -p 0.0.0.0:3306:3306 \
  -p 0.0.0.0:13306:13306 \
  -e TZ=Asia/Shanghai \
  -e KILL_PROCESS_TIMEOUT=300 \
  -e KILL_ALL_PROCESSES_TIMEOUT=300 \
  --ulimit nofile=65535:65535 \
  --ulimit nproc=65535:65535 \
  --shm-size=1g \
  --log-driver json-file \
  --log-opt max-size=10m \
  --log-opt max-file=3 \
  -v /dockerdata/mariadb12v3/wwwdata_mysql_data:/wwwdata/mysql/data \
  -v /dockerdata/mariadb12v3/wwwdata_mysql_run:/wwwdata/mysql/run \
  -v /dockerdata/mariadb12v3/wwwdata_misc:/wwwdata/misc \
  <镜像>

docker ps
docker logs -f mariadb12v3

docker exec -t -i mariadb12v3 bash -l

docker stop --timeout 360 mariadb12v3
docker start mariadb12v3
docker restart --timeout 360 mariadb12v3
```

进入容器用 `docker exec -t -i mariadb12v3 bash -l`。客户端用 `/usr/local/mysql/bin/mariadb`，不把该目录加入 PATH。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 MariaDB 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起干掉）。

`docker rm mariadb12v3` 只删容器；数据在 volume 里还在。
