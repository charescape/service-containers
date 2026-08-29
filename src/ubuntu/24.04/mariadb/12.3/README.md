Ubuntu 24.04 + MariaDB 12.3

容器启动后，runit 会拉起 `/etc/service/mariadb/run`。客户端 `my.cnf` 默认走 TCP，初始化必须用 `--protocol=socket`（unix_socket 认证，OS root 免密）：

```bash
mariadb --protocol=socket -u root -e "SET PASSWORD = PASSWORD('root12345');"
mariadb --protocol=socket -u root -e "CREATE USER 'root'@'%' IDENTIFIED BY 'root12345';"
mariadb --protocol=socket -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;"
mariadb --protocol=socket -u root -e "CREATE DATABASE test0db;"
mariadb --protocol=socket -u root -e "CREATE DATABASE test1db;"
mariadb --protocol=socket -u root -e "CREATE DATABASE test2db;"
mariadb --protocol=socket -u root -e "FLUSH PRIVILEGES;"
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

`-t 60` 对应镜像 `KILL_PROCESS_TIMEOUT=60`，给 InnoDB 刷盘。默认 10 秒会被 SIGKILL。

```bash
docker build -f src/ubuntu/24.04/mariadb/12.3/Dockerfile -t mariadb:12.3.3 .

docker run -d --name mariadb1233 -p 3306:3306 -v /path/on/host/mysql:/wwwdata/mysql mariadb:12.3.3

docker ps
docker logs -f mariadb1233

docker exec -it mariadb1233 bash -l

docker stop -t 60 mariadb1233
docker start mariadb1233
docker restart -t 60 mariadb1233
```

进入容器用 `docker exec`。不要 `docker run -it … bash`（会跳过 `/sbin/my_init`，runit 和 MariaDB 都不会起来）。不要 `docker attach` 再 Ctrl-C（可能把 PID 1 一起干掉）。

`docker rm mariadb1233` 只删容器；数据在 volume 里还在。
