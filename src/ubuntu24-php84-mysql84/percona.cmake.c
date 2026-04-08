-- Running cmake version 3.22.1
-- CMAKE_MODULE_PATH is /usr/local/src/percona-server-8.4.3-3/cmake
-- MySQL 8.4.3-3
-- Source directory /usr/local/src/percona-server-8.4.3-3
-- Binary directory /usr/local/src/percona-server-8.4.3-3/build_tmp_dir
-- CMAKE_GENERATOR: Unix Makefiles
-- SIZEOF_VOIDP 8
-- Found verified platform LINUX for libbacktrace
-- Packaging as: percona-server-8.4.3-3-Linux-x86_64
-- BOOST_PATCHES_DIR /usr/local/src/percona-server-8.4.3-3/include/boost_1_84_0/patches
-- BOOST_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/boost/boost_1_84_0
-- NUMA library missing or required version not available
-- Using libbacktrace on LINUX
-- ZLIB_VERSION (bundled) is 1.3.1
-- ZLIB_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/zlib/zlib-1.3.1
-- ZSTD_VERSION (bundled) is 1.5.5
-- ZSTD_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/zstd/zstd-1.5.5/lib
-- ZSTD_LEGACY_SUPPORT not defined!
-- OPENSSL_VERSION (system) is 3.0.2
-- OPENSSL_INCLUDE_DIR = /usr/include
-- OPENSSL_LIBRARIES = /usr/lib/x86_64-linux-gnu/libssl.so /usr/lib/x86_64-linux-gnu/libcrypto.so
-- SYSTEM_KRB5_FOUND  1
-- SYSTEM_KRB5_LIBRARIES  krb5;k5crypto;com_err
-- SYSTEM_KRB5_LIBRARY_DIRS  /usr/lib/x86_64-linux-gnu/mit-krb5
-- SYSTEM_KRB5_LDFLAGS  -L/usr/lib/x86_64-linux-gnu/mit-krb5;-lkrb5;-lk5crypto;-lcom_err
-- SYSTEM_KRB5_LDFLAGS_OTHER  
-- SYSTEM_KRB5_INCLUDE_DIRS  /usr/include/mit-krb5
-- SYSTEM_KRB5_CFLAGS  -isystem;/usr/include/mit-krb5
-- SYSTEM_KRB5_CFLAGS_OTHER  
-- GSSAPI_LIBRARIES /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so
-- GSSAPI_INCLUDE_DIR  /usr/include
-- HAVE_KRB5_KRB5_H  1
-- KERBEROS_LIBRARIES  -L/usr/lib/x86_64-linux-gnu/mit-krb5;-lkrb5;-lk5crypto;-lcom_err
-- SASL_LIBRARY /usr/lib/x86_64-linux-gnu/libsasl2.so
-- SASL_VERSION (system) is 2.1.27
-- LBER_LIBRARY /usr/lib/x86_64-linux-gnu/liblber.so
-- LDAP_LIBRARY /usr/lib/x86_64-linux-gnu/libldap_r.so
-- KERBEROS_FOUND  1
-- GSSAPI_FOUND  1
-- WITH_KERBEROS  system
-- AWK_EXECUTABLE is /usr/bin/gawk
-- LZ4_VERSION (bundled) is 1.10.0
-- LZ4_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/lz4/lz4-1.10.0/lib
-- ICU_VERSION (bundled) is 73
-- ICU_INCLUDE_DIRS /usr/local/src/percona-server-8.4.3-3/extra/icu/icu-release-73-1/source/common;/usr/local/src/percona-server-8.4.3-3/extra/icu/icu-release-73-1/source/stubdata;/usr/local/src/percona-server-8.4.3-3/extra/icu/icu-release-73-1/source/i18n
-- ICU_LIBRARIES icui18n;icuuc;icustubdata
-- PROTOBUF_VERSION (bundled) is 4.24.4
-- PROTOBUF_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/protobuf/protobuf-24.4/src
-- PROTOBUF_PROTOC_EXECUTABLE protoc
-- CURL_INCLUDE_DIR = /usr/include/x86_64-linux-gnu
-- CURL_VERSION (system) is 7.81
-- RAPIDJSON_INCLUDE_DIR /usr/local/src/percona-server-8.4.3-3/extra/rapidjson/include
-- RAPIDJSON_MAJOR_VERSION is 1
-- RAPIDJSON_MINOR_VERSION is 1
-- Build with DWITH_COREDUMPER = ON
-- FIDO_VERSION (bundled) is 1.15.0
-- CMAKE_MODULE_LINKER_FLAGS_DEBUG  -Wl,-rpath,'$ORIGIN/../../private'
-- CMAKE_SHARED_LINKER_FLAGS_DEBUG  -Wl,-rpath,'$ORIGIN/../../private'
-- mysys_objlib depends on ext::zlib
-- mysys_objlib depends on ext::zstd
-- clientlib_objlib depends on ext::zlib
-- Found Unix DNS SRV APIs
-- Building authentication_ldap_sasl_client with Kerberos
-- Building KERBEROS client authentication plug-in for linux.
-- Using Kerberos libraries: /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so;-L/usr/lib/x86_64-linux-gnu/mit-krb5;-lkrb5;-lk5crypto;-lcom_err
-- Library perconaserverclient depends on OSLIBS m
-- MERGE_CONVENIENCE_LIBRARIES TARGET perconaserverclient
-- MERGE_CONVENIENCE_LIBRARIES LIBS clientlib;mytime;strings;vio;mysys;zlib;zstd;backtrace
-- Building ndbcluster plugin
-- Excluding Cluster Java components
-- ndbgeneral_objlib depends on ext::zlib
-- ndbapi_objlib depends on ext::zlib
-- LIBS_TO_MERGE mysys;mytime;ndbapi;ndbgeneral;ndblogger;ndbmgmapi;ndbmgmcommon;ndbportlib;ndbsignaldata;ndbtrace;ndbtransport;strings;zlib;backtrace
-- Library ndbclient_static depends on OSLIBS m
-- MERGE_CONVENIENCE_LIBRARIES TARGET ndbclient_static
-- MERGE_CONVENIENCE_LIBRARIES LIBS mysys;mytime;ndbapi;ndbgeneral;ndblogger;ndbmgmapi;ndbmgmcommon;ndbportlib;ndbsignaldata;ndbtrace;ndbtransport;strings;zlib;backtrace
-- Building with MyRocks storage engine = 1
-- MyRocks: Using local RocksDB
-- MyRocks x86_64 build architecture: -march=native
-- malloc_usable_size() function detected but not used as ROCKSDB_USE_MALLOC_USABLE_SIZE is not defined
-- MyRocks compile definitions: HAVE_ALIGNED_NEW;HAVE_AVX2;HAVE_PCLMUL;HAVE_SCHED_GETCPU=1;HAVE_SSE42;HAVE_TLSv13;HAVE_UINT128_EXTENSION;LZ4;LZ4_DISABLE_DEPRECATE_WARNINGS;OS_LINUX;ROCKSDB_AUXV_GETAUXVAL_PRESENT;ROCKSDB_BACKTRACE;ROCKSDB_FALLOCATE_PRESENT;ROCKSDB_LIB_IO_POSIX;ROCKSDB_PLATFORM_POSIX;ROCKSDB_PTHREAD_ADAPTIVE_MUTEX;ROCKSDB_RANGESYNC_PRESENT;ROCKSDB_SCHED_GETCPU_PRESENT;ROCKSDB_SUPPORT_THREAD_LOCAL;ZLIB;ZSTD;_FILE_OFFSET_BITS=64;_GNU_SOURCE;_USE_MATH_DEFINES;__STDC_FORMAT_MACROS;__STDC_LIMIT_MACROS
-- RPC_INCLUDE_DIRS /usr/include/tirpc
-- GROUP_REPLICATION_WITH_ROCKSDB is turned off
-- Changing RPATH when installing /usr/local/src/percona-server-8.4.3-3/debug/plugin_output_directory/group_replication.so
-- MYSQLX - Text log of protobuf messages enabled
-- Building Binlog Utils UDF component
-- Building Encryption UDF component
-- Building Keyring Vault Component
-- Building Masking Functions component
-- Not building Percona Telemetry component
-- Building UUID_VX UDF component
-- Building Keyring Vault Component unit tests
-- json_client_library_objlib depends on ext::zlib
-- Library json_binlog_static depends on OSLIBS m
-- MERGE_CONVENIENCE_LIBRARIES TARGET json_binlog_static
-- MERGE_CONVENIENCE_LIBRARIES LIBS json_client_library;mysys;mytime;strings;decimal
-- BISON outputs /usr/local/src/percona-server-8.4.3-3/build_tmp_dir/sql/sql_yacc.cc;/usr/local/src/percona-server-8.4.3-3/build_tmp_dir/sql/sql_yacc.h
-- BISON outputs /usr/local/src/percona-server-8.4.3-3/build_tmp_dir/sql/sql_hints.yy.cc;/usr/local/src/percona-server-8.4.3-3/build_tmp_dir/sql/sql_hints.yy.h
-- CONFIG_CLIENT_LIBS -lssl  -lcrypto -lresolv -lm
-- CONFIG_LIBS_PRIVATE  -lresolv -lm
-- INSTALL perconaserverclient.pc lib/pkgconfig
-- MySQL 8.4.3-3
-- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE) 
-- CMAKE_BUILD_TYPE: RelWithDebInfo
-- COMPILE_DEFINITIONS: _GNU_SOURCE;_FILE_OFFSET_BITS=64;__STDC_LIMIT_MACROS;__STDC_FORMAT_MACROS;_USE_MATH_DEFINES;LZ4_DISABLE_DEPRECATE_WARNINGS;HAVE_TLSv13
-- CMAKE_C_FLAGS: -fno-omit-frame-pointer -ftls-model=initial-exec -g -O2 -ffile-prefix-map=/usr/local/src/percona-server-8.4.3-3/build_tmp_dir=. -flto=auto -ffat-lto-objects -flto=auto -ffat-lto-objects -fstack-protector-strong -Wformat -Werror=format-security   -Wdate-time -D_FORTIFY_SOURCE=2 -Wall -Wextra -Wformat-security -Wvla -Wundef -Wmissing-format-attribute -Wwrite-strings -Wjump-misses-init -Wstringop-truncation -Wmissing-include-dirs
-- CMAKE_CXX_FLAGS: -std=c++20 -fno-omit-frame-pointer -ftls-model=initial-exec -g -O2 -ffile-prefix-map=/usr/local/src/percona-server-8.4.3-3/build_tmp_dir=. -flto=auto -ffat-lto-objects -flto=auto -ffat-lto-objects -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2 -Wall -Wextra -Wformat-security -Wvla -Wundef -Wmissing-format-attribute -Woverloaded-virtual -Wcast-qual -Wimplicit-fallthrough=5 -Wstringop-truncation -Wsuggest-override -Wmissing-include-dirs -Wextra-semi -Wlogical-op
-- CMAKE_CXX_FLAGS_DEBUG: -DSAFE_MUTEX -DENABLED_DEBUG_SYNC -g
-- CMAKE_CXX_FLAGS_RELWITHDEBINFO: -DNDEBUG -D_FORTIFY_SOURCE=2 -ffunction-sections -fdata-sections -O2 -g -DNDEBUG -g1
-- CMAKE_CXX_FLAGS_RELEASE: -DNDEBUG -D_FORTIFY_SOURCE=2 -ffunction-sections -fdata-sections -O3 -DNDEBUG
-- CMAKE_CXX_FLAGS_MINSIZEREL: -DNDEBUG -D_FORTIFY_SOURCE=2 -ffunction-sections -fdata-sections -Os -DNDEBUG
-- CMAKE_C_LINK_FLAGS: 
-- CMAKE_CXX_LINK_FLAGS: 
-- CMAKE_EXE_LINKER_FLAGS -Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro
-- CMAKE_MODULE_LINKER_FLAGS -Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro
-- CMAKE_SHARED_LINKER_FLAGS -Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro
-- Configuring done
-- Generating done
-- Build files have been written to: /usr/local/src/percona-server-8.4.3-3/build_tmp_dir
-- Cache values
// If ON, Abseil will build all of Abseil's own tests.
ABSL_BUILD_TESTING:BOOL=OFF

