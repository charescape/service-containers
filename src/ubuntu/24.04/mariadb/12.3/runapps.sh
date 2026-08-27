#!/bin/bash

set -eux

chown -R www-data:www-data /usr/local/mysql/
chown -R www-data:www-data /data/mysql/

/usr/local/mysql/support-files/mysql.server start

chown -R www-data:www-data /usr/local/mysql/
chown -R www-data:www-data /data/mysql/

pgrep -a mariadbd
