wget http://ftp.gnu.org/gnu/bison/bison-2.6.4.tar.gz

# https://github.com/fede2cr/slackware_riscv/issues/2
sed -i 's/IO_ftrylockfile/IO_EOF_SEEN/' lib/*.c
echo "#define _IO_IN_BACKUP 0x100" >> lib/stdio-impl.h

YACC=/usr/local/bison264/bin/bison ./configure  --prefix=/usr/local/php54 \
--enable-fpm \
--with-fpm-user=www-data \
--with-fpm-group=www-data \
--disable-short-tags \
--with-libxml-dir \
--with-openssl=/usr/local/openssl102u \
--with-openssl-dir=/usr/local/openssl102u \
--with-pcre-regex \
--with-pcre-dir \
--with-zlib \
--with-zlib-dir \
--enable-bcmath \
--with-bz2 \
--enable-calendar \
--with-curl \
--with-enchant=/usr/local/enchant161 \
--enable-exif \
--enable-ftp \
--with-gd \
--with-jpeg-dir \
--with-xpm-dir \
--with-png-dir \
--with-freetype-dir=/usr/local/freetype2133 \
--enable-gd-native-ttf \
--enable-gd-jis-conv \
--with-gettext \
--with-gmp \
--with-mhash \
--enable-mbstring \
--with-mcrypt \
--with-mysql \
--with-mysqli \
--with-pdo-mysql \
--enable-pcntl \
--with-readline \
--enable-zip \
--enable-mysqlnd \
--enable-pdo \
--enable-intl \
--with-icu-dir=/usr/local/icu60 \
--with-pspell \
--with-recode \
--enable-soap \
--enable-sockets \
--enable-sysvmsg \
--enable-sysvsem \
--enable-sysvshm \
--enable-shmop \
--with-xsl \
--with-tidy \
--with-xmlrpc \
--with-iconv-dir \
--with-pear

wget https://github.com/rrthomas/enchant/releases/download/enchant-1-6-1/enchant-1.6.1.tar.gz
apt install libhunspell-dev
./configure  --prefix=/usr/local/enchant161

wget https://jaist.dl.sourceforge.net/project/freetype/freetype2/2.13.3/freetype-2.13.3.tar.gz
apt install libpng-dev
./configure --prefix=/usr/local/freetype2133 --enable-freetype-config

ln -s /usr/include/x86_64-linux-gnu/gmp.h /usr/include/gmp.h
ln -s /usr/lib/x86_64-linux-gnu/libXpm.a /usr/lib/libXpm.a

# https://blog.hanhans.net/2020/06/08/php-compile-with-focal/
./runConfigureICU Linux --prefix=/usr/local/icu60

ln -s /usr/local/icu60/lib/libicudata.so.60    /usr/lib/x86_64-linux-gnu/libicudata.so.60
ln -s /usr/local/icu60/lib/libicui18n.so.60    /usr/lib/x86_64-linux-gnu/libicui18n.so.60
ln -s /usr/local/icu60/lib/libicuio.so.60    /usr/lib/x86_64-linux-gnu/libicuio.so.60
ln -s /usr/local/icu60/lib/libicutest.so.60    /usr/lib/x86_64-linux-gnu/libicutest.so.60
ln -s /usr/local/icu60/lib/libicutu.so.60    /usr/lib/x86_64-linux-gnu/libicutu.so.60
ln -s /usr/local/icu60/lib/libicuuc.so.60    /usr/lib/x86_64-linux-gnu/libicuuc.so.60


# OpenSSL问题
# https://www.cnblogs.com/anekec/articles/17473186.html
# https://openssl.org/source/old/1.0.2/openssl-1.0.2u.tar.gz

apt install libcurl4-gnutls-dev \
libcurl4-openssl-dev \
libmcrypt-dev \
libpspell-dev \
librecode-dev \
libenchant-2-dev \
libxpm-dev \
\
\
build-essential \
tzdata \
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
imagemagick


ln -s /usr/include/x86_64-linux-gnu/curl /usr/include/

./configure --prefix=/usr/local/php54 \
--enable-fpm \
--with-fpm-user=www-data \
--with-fpm-group=www-data \
--enable-phpdbg \
--disable-short-tags \
--with-libxml-dir \
--with-openssl \
--with-openssl-dir \
--with-pcre-regex \
--with-pcre-dir \
--with-zlib \
--with-zlib-dir \
--enable-bcmath \
--with-bz2 \
--enable-calendar \
--with-curl \
--with-enchant \
--enable-exif \
--enable-ftp \
--with-gd \
--with-jpeg-dir \
--with-xpm-dir \
--with-png-dir \
--with-freetype-dir \
--enable-gd-native-ttf \
--enable-gd-jis-conv \
--with-gettext \
--with-gmp \
--with-mhash \
--enable-mbstring \
--with-mcrypt \
--with-mysql \
--with-mysqli \
--with-pdo-mysql \
--enable-opcache \
--enable-pcntl \
--with-readline \
--enable-zip \
--enable-mysqlnd \
--enable-pdo \
--enable-intl \
--with-icu-dir=/usr \
--with-pspell \
--with-recode \
--enable-soap \
--enable-sockets \
--enable-sysvmsg \
--enable-sysvsem \
--enable-sysvshm \
--enable-shmop \
--with-xsl \
--with-tidy \
--with-xmlrpc \
--with-iconv-dir \
--with-pear
