#!/bin/bash

set -eux

chown -R www-data:www-data /usr/local/mysql/

/usr/local/mysql/support-files/mysql.server start

chown -R www-data:www-data /usr/local/mysql/

pgrep -l mysql