// If ON, Abseil will build libraries that you can use to write tests against Abseil code. This option requires that Abseil is configured to use GoogleTest.
ABSL_BUILD_TEST_HELPERS:BOOL=OFF

// Enable install rule
ABSL_ENABLE_INSTALL:BOOL=OFF

// If set, download GoogleTest from this URL
ABSL_GOOGLETEST_DOWNLOAD_URL:STRING=

// Path to a library.
ABSL_LIBRT:FILEPATH=/usr/lib/x86_64-linux-gnu/librt.a

// If ABSL_USE_GOOGLETEST_HEAD is OFF and ABSL_GOOGLETEST_URL is not set, specifies the directory of a local GoogleTest checkout.
ABSL_LOCAL_GOOGLETEST_DIR:PATH=/usr/src/googletest

// If ON, Abseil will assume that the targets for GoogleTest are already provided by the including project. This makes sense when Abseil is used with add_subdirectory.
ABSL_USE_EXTERNAL_GOOGLETEST:BOOL=OFF

// If ON, abseil will download HEAD from GoogleTest at config time.
ABSL_USE_GOOGLETEST_HEAD:BOOL=OFF

// Silence warnings in Abseil headers by marking them as SYSTEM includes
ABSL_USE_SYSTEM_INCLUDES:BOOL=OFF

