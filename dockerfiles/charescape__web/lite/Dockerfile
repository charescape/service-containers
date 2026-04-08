FROM phusion/baseimage:jammy-1.0.2

LABEL maintainer="charescape@outlook.com"

ENV TZ                  Asia/Shanghai

ENV PHP_VERSION         8.2.17
ENV PHP_HASH            1d8ab98e1c09518c672c5afcbef0e61f9003173c7638fc686461ae670d12742e

ENV COMPOSER_VERSION    2.7.2
ENV COMPOSER_HASH       049b8e0ed9f264d770a0510858cffbc35401510759edc9a784b3a5c6e020bcac

ENV OPENRESTY_VERSION   1.25.3.1
ENV OPENRESTY_HASH      32ec1a253a5a13250355a075fe65b7d63ec45c560bbe213350f0992a57cd79df

COPY ./dockerfiles/charescape__web/lite/runapps.sh  /etc/my_init.d/

ADD https://raw.githubusercontent.com/mobyapps/composed/ubuntu22-php82-mysql80/configfiles/php.ini                 /usr/local/src/
ADD https://raw.githubusercontent.com/mobyapps/composed/ubuntu22-php82-mysql80/configfiles/php-fpm.conf            /usr/local/src/
ADD https://raw.githubusercontent.com/mobyapps/composed/ubuntu22-php82-mysql80/configfiles/www.conf                /usr/local/src/
ADD https://raw.githubusercontent.com/mobyapps/composed/ubuntu22-php82-mysql80/configfiles/openresty_testing.conf  /usr/local/src/
ADD https://raw.githubusercontent.com/mobyapps/composed/ubuntu22-php82-mysql80/ttt/dbapi.php                       /usr/local/src/

# see http://www.ruanyifeng.com/blog/2017/11/bash-set.html
RUN set -eux \
&& export DEBIAN_FRONTEND=noninteractive \
&& export CPUS_COUNT=`cat /proc/cpuinfo | grep processor | wc -l` \
\
&& date -d "1 day ago" \
&& echo "${TZ}" > /etc/timezone \
&& ln -sf /usr/share/zoneinfo/${TZ} /etc/localtime \
&& cat /etc/timezone \
\
&& apt -y update            \
&& apt -y upgrade           \
&& apt -y autoremove           \
&& apt -y install --fix-broken  \
&& apt -y install --fix-missing \
\
&& echo '' >> ~/.bashrc         \
\
&& apt -y install tzdata build-essential \
cmake                           \
autoconf                        \
pkg-config                      \
wget                            \
perl                            \
git                             \
git-lfs                         \
curl                            \
re2c                            \
bison                           \
zip                             \
p7zip-full                      \
socat                           \
zstd                            \
libtool                         \
dnsutils                        \
libmaxminddb-dev                        \
libpcre3-dev                    \
libxslt1-dev                    \
libgeoip-dev                    \
libcapstone-dev                    \
libsqlite3-dev                  \
libbz2-dev                      \
libcurl4-openssl-dev            \
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
libssl-dev                      \
                        \
                        \
                        \
                        \
imagemagick                     \
supervisor                      \
memcached                       \
libmemcached-tools              \
libmemcached-dev                \
                \
