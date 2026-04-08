#!/bin/bash

set -eux

apt -y update

apt -y upgrade

PHP_VERSION=7.4.12
PHP_HASH=f056d74409a71f17218f76538c6a2d7b59ee99db9db7685fa0ab9cd0d4c0f286

COMPOSER_VERSION=1.10.17
COMPOSER_HASH=6fa00eba5103ce6750f94f87af8356e12cc45d5bbb11a140533790cf60725f1c

OPENRESTY_VERSION=1.19.3.1
OPENRESTY_HASH=f36fcd9c51f4f9eb8aaab8c7f9e21018d5ce97694315b19cacd6ccf53ab03d5d

# apt -y install build-essential \
# zlib1g-dev                      \
# libedit-dev                     \
# libeditline-dev                 \
# libgd-dev                       \
# libicu-dev                      \
# libevent-dev                    \
# chromium-browser                \
# fonts-droid-fallback            \
# ttf-wqy-zenhei                  \
# ttf-wqy-microhei                \
# fonts-arphic-ukai               \
# fonts-arphic-uming

apt -y install build-essential \
autoconf                        \
pkg-config                      \
wget                            \
perl                            \
git                             \
curl                            \
re2c                            \
bison                           \
zip                             \
socat                           \
libtool                         \
libxml2-dev                     \
libssl-dev                      \
libcurl4-openssl-dev            \
libsqlite3-dev                  \
libbz2-dev                      \
libgmp-dev                      \
libonig-dev                     \
libreadline-dev                 \
libsodium-dev                   \
libargon2-0-dev                 \
libtidy-dev                     \
libxslt1-dev                    \
libpng-dev                      \
libwebp-dev                     \
libjpeg-dev                     \
libxpm-dev                      \
libfreetype6-dev                \
libzip-dev                      \
libpcre3-dev                    \
libgeoip-dev

# shellcheck disable=SC2164
cd /usr/local/bin/

wget https://getcomposer.org/download/${COMPOSER_VERSION}/composer.phar

echo "${COMPOSER_HASH} *composer.phar" | shasum -a 256 --check

COMPOSER_HASH_CHECK=$?

if [ "${COMPOSER_HASH_CHECK}" -ne "0" ]; then echo "composer.phar ${COMPOSER_VERSION} hash mismatch." && exit 1; fi

chmod +x /usr/local/bin/composer.phar



# shellcheck disable=SC2164
cd /usr/local/src

wget https://mirrors.sohu.com/php/php-${PHP_VERSION}.tar.gz

echo "${PHP_HASH} *php-${PHP_VERSION}.tar.gz" | shasum -a 256 --check

PHP_HASH_CHECK=$?

if [ "${PHP_HASH_CHECK}" -ne "0" ]; then echo "php-${PHP_VERSION}.tar.gz hash mismatch." && exit 1; fi

tar -zxf php-${PHP_VERSION}.tar.gz


wget https://openresty.org/download/openresty-${OPENRESTY_VERSION}.tar.gz

echo "${OPENRESTY_HASH} *openresty-${OPENRESTY_VERSION}.tar.gz" | shasum -a 256 --check

OPENRESTY_HASH_CHECK=$?

if [ "${OPENRESTY_HASH_CHECK}" -ne "0" ]; then echo "openresty-${OPENRESTY_VERSION}.tar.gz hash mismatch." && exit 1; fi

tar -zxf openresty-${OPENRESTY_VERSION}.tar.gz


mkdir -p /var/www