// Generate a .gdb_index section in the binaries.
ADD_GDB_INDEX:BOOL=OFF

// Build shared libraries by default
BUILD_SHARED_LIBS:BOOL=OFF

// Build the testing tree.
BUILD_TESTING:BOOL=OFF

// Bundle mecab and ipadic with plugin
BUNDLE_MECAB:BOOL=ON

// Check printf format for English error messages
CHECK_ERRMSG_FORMAT:BOOL=OFF

// Choose the type of build, options are: None(CMAKE_CXX_FLAGS or
 CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel
CMAKE_BUILD_TYPE:STRING=RelWithDebInfo

// install prefix
CMAKE_INSTALL_PREFIX:PATH=/usr/local/mysql

// Target 'install' does not depend on 'all'
CMAKE_SKIP_INSTALL_ALL_DEPENDENCY:BOOL=OFF

// Compress debug sections of mysqld and test executables
COMPRESS_DEBUG_SECTIONS:BOOL=OFF

// Path to a program.
CTAGS_EXECUTABLE:FILEPATH=CTAGS_EXECUTABLE-NOTFOUND

// Path to a program.
CTEST_EXECUTABLE:FILEPATH=/usr/bin/ctest

// Curl library
CURL_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libcurl.so

// 
DEB_CHANGELOG_TIMESTAMP:STRING=Sun, 09 Mar 2025 03:12:22 +0800