libc6-dev                     \
libxml2-dev                     \
libjemalloc-dev                 \
libzstd-dev                     \
libedit-dev                     \
libevent-dev                    \
liblz4-dev                      \
libsasl2-dev                    \
libldap2-dev                    \
\
\
libvulkan1                      \
\
\
nodejs \
npm \
chromium-chromedriver \
firefox \
libgtk2.0-0 \
libgtk-3-0 \
libnotify-dev \
libgconf-2-4 \
libgbm-dev \
libnss3 \
libxss1 \
libasound2 \
libxtst6 \
xauth \
xvfb \
libu2f-udev \
\
fontconfig \
fonts-noto-color-emoji \
fonts-arphic-bkai00mp \
fonts-arphic-bsmi00lp \
fonts-arphic-gbsn00lp \
fonts-arphic-gkai00mp \
fonts-arphic-ukai \
fonts-arphic-uming \
fonts-wqy-zenhei \
fonts-wqy-microhei \
xfonts-wqy \
\
fonts-liberation \
libappindicator3-1 \
xdg-utils \
mplayer \
\
\
&& date -d "1 day ago" \
&& ls -l /usr/share/zoneinfo/ \
&& ls -l /usr/share/zoneinfo/Asia/ \
\
\
&& chmod +x /etc/my_init.d/runapps.sh \
\
\
&& cd /usr/local/bin/ \
&& wget --no-verbose https://getcomposer.org/download/${COMPOSER_VERSION}/composer.phar \
&& echo "${COMPOSER_HASH} *composer.phar" | shasum -a 256 --check \
&& COMPOSER_HASH_CHECK=$? \
&& if [ "$COMPOSER_HASH_CHECK" -ne "0" ]; then echo "composer.phar hash mismatch." && exit 1; fi \
\
&& mv /usr/local/bin/composer.phar /usr/local/bin/composer \
&& chmod +x /usr/local/bin/composer \
&& chown www-data:www-data /usr/local/bin/composer \
\
&& cd /usr/local \
&& wget --no-verbose https://curl.se/ca/cacert.pem \
&& wget --no-verbose https://curl.se/ca/cacert.pem.sha256 \
&& cat cacert.pem.sha256 | shasum -a 256 --check \
&& CACERT_HASH_CHECK=$? \
&& if [ "$CACERT_HASH_CHECK" -ne "0" ]; then echo "cacert.pem hash mismatch." && exit 1; fi \
&& rm cacert.pem.sha256 \
\
&& cd /usr/local/src \
\
&& wget --no-verbose https://www.php.net/distributions/php-${PHP_VERSION}.tar.gz \
&& echo "${PHP_HASH} *php-${PHP_VERSION}.tar.gz" | shasum -a 256 --check \
&& PHP_HASH_CHECK=$? \
&& if [ "$PHP_HASH_CHECK" -ne "0" ]; then echo "php-${PHP_VERSION}.tar.gz hash mismatch." && exit 1; fi \
\
&& wget --no-verbose https://openresty.org/download/openresty-${OPENRESTY_VERSION}.tar.gz \
&& echo "${OPENRESTY_HASH} *openresty-${OPENRESTY_VERSION}.tar.gz" | shasum -a 256 --check \
&& OPENRESTY_HASH_CHECK=$? \
&& if [ "$OPENRESTY_HASH_CHECK" -ne "0" ]; then echo "openresty-${OPENRESTY_VERSION}.tar.gz hash mismatch." && exit 1; fi \
\
&& wget --no-verbose https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb \
&& dpkg -i google-chrome-stable_current_amd64.deb \
&& apt     install -y --fix-broken \
&& apt     install -y --fix-missing \
\
&& tar -zxf php-${PHP_VERSION}.tar.gz \
&& tar -zxf openresty-${OPENRESTY_VERSION}.tar.gz \
\
\
&& mkdir -p /var/www/ip_site \
&& mkdir -p /var/www/runlogs \
&& chown -R www-data:www-data /var/www \
\
\
&& cd /usr/local/src/php-${PHP_VERSION} \
&& ./configure --help \
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
--enable-xmlreader \
--enable-xmlwriter \
\
\
--enable-phpdbg \
--disable-short-tags \
--with-openssl \
--with-openssl-dir \
--with-zlib \
--with-zlib-dir \
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
--with-mhash \
--enable-intl \
--enable-mbstring \
--enable-mysqlnd \
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
\
&& make -j$CPUS_COUNT \
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
&& chown -R www-data:www-data /usr/local/php \
\
&& /usr/local/php/bin/php -v \
&& sleep  3s \
&& /usr/local/php/sbin/php-fpm \
&& sleep  3s \
&& kill -INT `cat /usr/local/php/var/run/php-fpm.pid` \
\
\
&& ls -l /usr/local/php/bin \
&& ls -l /usr/local/php/sbin \
&& /usr/local/php/bin/pecl install memcached \
&& /usr/local/php/bin/php -m \
\
\
&& cd /usr/local/src \
&& git clone --depth 1 --branch master  git@github.com:vozlt/nginx-module-vts.git \
&& git clone --depth 1 --branch v1.2.11 git@github.com:winshining/nginx-http-flv-module.git \
&& git clone --depth 1 --branch master  git@github.com:leev/ngx_http_geoip2_module.git \
&& git clone --depth 1 --branch 1.3.0   git@github.com:evanmiller/mod_zip.git \
\
&& cd /usr/local/src/openresty-${OPENRESTY_VERSION} \
&& ./configure --help \
&& ./configure --prefix=/usr/local/openresty \
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
--with-http_iconv_module \
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
--with-http_xslt_module=dynamic \
--add-dynamic-module=/usr/local/src/nginx-module-vts \
--add-dynamic-module=/usr/local/src/nginx-http-flv-module \
--add-dynamic-module=/usr/local/src/ngx_http_geoip2_module \
--add-dynamic-module=/usr/local/src/mod_zip \
\
&& gmake -j$CPUS_COUNT \
&& sleep  3s \
&& gmake install \
\
&& cd /usr/local/src \
&& rm -f                        /usr/local/openresty/nginx/conf/nginx.conf \
&& mv ./openresty_testing.conf  /usr/local/openresty/nginx/conf/nginx.conf \
\
\
&& mkdir                       /repos \
&& mkdir -p                    /repos/ttt/dbapi \
&& cp ./dbapi.php              /repos/ttt/dbapi/index.php \
&& chown -R www-data:www-data  /var/www \
\
\
&& /usr/local/openresty/nginx/sbin/nginx -t \
&& /usr/local/openresty/nginx/sbin/nginx \
&& sleep 3s \
&& /usr/local/openresty/nginx/sbin/nginx -s stop \
\
&& echo '' >> ~/.bashrc \
&& echo 'export PATH="$PATH:/usr/local/php/bin:/usr/local/php/sbin"' >> ~/.bashrc \
&& echo 'export PATH="$PATH:/usr/local/openresty/nginx/sbin"' >> ~/.bashrc \
&& echo '' >> ~/.bashrc \
\
&& apt -y autoremove \
&& apt clean \
&& rm -rf /var/lib/apt/lists/* \
&& rm -rf /tmp/* \
&& rm -rf /var/tmp/* \
&& du -h --max-depth=2 /usr/local/php \
&& du -h --max-depth=2 /usr/local/openresty \
&& du -h --max-depth=3 /var/www \
&& rm -rf /usr/local/src/*

EXPOSE 80 443

CMD ["/sbin/my_init"]

# source ~/.bashrc
