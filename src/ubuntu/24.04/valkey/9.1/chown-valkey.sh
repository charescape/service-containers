#!/bin/sh

set -eux

# One-shot boot prepare. The daemon is started by runit: /etc/service/valkey/run
mkdir -p /wwwdata/valkey/data
mkdir -p /wwwdata/valkey/run
mkdir -p /wwwdata/misc

chown -R www-data:www-data /usr/local/valkey/
chown -R www-data:www-data /wwwdata/
chown www-data:www-data /etc/valkey.conf