// 
DEB_CODENAME:STRING=jammy

// 
DEB_ID:STRING=Ubuntu

// 
DEB_RELEASE:STRING=22.04

// Enable profiling
ENABLED_PROFILING:BOOL=ON

// Expose ussually hidden system variables to allow experiments
ENABLE_EXPERIMENT_SYSVARS:BOOL=OFF

// Enable gcov (debug, Linux builds only)
ENABLE_GCOV:BOOL=OFF

// Enable gprof (optimized, Linux builds only)
ENABLE_GPROF:BOOL=OFF

// Path to a library.
EXECINFO_LIBRARY:FILEPATH=EXECINFO_LIBRARY-NOTFOUND

// Extra text in package name
EXTRA_NAME_SUFFIX:STRING=

// Colorize compiler output
FORCE_COLORED_OUTPUT:BOOL=OFF

// Allow in-source build
FORCE_INSOURCE_BUILD:BOOL=OFF

// Add -fprofile-generate
FPROFILE_GENERATE:BOOL=OFF

// Add -fprofile-use
FPROFILE_USE:BOOL=OFF

// Find header files with GLOB_RECURSE
GLOB_RECURSE_SQL_HEADERS:BOOL=OFF

// Path to a file.
GSSAPI_INCLUDE_DIR:PATH=/usr/include

