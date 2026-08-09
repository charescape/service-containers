FROM phusion/baseimage:0.10.2

LABEL maintainer="charescape@outlook.com"

ENV TZ                 "Asia/Shanghai"

ENV MARIADB_VERSION     "5.5.68"

COPY src/ubuntu16-mariadb55/runapps.sh  /etc/my_init.d/
COPY src/ubuntu16-mariadb55/my.cnf  /usr/local/src/

# see http://www.ruanyifeng.com/blog/2017/11/bash-set.html
RUN set -eux \
&& export DEBIAN_FRONTEND=noninteractive \
\
&& free -m            \
\
&& apt -y update            \
&& apt -yq upgrade          \
&& apt -y autoremove        \
\
&& echo '' >> ~/.bashrc         \
&& echo '' >> ~/.bashrc         \
\
&& mkdir -p /repos              \
&& chown -R www-data:www-data /repos \
\
&& apt -yq install build-essential \
sudo                            \
cmake                           \
make                            \
gcc                             \
g++                             \
autoconf                        \
pkg-config                      \
ca-certificates                 \
wget                            \
unzip                           \
clang                           \
automake                        \
perl                            \
git                             \
curl                            \
re2c                            \
bison                           \
zip                             \
p7zip-full                      \
socat                           \
libtool                         \
dnsutils                        \
tree                            \
supervisor                      \
dpkg-dev                        \
libc6-dev                       \
libaio-dev                 \
libpam0g-dev                 \
libevent-dev                 \
libssl-dev                 \
libncurses5-dev                 \
libjemalloc-dev                 \
libboost-dev \
libreadline-dev \
libwrap0-dev \
libxml2-dev \
libsnappy-dev \
liblz4-dev \
libbz2-dev \
libedit-dev \
libncurses-dev \
libgnutls-dev \
libpcre3-dev \
zlib1g-dev \
binutils-dev \
libboost-all-dev \
\
\
&& lsb_release -rs \
&& lsb_release -cs \
&& lsb_release -is \
\
&& chmod +x /etc/my_init.d/runapps.sh \
\
&& cd /usr/local/src \
&& cd /usr/local \
&& wget --no-verbose https://curl.se/ca/cacert.pem \
&& wget --no-verbose https://curl.se/ca/cacert.pem.sha256 \
&& cat cacert.pem.sha256 | shasum -a 256 --check \
&& CACERT_HASH_CHECK=$? \
&& if [ "$CACERT_HASH_CHECK" -ne "0" ]; then echo "cacert.pem hash mismatch." && exit 1; fi \
&& rm cacert.pem.sha256 \
\
&& wget --no-verbose https://fs-1300425912.cos.ap-shanghai.myqcloud.com/localupload/202606/mariadb-${MARIADB_VERSION}.tar.gz \
&& wget --no-verbose https://fs-1300425912.cos.ap-shanghai.myqcloud.com/localupload/202606/mariadb-${MARIADB_VERSION}.sha256sums.txt \
&& cat mariadb-${MARIADB_VERSION}.sha256sums.txt | shasum -a 256 --check \
&& MARIADB_HASH_CHECK=$? \
&& if [ "$MARIADB_HASH_CHECK" -ne "0" ]; then echo "mariadb-${MARIADB_VERSION}.tar.gz hash mismatch." && exit 1; fi \
\
&& tar -zxf mariadb-${MARIADB_VERSION}.tar.gz \
\
\
&& mkdir /usr/local/src/mariadb-${MYSQL_VERSION}/build_tmp_dir \
&& cd /usr/local/src/mariadb-${MYSQL_VERSION}/build_tmp_dir \
&& cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo \
-DCMAKE_INSTALL_PREFIX=/usr/local/mysql \
-DMYSQL_DATADIR=/usr/local/mysql/data \
-DINSTALL_SYSCONFDIR=/usr/local/mysql/mysysconfdir \
-DTMPDIR=/usr/local/mysql/mytmpdir \
-DMYSQL_TCP_PORT=3306 \
-DMYSQL_UNIX_ADDR=/tmp/mysql.sock \
-DDEFAULT_CHARSET=utf8 \
-DDEFAULT_COLLATION=utf8_general_ci \
-DENABLED_LOCAL_INFILE=ON \
-DWITH_EXTRA_CHARSETS=all \
-DWITH_JEMALLOC=yes \
-DWITH_SSL=system \
-DWITH_ZLIB=system \
-DWITH_INNOBASE_STORAGE_ENGINE=ON \
-DWITH_ARCHIVE_STORAGE_ENGINE=ON \
-DWITH_BLACKHOLE_STORAGE_ENGINE=ON \
-DWITH_PARTITION_STORAGE_ENGINE=ON \
-DWITH_PERFSCHEMA_STORAGE_ENGINE=ON \
-DWITH_FEDERATEDX_STORAGE_ENGINE=ON \
-DWITH_TOKUDB_STORAGE_ENGINE=ON \
-DWITH_QUERY_CACHE_INFO=ON \
-DWITH_UNIT_TESTS=OFF \
\
\
&& make -j$(nproc --all) \
&& sleep 3s \
&& make install \
\
\
&& mkdir -p /usr/local/mysql/mysysconfdir \
&& mkdir -p /usr/local/mysql/mytmpdir \
&& mkdir -p /usr/local/mysql/myrundir \
&& mkdir -p /etc/my.cnf.d \
\
\
&& cd /usr/local/src \
&& rm -f       /etc/my.cnf \
&& rm -f       /etc/mysql/my.cnf \
&& rm -f       /root/.my.cnf \
&& rm -f       /usr/local/mysql/mysysconfdir/my.cnf \
\
\
&& cp       ./my.cnf          /etc/my.cnf \
&& chown -R www-data:www-data /etc/my.cnf \
&& chown -R www-data:www-data /usr/local/mysql \
&& /usr/local/mysql/scripts/mysql_install_db --defaults-file=/etc/my.cnf --user=www-data --basedir=/usr/local/mysql --datadir=/usr/local/mysql/data \
\
&& chown -R www-data:www-data /usr/local/mysql \
&& /usr/local/mysql/support-files/mysql.server start \
&& chown -R www-data:www-data /usr/local/mysql \
&& sleep 3s \
&& /usr/local/mysql/bin/mysql -u root -e "UPDATE mysql.user SET Password = PASSWORD('root12345') WHERE user = 'root';" \
&& sleep 3s \
&& /usr/local/mysql/support-files/mysql.server restart \
&& sleep 3s \
&& /usr/local/mysql/bin/mysql -uroot -proot12345 -e "UPDATE mysql.user SET Host='%' WHERE User='root' AND Host='localhost';" \
&& /usr/local/mysql/bin/mysql -uroot -proot12345 -e "UPDATE mysql.db   SET Host='%' WHERE User='root' AND Host='localhost';" \
&& /usr/local/mysql/support-files/mysql.server restart \
&& sleep 3s \
&& /usr/local/mysql/bin/mysql -uroot -proot12345 -e "CREATE DATABASE test0db;" \
&& /usr/local/mysql/bin/mysql -uroot -proot12345 -e "CREATE DATABASE test1db;" \
&& /usr/local/mysql/bin/mysql -uroot -proot12345 -e "CREATE DATABASE test2db;" \
&& sleep 3s \
&& /usr/local/mysql/support-files/mysql.server stop \
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
&& rm -rf /usr/local/mysql/mysql-test/* \
&& du -h --max-depth=2 /usr/local/mysql \
&& rm -rf /usr/local/src/*

EXPOSE 80 443 3306

CMD ["/sbin/my_init"]
