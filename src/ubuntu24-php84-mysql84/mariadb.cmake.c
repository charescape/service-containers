# cmake .. -LH

-- The following OPTIONAL packages have been found:

 * ZLIB
 * Python3
 * LibXml2
 * Boost (required version >= 1.40.0)
   Required for the OQGraph storage engine
 * Judy
   Required for the OQGraph storage engine
 * BZip2
 * LZ4 (required version >= 1.6)
 * LibLZMA
 * LZO
 * Snappy
 * BISON (required version >= 2.4)

-- The following RECOMMENDED packages have been found:

 * OpenSSL

-- The following REQUIRED packages have been found:

 * Curses
 * Threads
 * CURL

-- The following features have been disabled:

 * LIBWRAP, Support for tcp wrappers
 * SYSTEMD, Systemd scripts and notification support
 * COLUMNSTORE, Storage Engine
 * CONNECT_ODBC, Support for ODBC in the CONNECT storage engine
 * CONNECT_JDBC, Support for JDBC in the CONNECT storage engine
 * CONNECT_MONGODB, Support for MongoDB in the CONNECT storage engine
 * INNODB_EXTRA_DEBUG, Extra InnoDB debug checks
 * AWS_KEY_MANAGEMENT, AWS Encryption Key Management Plugin
 * EMBEDDED_SERVER, Embedded MariaDB Server Library

-- The following OPTIONAL packages have not been found:

 * Java (required version >= 1.6)
   Required for the CONNECT_JDBC feature
 * JNI
   Required for the CONNECT_JDBC feature
 * GSSAPI

-- Configuring done (41.4s)
-- Generating done (0.6s)
-- Build files have been written to: /usr/local/src/mariadb-12.1.2/build_tmp_dir
-- Cache values
// Allow to download and build AWS C++ SDK
AWS_SDK_EXTERNAL_PROJECT:BOOL=OFF

// Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel
CMAKE_BUILD_TYPE:STRING=RelWithDebInfo

// install prefix
CMAKE_INSTALL_PREFIX:PATH=/usr/local/mysql

// Default value for MYSQL_OPT_SSL_VERIFY_SERVER_CERT
CONC_DEFAULT_SSL_VERIFY_SERVER_CERT:BOOL=ON

// Use Boost::Context for the non-blocking API on platforms without native implementation
CONC_WITH_BOOST_CONTEXT:BOOL=OFF

// creates manpages
CONC_WITH_DOCS:BOOL=OFF

// Enables support of dynamic columns
CONC_WITH_DYNCOL:BOOL=ON

// build test suite
CONC_WITH_UNIT_TESTS:BOOL=ON

// Compile CONNECT storage engine with BSON support
CONNECT_WITH_BSON:BOOL=ON

// Compile CONNECT storage engine with JDBC support
CONNECT_WITH_JDBC:BOOL=ON

// Compile CONNECT storage engine with LIBXML2 support
CONNECT_WITH_LIBXML2:BOOL=ON

// Compile CONNECT storage engine with MONGO support
CONNECT_WITH_MONGO:BOOL=ON

// Compile CONNECT storage engine with ODBC support
CONNECT_WITH_ODBC:BOOL=ON

// Compile CONNECT storage engine with REST support
CONNECT_WITH_REST:BOOL=ON

// Compile CONNECT storage engine with VCT support
CONNECT_WITH_VCT:BOOL=ON

// Compile CONNECT storage engine with index file mapping support
CONNECT_WITH_XMAP:BOOL=ON

// Compile CONNECT storage engine with ZIP support
CONNECT_WITH_ZIP:BOOL=ON

// Don't build shared libraries, compile code as position-dependent
DISABLE_SHARED:BOOL=OFF

// Enable Json_writer_object / Json_writer_array checking to produce consistent JSON output
ENABLED_JSON_WRITER_CONSISTENCY_CHECKS:BOOL=OFF

// Enable profiling
ENABLED_PROFILING:BOOL=ON

// Enable gcov (debug, macOS and Linux builds only)
ENABLE_GCOV:BOOL=OFF

//
FEATURE_SUMMARY:BOOL=OFF

// Groonga's default DB key management algorithm
GRN_DEFAULT_DB_KEY:STRING=auto

// Groonga's default document root
GRN_DEFAULT_DOCUMENT_ROOT:PATH=/usr/local/mysql/share/groonga/html/admin