// Handle fatal signals with internal signal handler
HANDLE_FATAL_SIGNALS:BOOL=ON

// Name of Harness
HARNESS_NAME:STRING=mysqlrouter

// Installation directory layout. Options are: TARGZ (as in tar.gz installer), STANDALONE, RPM, DEB, SVR4
INSTALL_LAYOUT:STRING=STANDALONE

// Where to install perconaserverclient.pc, defaults to lib/pkgconfig
INSTALL_PKGCONFIGDIR:PATH=

// Install static libraries
INSTALL_STATIC_LIBRARIES:BOOL=ON

// Path to a file.
KERBEROS_INCLUDE_DIR:PATH=/usr/include/mit-krb5

// Path to a library.
LBER_SYSTEM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/liblber.so

// Path to a library.
LDAP_SYSTEM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libldap_r.so

// Randomize the order of all symbols in the binary
LINK_RANDOMIZE:BOOL=OFF

// Seed to use for link randomization
LINK_RANDOMIZE_SEED:STRING=mysql

// Path to a library.
MEMKIND_LIBRARY:FILEPATH=MEMKIND_LIBRARY-NOTFOUND

// Reduce debug information for gcc RelWithDebInfo builds
MINIMAL_RELWITHDEBINFO:BOOL=ON

// Enable the extra MSVC CppCheck checks
MSVC_CPPCHECK:BOOL=OFF

// Mutex type: event, sys or futex
MUTEXTYPE:STRING=event

// MYSQLX - enable additional tests
MYSQLX_ADDITIONAL_TESTS_ENABLE:BOOL=OFF

// MYSQLX_GENERATE_DIR
MYSQLX_GENERATE_DIR:STRING=/usr/local/src/percona-server-8.4.3-3/build_tmp_dir/plugin/x/generated

// default MySQL data directory
MYSQL_DATADIR:PATH=/usr/local/mysql/data

// default MySQL ICU data directory
MYSQL_ICU_DATADIR:PATH=/usr/local/mysql/lib/private

// default MySQL keyring directory
MYSQL_KEYRINGDIR:PATH=/usr/local/mysql/keyring

// MySQL maintainer-specific development environment
MYSQL_MAINTAINER_MODE:BOOL=OFF

// Name of default configuration file
MYSQL_ROUTER_INI:STRING=mysqlrouter.conf

// MySQL Router project name
MYSQL_ROUTER_NAME:STRING=MySQL Router

// Path to a program.
MY_DPKG_BUILDFLAGS:FILEPATH=/usr/bin/dpkg-buildflags

// Path to a program.
MY_KRB5_CONFIG:FILEPATH=MY_KRB5_CONFIG-NOTFOUND

// pkg-config executable
MY_PKG_CONFIG_EXECUTABLE:FILEPATH=/usr/bin/pkg-config

// Path to a program.
MY_RPM:FILEPATH=MY_RPM-NOTFOUND

// Path to a program.
MY_UNAME:FILEPATH=/usr/bin/uname

// Add -Og -fno-inline to CMAKE_<lang>_FLAGS_DEBUG
OPTIMIZE_DEBUG_BUILDS:BOOL=OFF

// Add -O1 -fno-inline to sanitizer builds
OPTIMIZE_SANITIZER_BUILDS:BOOL=ON

// Path to a program.
PATCHELF_EXECUTABLE:FILEPATH=PATCHELF_EXECUTABLE-NOTFOUND

// Path to a program.
PERL_EXECUTABLE:FILEPATH=/usr/bin/perl

// Path to a program.
READELF_EXECUTABLE:FILEPATH=/usr/bin/readelf

