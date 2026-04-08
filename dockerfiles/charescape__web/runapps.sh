#!/bin/bash

set -eux


# find /repos -not \( -path "*/node_modules/*" -o -path "*/\.git/*" \) -exec chown www-data:www-data {} \;

# chown -R www-data:www-data /repos/
chown -R www-data:www-data /usr/local/mysql/
chown -R www-data:www-data /usr/local/php/
chown -R www-data:www-data /usr/local/openresty/

/usr/local/mysql/support-files/mysql.server start

/usr/local/php/bin/php -v
/usr/local/php/sbin/php-fpm
memcached -d -m 512 -p 11211 -l 0.0.0.0 -u root

if [ -f /repos/nginx-external.conf ]
then
  /usr/local/openresty/nginx/sbin/nginx -c /repos/nginx-external.conf -t
  /usr/local/openresty/nginx/sbin/nginx -c /repos/nginx-external.conf
else
  if [ -f /repos/nginx-override.conf ]; then
    rm -f                          /usr/local/openresty/nginx/conf/nginx.conf
    cp /repos/nginx-override.conf  /usr/local/openresty/nginx/conf/nginx.conf

    chown -R www-data:www-data       /usr/local/openresty/
  fi

  /usr/local/openresty/nginx/sbin/nginx -t
  /usr/local/openresty/nginx/sbin/nginx
fi

pgrep -l mysql
pgrep -l php
pgrep -l nginx
pgrep -l memcached