// Groonga's default document root base path
GRN_DEFAULT_DOCUMENT_ROOT_BASE:PATH=html/admin

// Groonga's default encoding
GRN_DEFAULT_ENCODING:STRING=utf8

// Groonga's default match escalation threshold
GRN_DEFAULT_MATCH_ESCALATION_THRESHOLD:STRING=0

// Groonga's default relative document root
GRN_DEFAULT_RELATIVE_DOCUMENT_ROOT:PATH=share/groonga/html/admin

// Build as a static library to embed into an application
GRN_EMBED:BOOL=ON

// timeout to acquire a lock.
GRN_LOCK_TIMEOUT:STRING=900000

// wait time in nanosecond to acquire a lock.
GRN_LOCK_WAIT_TIME_NANOSECOND:STRING=1000000

// log file path
GRN_LOG_PATH:FILEPATH=/usr/local/mysql/var/log/groonga/groonga.log

// mecab-config path
GRN_MECAB_CONFIG:FILEPATH=mecab-config

// Path to a program.
GRN_MECAB_CONFIG_ABSOLUTE_PATH:FILEPATH=GRN_MECAB_CONFIG_ABSOLUTE_PATH-NOTFOUND

// DANGER!!! Groonga's stack size. Normarlly, you should not change this variable.
GRN_STACK_SIZE:STRING=1024

// use bundled LZ4
GRN_WITH_BUNDLED_LZ4:BOOL=OFF

// use bundled MeCab
GRN_WITH_BUNDLED_MECAB:BOOL=OFF

// use bundled MessagePack
GRN_WITH_BUNDLED_MESSAGE_PACK:BOOL=OFF

// enable debug build.
GRN_WITH_DEBUG:BOOL=OFF

// use KyTea for morphological analysis
GRN_WITH_KYTEA:STRING=auto

// use libevent for suggestion
GRN_WITH_LIBEVENT:STRING=auto

// use libstemmer for stemming token filter
GRN_WITH_LIBSTEMMER:STRING=auto

// Support data compression by LZ4.
GRN_WITH_LZ4:STRING=auto

// use MeCab for morphological analysis
GRN_WITH_MECAB:STRING=auto

// use MessagePack for suggestion
GRN_WITH_MESSAGE_PACK:STRING=auto

// use mruby
GRN_WITH_MRUBY:BOOL=OFF

// use NFKC based UTF8 normalization.
GRN_WITH_NFKC:BOOL=ON

// use ZeroMQ for suggestion
GRN_WITH_ZEROMQ:STRING=auto

// Support data compression by zlib.
GRN_WITH_ZLIB:STRING=auto

// Build as a static library to embed into an application
GROONGA_NORMALIZER_MYSQL_EMBED:BOOL=ON

// Command for determining hostname
HOSTNAME:STRING=uname -n

// Enable innodb_enable_xap_unlock_unmodified_for_primary_debug system variable even for release build
INNODB_ENABLE_XAP_UNLOCK_UNMODIFIED_FOR_PRIMARY:BOOL=OFF

// Installation directory layout. Options are: STANDALONE (as in zip or tar.gz installer) RPM DEB SVR4
INSTALL_LAYOUT:STRING=STANDALONE

// Rundata installation directory
INSTALL_RUNDATADIR:FILEPATH=/tmp

// path to the flex executable
LEX_EXECUTABLE:FILEPATH=LEX_EXECUTABLE-NOTFOUND

// Path to a file.
LIBAIO_INCLUDE_DIRS:PATH=LIBAIO_INCLUDE_DIRS-NOTFOUND

// Path to a library.
LIBAIO_LIBRARIES:FILEPATH=LIBAIO_LIBRARIES-NOTFOUND

//
LZ4_LIBS:STRING=

// Max number of indexes
MAX_INDEXES:STRING=64

// Whether to build Mroonga for embedded server or not. You can't use Mroonga built for embedded server with non embedded server.
MRN_BUILD_FOR_EMBEDDED_SERVER:BOOL=OFF

// The default fulltext parser (Deprecated. Use MRN_DEFAULT_TOKENIZER instead.)
MRN_DEFAULT_PARSER:STRING=

// The default tokenizer for fulltext index
MRN_DEFAULT_TOKENIZER:STRING=

// Embed libgroonga
MRN_GROONGA_EMBED:BOOL=ON