// Take extra pains to make build result independent of build location and time
REPRODUCIBLE_BUILD:BOOL=OFF

// Path to a library.
RESOLV_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libresolv.so

// Location of data files such as keyring file
ROUTER_DATADIR:STRING=/usr/local/mysql/var/lib/mysqlrouter

// Installation directory layout. Options are: STANDALONE RPM DEB SVR4 TARGZ
ROUTER_INSTALL_LAYOUT:STRING=STANDALONE

// Location of log files; empty is console (logging_folder)
ROUTER_LOGDIR:STRING=/usr/local/mysql/.

// Location MySQL Router plugins (plugin_folder)
ROUTER_PLUGINDIR:STRING=/usr/local/mysql/lib/mysqlrouter

// Location runtime files such as PID file (runtime_folder)
ROUTER_RUNTIMEDIR:STRING=/usr/local/mysql/run

// Path to a file.
SASL_INCLUDE_DIR:PATH=/usr/include

// Path to a library.
SASL_SYSTEM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libsasl2.so

// Path to a library.
SASL_SYSTEM_SCRAM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/sasl2/libscram.so

// Show mysqld build id as final target
SHOW_BUILD_ID:BOOL=OFF

// Path to a library.
SYSTEM_GSSAPI_LIBRARIES:FILEPATH=/usr/lib/x86_64-linux-gnu/libgssapi_krb5.so

// PATH to MySQL TMP dir. Defaults to the P_tmpdir macro in <stdio.h>
TMPDIR:PATH=P_tmpdir

// Path to a library.
UDEV_SYSTEM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libudev.so

// Path to a library.
URING_LIBRARY:FILEPATH=URING_LIBRARY-NOTFOUND

// Use bison results from source distribution tarball
USE_BISON_RESULTS_FROM_MAKE_DIST:BOOL=OFF

// Link ARCHIVE statically to the server
WITH_ARCHIVE_STORAGE_ENGINE:BOOL=ON

// Enable address sanitizer
WITH_ASAN:BOOL=OFF

// Build client-side authentication plugins, even if server-side are disabled
WITH_AUTHENTICATION_CLIENT_PLUGINS:BOOL=ON

// Report error if the Kerberos authentication plugin cannot be built.
WITH_AUTHENTICATION_KERBEROS:BOOL=ON

// Report error if the LDAP authentication plugin cannot be built.
WITH_AUTHENTICATION_LDAP:BOOL=ON

// Report error if the WEBAUTHN authentication plugin cannot be built.
WITH_AUTHENTICATION_WEBAUTHN:BOOL=OFF

// Build Binlog Utils component
WITH_BINLOG_UTILS_UDF:BOOL=ON

// Link BLACKHOLE statically to the server
WITH_BLACKHOLE_STORAGE_ENGINE:BOOL=ON

// Add --build-id=sha1 to all executables.
WITH_BUILD_ID:BOOL=ON

// Support for client-side protocol tracing plugins
WITH_CLIENT_PROTOCOL_TRACING:BOOL=ON

// Build with Percona Audit Log Filter component
WITH_COMPONENT_AUDIT_LOG_FILTER:BOOL=ON

// Building Keyring Vault Component
WITH_COMPONENT_KEYRING_VAULT:BOOL=ON

// Build Masking Functions component
WITH_COMPONENT_MASKING_FUNCTIONS:BOOL=ON

// Enable support for coredumper library
WITH_COREDUMPER:BOOL=ON

// Compile change streams library with protobuf based functionality
WITH_CS_PROTOBUF:BOOL=OFF

// | system (use the OS curl library), | bundled (code in extra/curl), | </path/to/custom/installation>, | 0 | no | off | none (skip curl)| 
WITH_CURL:STRING=system

// Use dbug/safemutex
WITH_DEBUG:BOOL=OFF

// Use flags from cmake/build_configurations/compiler_options.cmake
WITH_DEFAULT_COMPILER_OPTIONS:BOOL=ON

