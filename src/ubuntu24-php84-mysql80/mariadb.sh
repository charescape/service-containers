apt -y install \
liblzo2-dev \
libsnappy-dev \
\
&& mkdir /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cd /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/mariadb \
-DCMAKE_BUILD_TYPE=Release \
-DWITH_SYSTEM_LIBS=1 \
-DMYSQL_DATADIR=/var/www/mariadb_data \
-DSYSCONFDIR=/var/www/mariadb_conf \
-DTMPDIR=/var/www/mariadb_temp \
-DDEFAULT_CHARSET=utf8mb4 \
-DDEFAULT_COLLATION=utf8mb4_unicode_ci \
-DDOWNLOAD_BOOST=1 \
-DWITH_BOOST=/usr/local/boostcxx_build_1_87_0 \
-DENABLED_LOCAL_INFILE=1 \
-DMYSQL_TCP_PORT=3307 \
-DMYSQL_UNIX_ADDR=/var/www/mariadb.sock \
-DWITH_JEMALLOC=1 \
-DWITH_RAPIDJSON=bundled \
-DWITH_PROTOBUF=bundled \
-DWITH_FIDO=bundled \
-DWITH_UNIT_TESTS=0
