mkdir -p /var/www \
&& mkdir /var/www/mariadb_server \
&& mkdir /var/www/mariadb_server/datadir \
&& mkdir /var/www/mariadb_server/sysconfdir \
&& mkdir /var/www/mariadb_server/tmpdir \
&& mkdir /var/www/mariadb_server/tmprundatadir \

apt -y install \
liblzo2-dev \
libsnappy-dev \
libboost-dev \
\
&& mkdir /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cd /usr/local/src/mariadb-${MARIADB_VERSION}/build_tmp_dir \
&& cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/mariadb \
-DCMAKE_BUILD_TYPE=RelWithDebInfo \
-DDISABLE_SHARED=1 \
-DMYSQL_DATADIR=/var/www/mariadb_server/datadir \
-DSYSCONFDIR=/var/www/mariadb_server/sysconfdir \
-DTMPDIR=/var/www/mariadb_server/tmpdir \
-DINSTALL_RUNDATADIR=/var/www/mariadb_server/tmprundatadir \
-DWITH_SYSTEM_LIBS=0 \
-DDOWNLOAD_BOOST=0 \
-DWITH_BOOST=/usr/local/boost_1_88_0 \
-DWITH_DYNAMIC_PLUGINS=1 \
-DENABLE_DOWNLOADS=0 \
-DDEFAULT_CHARSET=utf8mb4 \
-DDEFAULT_COLLATION=utf8mb4_0900_ai_ci \
-DWITH_EXTRA_CHARSETS=all \
-DWITH_ARCHIVE_STORAGE_ENGINE=1 \
-DWITH_BLACKHOLE_STORAGE_ENGINE=1 \
-DWITH_COLUMNSTORE_STORAGE_ENGINE=1 \
-DWITH_EXAMPLE_STORAGE_ENGINE=1 \
-DWITH_FEDERATED_STORAGE_ENGINE=1 \
-DWITH_FEDERATEDX_STORAGE_ENGINE=1 \
-DWITH_S3_STORAGE_ENGINE=1 \
-DWITH_OQGRAPH_STORAGE_ENGINE=1 \
-DWITH_ROCKSDB_STORAGE_ENGINE=1 \
-DENABLED_LOCAL_INFILE=1 \
-DMYSQL_TCP_PORT=3307 \
-DMYSQL_UNIX_ADDR=/var/www/mariadb_server/mariadb.sock \
-DMYSQLX_TCP_PORT=33070 \
-DMYSQLX_UNIX_ADDR=/var/www/mariadb_server/mariadbx.sock \
-DWITH_LIBAIO=1 \
-DWITH_ROCKSDB_ZSTD=ON \
-DWITH_SYSTEMD=no \
-DDEB_ID="Ubuntu" \
-DDEB_CODENAME="noble" \
-DDEB_RELEASE="24.04" \
-DWITH_CURL=system \
-DWITH_SSL=system \
-DCURL_ZSTD=1 \
-DWITH_FIDO=system \
-DWITH_LIBFMT=system \
-DWITH_EDITLINE=bundled \
-DWITH_ICU=bundled \
-DWITH_LIBEVENT=bundled \
-DWITH_LZ4=bundled \
-DWITH_LZMA=bundled \
-DWITH_RE2=bundled \
-DWITH_ZLIB=bundled \
-DWITH_ZSTD=bundled \
-DWITH_RAPIDJSON=bundled \
-DWITH_PROTOBUF=bundled \
-DWITH_DEBUG=0 \
-DWITH_UNIT_TESTS=0

# 必须指定用户为 mariadb
/usr/local/mariadb/scripts/mariadb-install-db --defaults-file=/var/www/mariadb_server/sysconfdir/my.cnf \
--user=www-data \
--group=www-data \
--basedir=/usr/local/mariadb \
--datadir=/var/www/mariadb_server/datadir \
--skip-name-resolve

/usr/local/mariadb/bin/mariadbd-safe --defaults-file=/var/www/mariadb_server/sysconfdir/my.cnf \
--user=www-data \
--group=www-data \
--basedir=/usr/local/mariadb \
--datadir=/var/www/mariadb_server/datadir \
--skip-name-resolve

/usr/local/mariadb/bin/mariadb-secure-installation

# /usr/local/mariadb/scripts/mariadb-install-db --defaults-file=/var/www/mariadb_server/sysconfdir/my.cnf \
#--user=www-data \
#--group=www-data \
#--basedir=/usr/local/mariadb \
#--datadir=/var/www/mariadb_server/datadir \
#--skip-name-resolve
#Installing MariaDB/MySQL system tables in '/var/www/mariadb_server/datadir' ...
#OK
#
#To start mariadbd at boot time you have to copy
#support-files/mariadb.service to the right place for your system
#
#
#Two all-privilege accounts were created.
#One is root@localhost, it has no password, but you need to
#be system 'root' user to connect. Use, for example, sudo mariadb
#The second is www-data@localhost, it has no password either, but
#you need to be the system 'www-data' user to connect.
#After connecting you can set the password, if you would need to be
#able to connect as any of these users with a password and without sudo
#
#See the MariaDB Knowledgebase at https://mariadb.com/kb
#
#You can start the MariaDB daemon with:
#cd '/usr/local/mariadb' ; /usr/local/mariadb/bin/mariadbd-safe --datadir='/var/www/mariadb_server/datadir'
#
#You can test the MariaDB daemon with mariadb-test-run.pl
#cd '/usr/local/mariadb/mariadb-test' ; perl mariadb-test-run.pl
#
#Please report any problems at https://mariadb.org/jira
#
#The latest information about MariaDB is available at https://mariadb.org/.
#
#Consider joining MariaDB's strong and vibrant community:
#https://mariadb.org/get-involved/