// Embed groonga-normalizer-mysql Groonga plugin
MRN_GROONGA_NORMALIZER_MYSQL_EMBED:BOOL=ON

// default MySQL data directory
MYSQL_DATADIR:PATH=/usr/local/mysql/data

// Enable MariaDB maintainer-specific warnings. One of: NO (warnings are disabled) WARN (warnings are enabled) ERR (warnings are errors) AUTO (warnings are errors in Debug only)
MYSQL_MAINTAINER_MODE:STRING=AUTO

// Path to a library.
PAM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libpam.so

// How to build plugin ARCHIVE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_ARCHIVE:STRING=DYNAMIC

// How to build plugin AUDIT_NULL. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUDIT_NULL:STRING=DYNAMIC

// How to build plugin AUTH_0X0100. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_0X0100:STRING=DYNAMIC

// How to build plugin AUTH_ED25519. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_ED25519:STRING=DYNAMIC

// How to build plugin AUTH_MYSQL_SHA2. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_MYSQL_SHA2:STRING=DYNAMIC

// How to build plugin AUTH_PAM. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_PAM:STRING=DYNAMIC

// How to build plugin AUTH_PAM_V1. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_PAM_V1:STRING=DYNAMIC

// How to build plugin AUTH_PARSEC. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_PARSEC:STRING=DYNAMIC

// How to build plugin AUTH_SOCKET. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_SOCKET:STRING=STATIC

// How to build plugin AUTH_TEST_PLUGIN. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_AUTH_TEST_PLUGIN:STRING=DYNAMIC

// How to build plugin BLACKHOLE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_BLACKHOLE:STRING=DYNAMIC

// How to build plugin COLUMNSTORE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_COLUMNSTORE:STRING=NO

// How to build plugin CONNECT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_CONNECT:STRING=DYNAMIC

// How to build plugin DAEMON_EXAMPLE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_DAEMON_EXAMPLE:STRING=DYNAMIC

// How to build plugin DEBUG_KEY_MANAGEMENT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_DEBUG_KEY_MANAGEMENT:STRING=DYNAMIC

// How to build plugin DIALOG_EXAMPLES. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_DIALOG_EXAMPLES:STRING=DYNAMIC

// How to build plugin DISKS. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_DISKS:STRING=DYNAMIC

// How to build plugin EXAMPLE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_EXAMPLE:STRING=DYNAMIC

// How to build plugin EXAMPLE_KEY_MANAGEMENT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_EXAMPLE_KEY_MANAGEMENT:STRING=DYNAMIC

// How to build plugin FEDERATED. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FEDERATED:STRING=DYNAMIC

// How to build plugin FEDERATEDX. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FEDERATEDX:STRING=DYNAMIC

// How to build plugin FEEDBACK. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FEEDBACK:STRING=STATIC

// How to build plugin FILE_KEY_MANAGEMENT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FILE_KEY_MANAGEMENT:STRING=DYNAMIC

// How to build plugin FTEXAMPLE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FTEXAMPLE:STRING=DYNAMIC

// How to build plugin FUNC_TEST. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_FUNC_TEST:STRING=DYNAMIC

// How to build plugin HANDLERSOCKET. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_HANDLERSOCKET:STRING=DYNAMIC

// How to build plugin HASHICORP_KEY_MANAGEMENT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_HASHICORP_KEY_MANAGEMENT:STRING=DYNAMIC

// How to build plugin INNOBASE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_INNOBASE:STRING=STATIC

// How to build plugin LOCALES. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_LOCALES:STRING=DYNAMIC

// How to build plugin METADATA_LOCK_INFO. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_METADATA_LOCK_INFO:STRING=DYNAMIC

// How to build plugin MROONGA. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_MROONGA:STRING=DYNAMIC

// How to build plugin OQGRAPH. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_OQGRAPH:STRING=DYNAMIC

// How to build plugin PARTITION. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PARTITION:STRING=STATIC

// How to build plugin PASSWORD_REUSE_CHECK. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PASSWORD_REUSE_CHECK:STRING=DYNAMIC

// How to build plugin PERFSCHEMA. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PERFSCHEMA:STRING=STATIC

// How to build plugin PROVIDER_BZIP2. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PROVIDER_BZIP2:STRING=DYNAMIC

// How to build plugin PROVIDER_LZ4. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PROVIDER_LZ4:STRING=DYNAMIC

