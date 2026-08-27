FROM phusion/baseimage:noble-1.0.3

LABEL maintainer="charescape@outlook.com"

ENV TZ="Asia/Shanghai"
ENV MARIADB_VERSION="12.3.3"
ENV KILL_PROCESS_TIMEOUT=60
ENV KILL_ALL_PROCESSES_TIMEOUT=60

COPY src/ubuntu/24.04/mariadb/12.3/runapps.sh  /etc/my_init.d/
COPY src/ubuntu/24.04/mariadb/12.3/my.cnf  /usr/local/src/
COPY src/ubuntu/24.04/mariadb/12.3/mariadb.run  /etc/service/mariadb/run

# see http://www.ruanyifeng.com/blog/2017/11/bash-set.html
RUN set -eux \
&& export DEBIAN_FRONTEND=noninteractive \
\
&& free -m            \
\
&& apt -y update            \
&& apt -yq -o Dpkg::Options::="--force-confold" upgrade \
&& apt -y autoremove        \
\
&& echo '' >> ~/.bashrc         \
&& echo '' >> ~/.bashrc         \
\
&& mkdir -p /data/mysql         \
&& chown -R www-data:www-data /data/mysql \
\
&& apt -yq --no-install-recommends install tzdata \
build-essential                 \
cmake                           \
pkg-config                      \
ca-certificates                 \
wget                            \
perl                            \
bison                           \
flex                            \
libaio-dev                      \
liburing-dev                    \
libnuma-dev                     \
libpam0g-dev                    \
libssl-dev                      \
libkrb5-dev                     \
libcurl4-openssl-dev            \
libncurses-dev                  \
libboost-all-dev                \
libjudy-dev                     \
libxml2-dev                     \
libsnappy-dev                   \
liblzo2-dev                     \
liblz4-dev                      \
liblzma-dev                     \
libbz2-dev                      \
libzstd-dev                     \
libfmt-dev                      \
libpcre2-dev                    \
zlib1g-dev                      \
\
\
&& chmod +x /etc/my_init.d/runapps.sh \
&& chmod +x /etc/service/mariadb/run \
\
&& cd /usr/local/src \
\
&& wget --no-verbose https://archive.mariadb.org/mariadb-${MARIADB_VERSION}/source/mariadb-${MARIADB_VERSION}.tar.gz \
&& wget --no-verbose https://archive.mariadb.org/mariadb-${MARIADB_VERSION}/source/sha256sums.txt \
&& grep "mariadb-${MARIADB_VERSION}.tar.gz\$" sha256sums.txt | shasum -a 256 --check \
&& MARIADB_HASH_CHECK=$? \
&& if [ "$MARIADB_HASH_CHECK" -ne "0" ]; then echo "mariadb-${MARIADB_VERSION}.tar.gz hash mismatch." && exit 1; fi \
\
&& tar -zxf mariadb-${MARIADB_VERSION}.tar.gz \
\
\
&& mkdir /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cd /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo \
-DCMAKE_INSTALL_PREFIX=/usr/local/mysql \
-DMYSQL_DATADIR=/data/mysql \
-DTMPDIR=/tmp \
-DINSTALL_RUNDIR=/tmp \
-DWITH_EXTRA_CHARSETS=all \
-DPLUGIN_COLUMNSTORE=NO \
-DENABLED_LOCAL_INFILE=1 \
-DWITH_URING=ON \
-DWITH_LIBAIO=OFF \
-DWITH_NUMA=AUTO \
-DWITH_ROCKSDB_ZSTD=ON \
-DWITH_INNODB_AHI=ON \
-DWITH_MARIABACKUP=ON \
-DWITH_SYSTEMD=no \
-DWITH_SSL=system \
-DWITH_LIBFMT=auto \
-DWITH_ZLIB=system \
-DWITH_UNIT_TESTS=0 \
\
\
&& make -j$(nproc --all) \
&& sleep 3s \
&& make install \
\
\
&& cd /usr/local/src \
&& rm -f       /etc/my.cnf \
&& rm -f       /etc/mysql/my.cnf \
&& rm -f       /root/.my.cnf \
\
\
&& cp       ./my.cnf          /etc/my.cnf \
&& chown -R www-data:www-data /etc/my.cnf \
&& chown -R www-data:www-data /usr/local/mysql \
&& chown -R www-data:www-data /data/mysql \
&& /usr/local/mysql/scripts/mariadb-install-db --defaults-file=/etc/my.cnf --user=www-data --basedir=/usr/local/mysql --datadir=/data/mysql --skip-name-resolve \
\
&& chown -R www-data:www-data /usr/local/mysql \
&& chown -R www-data:www-data /data/mysql \
&& /usr/local/mysql/support-files/mysql.server start \
&& chown -R www-data:www-data /usr/local/mysql \
&& chown -R www-data:www-data /data/mysql \
&& sleep 3s \
&& /usr/local/mysql/bin/mariadb -u root -e "SET PASSWORD = PASSWORD('root12345');" \
&& sleep 3s \
&& /usr/local/mysql/bin/mariadb -u root -e "CREATE USER 'root'@'%' IDENTIFIED BY 'root12345';" \
&& /usr/local/mysql/bin/mariadb -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;" \
&& /usr/local/mysql/bin/mariadb -u root -e "CREATE DATABASE test0db;" \
&& /usr/local/mysql/bin/mariadb -u root -e "CREATE DATABASE test1db;" \
&& /usr/local/mysql/bin/mariadb -u root -e "CREATE DATABASE test2db;" \
&& /usr/local/mysql/bin/mariadb -u root -e "FLUSH PRIVILEGES;" \
&& sleep 3s \
&& /usr/local/mysql/support-files/mysql.server stop \
\
&& echo '/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/mysql/bin' > /etc/container_environment/PATH \
&& echo 'export PATH="$PATH:/usr/local/mysql/bin"' > /etc/profile.d/mariadb.sh \
&& echo 'export PATH="$PATH:/usr/local/mysql/bin"' >> ~/.bashrc \
&& echo '' >> ~/.bashrc \
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
&& rm -rf /usr/local/mysql/mariadb-test/* \
&& du -h --max-depth=2 /usr/local/mysql \
&& du -h --max-depth=2 /data/mysql \
&& rm -rf /usr/local/src/*

EXPOSE 3306

CMD ["/sbin/my_init"]
