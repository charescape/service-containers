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