// How to build plugin PROVIDER_LZMA. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PROVIDER_LZMA:STRING=DYNAMIC

// How to build plugin PROVIDER_LZO. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PROVIDER_LZO:STRING=DYNAMIC

// How to build plugin PROVIDER_SNAPPY. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_PROVIDER_SNAPPY:STRING=DYNAMIC

// How to build plugin QA_AUTH_CLIENT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_QA_AUTH_CLIENT:STRING=DYNAMIC

// How to build plugin QA_AUTH_INTERFACE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_QA_AUTH_INTERFACE:STRING=DYNAMIC

// How to build plugin QA_AUTH_SERVER. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_QA_AUTH_SERVER:STRING=DYNAMIC

// How to build plugin QUERY_CACHE_INFO. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_QUERY_CACHE_INFO:STRING=DYNAMIC

// How to build plugin QUERY_RESPONSE_TIME. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_QUERY_RESPONSE_TIME:STRING=DYNAMIC

// How to build plugin ROCKSDB. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_ROCKSDB:STRING=DYNAMIC

// How to build plugin S3. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_S3:STRING=DYNAMIC

// How to build plugin SEQUENCE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SEQUENCE:STRING=STATIC

// How to build plugin SERVER_AUDIT. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SERVER_AUDIT:STRING=DYNAMIC

// How to build plugin SIMPLE_PASSWORD_CHECK. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SIMPLE_PASSWORD_CHECK:STRING=DYNAMIC

// How to build plugin SPHINX. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SPHINX:STRING=DYNAMIC

// How to build plugin SPIDER. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SPIDER:STRING=DYNAMIC

// How to build plugin SQL_ERRLOG. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_SQL_ERRLOG:STRING=DYNAMIC

// How to build plugin TEST_SQL_DISCOVERY. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TEST_SQL_DISCOVERY:STRING=DYNAMIC

// How to build plugin TEST_SQL_SERVICE. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TEST_SQL_SERVICE:STRING=DYNAMIC

// How to build plugin TEST_VERSIONING. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TEST_VERSIONING:STRING=DYNAMIC

// How to build plugin THREAD_POOL_INFO. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_THREAD_POOL_INFO:STRING=STATIC

// How to build plugin TYPE_MYSQL_JSON. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TYPE_MYSQL_JSON:STRING=DYNAMIC

// How to build plugin TYPE_MYSQL_TIMESTAMP. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TYPE_MYSQL_TIMESTAMP:STRING=DYNAMIC

// How to build plugin TYPE_TEST. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_TYPE_TEST:STRING=DYNAMIC

// How to build plugin USER_VARIABLES. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_USER_VARIABLES:STRING=STATIC

// How to build plugin WSREP_INFO. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_WSREP_INFO:STRING=DYNAMIC

// How to build plugin WSREP_PROVIDER. Options are: NO STATIC DYNAMIC YES AUTO.
PLUGIN_WSREP_PROVIDER:STRING=STATIC

// Use security-enhancing compiler features (stack protector, relro, etc)
SECURITY_HARDENED:BOOL=ON

// PATH to MySQL TMP dir. Defaults to the P_tmpdir macro in <stdio.h>
TMPDIR:PATH=

// Update submodules automatically
UPDATE_SUBMODULES:BOOL=ON

// Use Aria for temporary tables
USE_ARIA_FOR_TMP_TABLES:BOOL=ON

// disable packed sort keys
WITHOUT_PACKED_SORT_KEYS:BOOL=OFF

// Build only the client library and clients
WITHOUT_SERVER:BOOL=OFF

// Enable address sanitizer
WITH_ASAN:BOOL=OFF

// Build with lz4. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'
WITH_COLUMNSTORE_LZ4:STRING=AUTO

// Enable DBUG_ENTER()/DBUG_RETURN()/DBUG_PRINT()
WITH_DBUG_TRACE:BOOL=ON

// Compile MariaDB with embedded server
WITH_EMBEDDED_SERVER:BOOL=OFF

// Options are: none complex all
WITH_EXTRA_CHARSETS:STRING=all

// build with fallocate
WITH_FALLOCATE:BOOL=ON

// Enable profiling with gprof
WITH_GPROF:BOOL=OFF

// Include innodb_adaptive_hash_index
WITH_INNODB_AHI:BOOL=ON

