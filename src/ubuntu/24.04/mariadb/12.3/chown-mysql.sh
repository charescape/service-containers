#!/bin/sh

set -eux

# One-shot boot prepare. The daemon is started by runit: /etc/service/mariadb/run
# Bind-mount of /wwwdata/misc is not seeded from the image.
mkdir -p /wwwdata/misc
if [ ! -f /wwwdata/misc/container.conf ]; then
  cp /etc/container.conf.default /wwwdata/misc/container.conf
fi

chown -R www-data:www-data /usr/local/mysql/
chown -R www-data:www-data /wwwdata/