cd /usr/local/src/php-${PHP_VERSION}
./configure --prefix=/usr/local/php \
--enable-fpm \
--with-fpm-user=www-data \
--with-fpm-group=www-data \
--disable-short-tags \
--with-openssl \
--with-openssl-dir \
--with-pcre-jit \
--with-zlib \
--with-zlib-dir \
--enable-bcmath \
--with-bz2 \
--enable-calendar \
--with-curl \
--enable-exif \
--enable-gd \
--with-freetype \
--with-webp \
--with-jpeg \
--with-xpm \
--enable-gd-jis-conv \
--with-gettext \
--with-gmp \
--with-mhash \
--enable-intl \
--enable-mbstring \
--enable-mysqlnd \
--enable-pdo \
--with-mysqli=mysqlnd \
--with-pdo-mysql=mysqlnd \
--enable-pcntl \
--with-readline \
--enable-soap \
--enable-sockets \
--enable-sysvmsg \
--enable-sysvsem \
--enable-sysvshm \
--enable-shmop \
--with-zip \
--with-xsl \
--with-tidy \
--with-xmlrpc \
--with-iconv-dir \
--with-pear \
--with-sodium \
--with-password-argon2

make
make install

# shellcheck disable=SC2164
cd /usr/local/src

wget https://raw.githubusercontent.com/mobyapps/composed/master/configfiles/php-fpm.conf
wget https://raw.githubusercontent.com/mobyapps/composed/master/configfiles/www.conf
wget https://raw.githubusercontent.com/mobyapps/composed/master/configfiles/php.ini

/bin/cp  ./php-fpm.conf  /usr/local/php/etc/php-fpm.conf
/bin/cp  ./www.conf      /usr/local/php/etc/php-fpm.d/www.conf
/bin/cp  ./php.ini       /usr/local/php/lib/php.ini


chown -R www-data:www-data /usr/local/php

/usr/local/php/bin/php -v
/usr/local/php/sbin/php-fpm
sleep 3s
# shellcheck disable=SC2046
# shellcheck disable=SC2006
kill -INT `cat /usr/local/php/var/run/php-fpm.pid`

chown -R www-data:www-data /usr/local/php



# shellcheck disable=SC2164
cd /usr/local/src/openresty-${OPENRESTY_VERSION}
./configure --prefix=/usr/local/openresty \
--with-threads \
--with-file-aio \
--with-http_ssl_module \
--with-http_v2_module \
--with-http_realip_module \
--with-http_addition_module \
--with-http_sub_module \
--with-http_gunzip_module \
--with-http_gzip_static_module \
--with-http_auth_request_module \
--with-http_random_index_module \
--with-http_secure_link_module \
--with-http_slice_module \
--with-http_stub_status_module \
--without-mail_pop3_module \
--without-mail_imap_module \
--without-mail_smtp_module \
--with-stream \
--with-stream_ssl_module \
--with-stream_realip_module \
--with-stream_ssl_preread_module \
--with-pcre-jit \
--with-http_geoip_module=dynamic \
--with-stream_geoip_module=dynamic \
--with-http_xslt_module=dynamic

make
make install

mkdir -p /var/www/gitrepos
chown -R www-data:www-data /var/www

# shellcheck disable=SC2164
cd /usr/local/src

wget https://raw.githubusercontent.com/mobyapps/composed/master/configfiles/openresty.conf
/bin/cp  ./openresty.conf  /usr/local/openresty/nginx/conf/nginx.conf


chown -R www-data:www-data /usr/local/openresty

/usr/local/openresty/nginx/sbin/nginx -t
/usr/local/openresty/nginx/sbin/nginx
sleep 3s
/usr/local/openresty/nginx/sbin/nginx -s stop

chown -R www-data:www-data /usr/local/openresty


# shellcheck disable=SC2129
echo '' >> ~/.bashrc
# shellcheck disable=SC2016
echo 'export PATH="$PATH:/usr/local/php/bin:/usr/local/php/sbin"' >> ~/.bashrc
# shellcheck disable=SC2016
echo 'export PATH="$PATH:/usr/local/openresty/nginx/sbin"' >> ~/.bashrc
echo '' >> ~/.bashrc


# apt clean
# rm -rf /var/lib/apt/lists/*
# rm -rf /tmp/*
# rm -rf /var/tmp/*
rm -rf /usr/local/src/*