// Enable extra InnoDB debug checks
WITH_INNODB_EXTRA_DEBUG:BOOL=OFF

// Support memory-mapped InnoDB redo log
WITH_INNODB_PMEM:BOOL=ON

// Cache index root block descriptors
WITH_INNODB_ROOT_GUESS:BOOL=ON

// Require that libaio is used
WITH_LIBAIO:BOOL=OFF

// Which libfmt to use (possible values are 'bundled', 'system', or 'auto')
WITH_LIBFMT:STRING=auto

// Compile with tcp wrappers support
WITH_LIBWRAP:BOOL=OFF

// Include mariabackup
WITH_MARIABACKUP:BOOL=ON

// Enable memory sanitizer
WITH_MSAN:BOOL=OFF

// Build with non-uniform memory access, allowing --innodb-numa-interleave. Options are ON|OFF|AUTO. ON = enabled (requires NUMA library), OFF = disabled, AUTO = enabled if NUMA library found.
WITH_NUMA:STRING=AUTO

// Which pcre to use (possible values are 'bundled', 'system', or 'auto')
WITH_PCRE:STRING=auto

// Enable protection of statement's memory root after first SP/PS execution. Turned into account only for debug build
WITH_PROTECT_STATEMENT_MEMROOT:BOOL=ON

// Use bundled readline
WITH_READLINE:BOOL=OFF

// Build RocksDB  with BZip2 compression. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'
WITH_ROCKSDB_BZip2:STRING=AUTO

// build RocksDB with JeMalloc
WITH_ROCKSDB_JEMALLOC:BOOL=OFF

// Build RocksDB  with LZ4 compression. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'
WITH_ROCKSDB_LZ4:STRING=AUTO

// Build RocksDB  with Snappy compression. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'
WITH_ROCKSDB_Snappy:STRING=AUTO

// Build RocksDB  with ZSTD compression. Possible values are 'ON', 'OFF', 'AUTO' and default is 'AUTO'
WITH_ROCKSDB_ZSTD:STRING=AUTO

// Use safemalloc memory debugger. Will result in slower execution. Options are: ON OFF AUTO.
WITH_SAFEMALLOC:STRING=AUTO

// bundled (use wolfssl), yes (prefer os library if present, otherwise use bundled), system (use os library)
WITH_SSL:STRING=yes

// Enable systemd scripts and notification support. Allowed values yes/no/auto.
WITH_SYSTEMD:STRING=auto

// Which Thrift to use (possible values are 'bundled', 'system', or 'auto')
WITH_THRIFT:STRING=bundled

// Enable thread sanitizer
WITH_TSAN:BOOL=OFF

// Enable undefined behavior sanitizer
WITH_UBSAN:BOOL=OFF

// Compile MySQL with unit tests
WITH_UNIT_TESTS:BOOL=ON

// Require that io_uring be used
WITH_URING:BOOL=OFF

// Valgrind instrumentation
WITH_VALGRIND:BOOL=OFF

// Build all components of WSREP (unit tests, sample programs)
WITH_WSREP_ALL:BOOL=OFF

// Which zlib to use (possible values are 'bundled' or 'system')
WITH_ZLIB:STRING=system

// Fail compilation on any warnings
WSREP_LIB_MAINTAINER_MODE:BOOL=OFF

// Compile with strict build flags
WSREP_LIB_STRICT_BUILD_FLAGS:BOOL=OFF

// Enable address sanitizer
WSREP_LIB_WITH_ASAN:BOOL=OFF

// Compile with coverage instrumentation
WSREP_LIB_WITH_COVERAGE:BOOL=OFF

// Compile sample dbsim program
WSREP_LIB_WITH_DBSIM:BOOL=OFF

// Generate documentation
WSREP_LIB_WITH_DOCUMENTATION:BOOL=OFF

// Enable thread sanitizer
WSREP_LIB_WITH_TSAN:BOOL=OFF

// Compile unit tests
WSREP_LIB_WITH_UNIT_TESTS:BOOL=OFF

// The directory containing a CMake configuration file for aws-cpp-sdk-kms.
aws-cpp-sdk-kms_DIR:PATH=aws-cpp-sdk-kms_DIR-NOTFOUND

// The directory containing a CMake configuration file for libmongoc-1.0.
libmongoc-1.0_DIR:PATH=libmongoc-1.0_DIR-NOTFOUND

