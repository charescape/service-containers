FROM phusion/baseimage:noble-1.0.3

LABEL maintainer="charescape@outlook.com"

ENV TZ="Asia/Shanghai"
ENV PHP_VERSION="8.4.25"
ENV PHP_HASH="5cde1da976b728fa09e6b549a4c8afcd0c180337028dacf34f73b11be50253db"
ENV COMPOSER_VERSION="2.10.3"
ENV COMPOSER_HASH="7a2d379d5b8ffdaa028580ef26494c36d2feef4b178d3dd1473a4dbc5e17c8d6"
ENV KILL_PROCESS_TIMEOUT=60
ENV KILL_ALL_PROCESSES_TIMEOUT=60
ENV PATH="/usr/local/php/bin:/usr/local/php/sbin:${PATH}"

COPY src/ubuntu/24.04/php/8.4/chown-php.sh  /etc/my_init.d/
COPY src/ubuntu/24.04/php/8.4/php.ini  /usr/local/src/
COPY src/ubuntu/24.04/php/8.4/php-fpm.conf  /usr/local/src/
COPY src/ubuntu/24.04/php/8.4/www.conf  /usr/local/src/
COPY src/ubuntu/24.04/php/8.4/php-fpm.run  /usr/local/src/

SHELL ["/bin/bash", "-c"]

RUN set -eux \
&& set -o pipefail \
&& export DEBIAN_FRONTEND=noninteractive \
\
&& free -m            \
\
&& apt -y update            \
&& apt -yq -o Dpkg::Options::="--force-confold" upgrade \
&& apt -y autoremove        \
\
\
&& mkdir -p /wwwdata/php/run \
&& mkdir -p /wwwdata/php/log \
&& mkdir -p /wwwdata/php/sessions \
&& mkdir -p /wwwdata/www \
&& mkdir -p /wwwdata/misc \
&& chown -R www-data:www-data /wwwdata \
\
&& apt -yq --no-install-recommends install tzdata \
build-essential                 \
autoconf                        \
pkg-config                      \
ca-certificates                 \
wget                            \
curl                            \
git                             \
unzip                           \
re2c                            \
bison                           \
libtool                         \
libxml2-dev                     \
libssl-dev                      \
libcurl4-openssl-dev            \
libpcre2-dev                    \
libxslt1-dev                    \
libsqlite3-dev                  \
libbz2-dev                      \
libpng-dev                      \
libavif-dev                     \
libwebp-dev                     \
libjpeg-dev                     \
libxpm-dev                      \
libfreetype6-dev                \
libgmp-dev                      \
libonig-dev                     \
libreadline-dev                 \
libsodium-dev                   \
libargon2-dev                   \
libtidy-dev                     \
libzip-dev                      \
libzstd-dev                     \
libpq-dev                       \
libcapstone-dev                 \
libexpat1-dev                   \
\
\
&& chmod +x /etc/my_init.d/chown-php.sh \
\
&& cd /usr/local \
&& wget --no-verbose https://curl.se/ca/cacert.pem \
&& wget --no-verbose https://curl.se/ca/cacert.pem.sha256 \
&& sha256sum --check cacert.pem.sha256 \
&& rm cacert.pem.sha256 \
\
&& cd /usr/local/src \
\
&& wget --no-verbose https://www.php.net/distributions/php-${PHP_VERSION}.tar.gz \
&& echo "${PHP_HASH} *php-${PHP_VERSION}.tar.gz" | sha256sum --check \
\
&& wget --no-verbose https://getcomposer.org/download/${COMPOSER_VERSION}/composer.phar \
&& echo "${COMPOSER_HASH} *composer.phar" | sha256sum --check \
\
&& tar -zxf php-${PHP_VERSION}.tar.gz \
\
\
&& cd /usr/local/src/php-${PHP_VERSION} \
&& ./configure --prefix=/usr/local/php \
--enable-fpm \
--with-fpm-user=www-data \
--with-fpm-group=www-data \
\
\
--enable-opcache \
--enable-ipv6 \
--enable-ctype \
--enable-dom \
--enable-fileinfo \
--enable-filter \
--enable-mbregex \
--enable-huge-code-pages \
--enable-opcache-jit \
--enable-pdo \
--enable-phar \
--enable-posix \
--enable-session \
--enable-simplexml \
--enable-tokenizer \
--enable-xml \
--with-expat \
--enable-xmlreader \
--enable-xmlwriter \
\
\
--enable-phpdbg \
--disable-short-tags \
--with-openssl \
--with-ftp-ssl \
--with-zlib \
--enable-bcmath \
--with-bz2 \
--enable-calendar \
--with-curl \
--enable-exif \
--enable-gd \
--with-freetype \
--with-avif \
--with-webp \
--with-jpeg \
--with-xpm \
--enable-gd-jis-conv \
--with-gettext \
--with-gmp \
--enable-intl \
--enable-mbstring \
--enable-mysqlnd \
--with-mysqlnd-ssl \
--enable-pdo \
--with-mysqli \
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
--with-sodium \
--with-password-argon2 \
--enable-ftp \
--with-capstone \
--with-pear \
--with-pdo-pgsql \
--enable-zend-max-execution-timers \
\
&& make -j$(nproc --all) \
&& sleep 3s \
&& make install \
\
&& cd /usr/local/src \
&& rm -f /usr/local/php/etc/php-fpm.conf \
&& rm -f /usr/local/php/etc/php-fpm.d/www.conf \
&& rm -f /usr/local/php/lib/php.ini \
\
&& mv ./php-fpm.conf /usr/local/php/etc/php-fpm.conf \
&& mv ./www.conf     /usr/local/php/etc/php-fpm.d/www.conf \
&& mv ./php.ini      /usr/local/php/lib/php.ini \
\
&& mv ./composer.phar /usr/local/bin/composer \
&& chmod +x /usr/local/bin/composer \
\
&& mkdir -p /usr/local/php/fpm_pools/www/log \
&& mkdir -p /usr/local/php/var/run \
&& mkdir -p /usr/local/php/var/log \
\
&& chown www-data:www-data /usr/local/bin/composer \
&& chown -R www-data:www-data /usr/local/php \
&& chown -R www-data:www-data /wwwdata \
\
&& /usr/local/php/bin/php -v \
&& /usr/local/php/bin/php -m \
&& /usr/local/bin/composer --version \
&& /usr/local/php/sbin/php-fpm --fpm-config /usr/local/php/etc/php-fpm.conf -t \
&& ( \
  /usr/local/php/sbin/php-fpm --nodaemonize --fpm-config /usr/local/php/etc/php-fpm.conf & \
  sleep 3s \
  kill -INT "$(cat /usr/local/php/var/run/php-fpm.pid)" \
  wait || true \
) \
\
&& mkdir -p /etc/service/php-fpm \
&& cp /usr/local/src/php-fpm.run /etc/service/php-fpm/run \
&& chmod +x /etc/service/php-fpm/run \
\
&& apt -y autoremove \
&& apt -y clean \
&& rm -rf /var/lib/apt/lists/* \
\
&& rm -rf  /var/cache/fontconfig/* \
&& rm -rf  /var/cache/apt/archives/*.deb \
&& rm -rf  /usr/share/doc/* \
&& rm -rf  /usr/share/man/* \
\
&& rm -rf /tmp/* \
&& rm -rf /var/tmp/* \
\
&& rm -rf  ~/.cache/* \
\
&& du -h --max-depth=2 /usr/local/php \
&& du -h --max-depth=2 /wwwdata \
&& rm -rf /usr/local/src/*

EXPOSE 9000

CMD ["/sbin/my_init"]
