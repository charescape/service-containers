#!/bin/sh

set -eux

# One-shot boot prepare. The daemon is started by runit: /etc/service/mariadb/run
chown -R www-data:www-data /usr/local/mysql/
chown -R www-data:www-data /wwwdata/mysql/