// By default use bundled editline
WITH_EDITLINE:STRING=bundled

// Build Encryption UDF plugin
WITH_ENCRYPTION_UDF:BOOL=ON

// Enable error injection in NDB
WITH_ERROR_INSERT:BOOL=OFF

// Use libbacktrace to print stacktraces
WITH_EXT_BACKTRACE:BOOL=ON

// Build deliberately failing GUint tests
WITH_FAILING_GUNIT_TESTS:BOOL=OFF

// Link FEDERATED statically to the server
WITH_FEDERATED_STORAGE_ENGINE:BOOL=ON

// By default use bundled libfido2.
WITH_FIDO:STRING=bundled

// Allow use of the hypergraph join optimizer
WITH_HYPERGRAPH_OPTIMIZER:BOOL=OFF

// By default use bundled icu library
WITH_ICU:STRING=bundled

// Enable extra InnoDB debug checks
WITH_INNODB_EXTRA_DEBUG:BOOL=OFF

// Use jemalloc rather than builtin malloc/free etc.
WITH_JEMALLOC:BOOL=OFF

// Build and install standalone json_binlog library
WITH_JSON_BINLOG_LIBRARY:BOOL=OFF

// | system (use the OS kerberos library), | </path/to/custom/installation>, | none (skip kerberos)>
WITH_KERBEROS:STRING=system

// | system (use the OS ldap library), | </path/to/custom/installation>
WITH_LDAP:STRING=system

// Compile with tcp wrappers support
WITH_LIBWRAP:BOOL=OFF

// Build the lock order mutex instrumentation code.
WITH_LOCK_ORDER:BOOL=OFF

// Enable leak sanitizer
WITH_LSAN:BOOL=OFF

// Enable the link-time optimizer. Currently works for gcc7/gcc8/gcc9/macos only.
WITH_LTO:BOOL=OFF

// By default use bundled lz4 library
WITH_LZ4:STRING=bundled

// <empty> (disabled) | system (use os library) | </path/to/custom/installation> (use custom version)
WITH_MECAB:STRING=

// Enable memory sanitizer
WITH_MSAN:BOOL=OFF

// Link MYSQLX statically to the server
WITH_MYSQLX:BOOL=ON

// Link mysqlx plugin with agains full version of protobuf/mysqlxmessages/mysqlxclient for better debugging
WITH_MYSQLX_USE_PROTOBUF_FULL:BOOL=OFF

// Link MYSQL_NATIVE_PASSWORD statically to the server
WITH_MYSQL_NATIVE_PASSWORD:BOOL=ON

// Build MySQL Cluster
WITH_NDB:BOOL=OFF

// Link NDBCLUSTER statically to the server
WITH_NDBCLUSTER_STORAGE_ENGINE:BOOL=ON

// Build the MySQL Cluster multithreadded data node
WITH_NDBMTD:BOOL=ON

// Extra compiler flags for NDB
WITH_NDB_CCFLAGS:STRING=

// Enable special ndb NDB features(including ERROR_INSERT)
WITH_NDB_DEBUG:BOOL=OFF

// Include NDB Cluster Java components
WITH_NDB_JAVA:BOOL=OFF

// Default port used by MySQL Cluster management server
WITH_NDB_PORT:STRING=

// Search path for TLS keys and certificates
WITH_NDB_TLS_SEARCH_PATH:STRING=$HOME/ndb-tls

// Link NGRAM_PARSER statically to the server
WITH_NGRAM_PARSER:BOOL=ON

// Explicitly set NUMA memory allocation policy
WITH_NUMA:BOOL=OFF

// Use DEB/RPM compiler flags
WITH_PACKAGE_FLAGS:BOOL=ON

// Build with Percona PAM plugin
WITH_PAM:BOOL=OFF

// Build with Percona LDAP Simple / LDAP SASL authentication plugins
WITH_PERCONA_AUTHENTICATION_LDAP:BOOL=ON

// Build Percona Telemetry component
WITH_PERCONA_TELEMETRY:BOOL=OFF

