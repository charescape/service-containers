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

服务由 runit 管理，不要用 `mysql.server` 或 `mariadb-admin shutdown`（后者停掉后 runit 约 1 秒会再拉起）。

```bash
sv status mariadb
sv stop mariadb
sv start mariadb
sv restart mariadb
```

整台容器一起停：宿主机执行 `docker stop -t 60 <容器>`（镜像 `KILL_PROCESS_TIMEOUT=60`，给 InnoDB 刷盘）。