// Bundled protoc and protobuf library
WITH_PROTOBUF:STRING=bundled

// By default use bundled rapidjson on this platform
WITH_RAPIDJSON:STRING=bundled

// Build MySQL Router
WITH_ROUTER:BOOL=ON

// | system (use the OS sasl library), | </path/to/custom/installation>
WITH_SASL:STRING=system

// Build a shared library for unit tests which depend on the entire server
WITH_SHARED_UNITTEST_LIBRARY:BOOL=ON

// Allow showing the parse tree
WITH_SHOW_PARSE_TREE:BOOL=OFF

// | openssl[0-9]+ (use alternative system library)| yes (synonym for system)| </path/to/custom/openssl/installation>
WITH_SSL:STRING=system

// Enable installation of systemd support files
WITH_SYSTEMD:BOOL=OFF

// Build in systemd debug trace
WITH_SYSTEMD_DEBUG:BOOL=OFF

// Use -DWITH_XXX=system for CURL;ICU;LZ4;PROTOBUF;SSL;ZSTD;FIDO;ZLIB
WITH_SYSTEM_LIBS:BOOL=OFF

// Use tcmalloc rather than builtin malloc/free etc.
WITH_TCMALLOC:BOOL=OFF

// Use tcmalloc_debug rather than builtin malloc/free etc.
WITH_TCMALLOC_DEBUG:BOOL=OFF

// Have a built-in test protocol trace plugin in libmysql (requires WITH_CLIENT_PROTOCOL_TRACING option)
WITH_TEST_TRACE_PLUGIN:BOOL=OFF

// Enable thread sanitizer
WITH_TSAN:BOOL=OFF

// Enable undefined behavior sanitizer
WITH_UBSAN:BOOL=OFF

// Compile MySQL with unit tests
WITH_UNIT_TESTS:BOOL=ON

// Build UUID_VX UDF plugin
WITH_UUID_VX_UDF:BOOL=ON

// Valgrind instrumentation
WITH_VALGRIND:BOOL=OFF

// By default use bundled zlib on this platform
WITH_ZLIB:STRING=bundled

// By default use bundled zstd library
WITH_ZSTD:STRING=bundled

// Enable logging of protobuf messages
XPLUGIN_LOG_PROTOBUF:STRING=1

// Enable Zlib Examples
ZLIB_BUILD_EXAMPLES:BOOL=ON

// BUILD CONTRIB
ZSTD_BUILD_CONTRIB:BOOL=OFF

// BUILD PROGRAMS
ZSTD_BUILD_PROGRAMS:BOOL=ON

// BUILD TESTS
ZSTD_BUILD_TESTS:BOOL=OFF

// LEGACY SUPPORT
ZSTD_LEGACY_SUPPORT:BOOL=OFF

// MULTITHREADING SUPPORT
ZSTD_MULTITHREAD_SUPPORT:BOOL=OFF

// Provider of absl library
protobuf_ABSL_PROVIDER:STRING=module

// Adjust build flags to allow for ccache support.
protobuf_ALLOW_CCACHE:BOOL=OFF

// Build conformance tests
protobuf_BUILD_CONFORMANCE:BOOL=OFF

// Build libprotoc
protobuf_BUILD_LIBPROTOC:BOOL=OFF

// Build protobuf libraries and protoc compiler
protobuf_BUILD_PROTOBUF_BINARIES:BOOL=ON

// Build libprotoc and protoc compiler
protobuf_BUILD_PROTOC_BINARIES:BOOL=ON

// Remove runtime type information in the binaries
protobuf_DISABLE_RTTI:BOOL=OFF

// Install protobuf binaries and files
protobuf_INSTALL:BOOL=OFF

// Provider of jsoncpp library
protobuf_JSONCPP_PROVIDER:STRING=module

// Output directory for XML logs from tests.
protobuf_TEST_XML_OUTDIR:BOOL=OFF

// Configure installation
utf8_range_ENABLE_INSTALL:BOOL=OFF

// Build test suite
utf8_range_ENABLE_TESTS:BOOL=OFF

