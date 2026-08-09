# cmake .. -LH

// For backwards compatibility, what version of CMake commands and syntax should this version of CMake try to support.
CMAKE_BACKWARDS_COMPATIBILITY:STRING=2.4

// Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel
CMAKE_BUILD_TYPE:STRING=RelWithDebInfo

// install prefix
CMAKE_INSTALL_PREFIX:PATH=/usr/local/mysql

// Set to true if this is a community build
COMMUNITY_BUILD:BOOL=ON

// Enable profiling
ENABLED_PROFILING:BOOL=ON

// Enable gcov (debug, Linux builds only)
ENABLE_GCOV:BOOL=OFF

// Single output directory for building all executables.
EXECUTABLE_OUTPUT_PATH:PATH=

// Installation directory layout. Options are: STANDALONE (as in zip or tar.gz installer) RPM DEB SVR4
INSTALL_LAYOUT:STRING=STANDALONE

// Single output directory for building all libraries.
LIBRARY_OUTPUT_PATH:PATH=

// default MySQL data directory
MYSQL_DATADIR:PATH=/usr/local/mysql/data

// Allow linking with GPLv2-incompatible system libraries. Only set it you never plan to distribute the resulting binaries
NOT_FOR_DISTRIBUTION:BOOL=OFF

// PATH to MySQL TMP dir. Defaults to the P_tmpdir macro in <stdio.h>
TMPDIR:PATH=

// Use Aria for temporary tables
USE_ARIA_FOR_TMP_TABLES:BOOL=ON

// Use gcov for test coverage.
USE_GCOV:BOOL=OFF

// Link ARCHIVE statically to the server
WITH_ARCHIVE_STORAGE_ENGINE:BOOL=OFF

// Link ARIA statically to the server
WITH_ARIA_STORAGE_ENGINE:BOOL=ON

// Enable address sanitizer
WITH_ASAN:BOOL=OFF

// Link BLACKHOLE statically to the server
WITH_BLACKHOLE_STORAGE_ENGINE:BOOL=OFF

// Compile MySQL with embedded server
WITH_EMBEDDED_SERVER:BOOL=OFF

// Options are: none complex all
WITH_EXTRA_CHARSETS:STRING=all

// Link FEDERATEDX statically to the server
WITH_FEDERATEDX_STORAGE_ENGINE:BOOL=OFF

// Link FEEDBACK statically to the server
WITH_FEEDBACK:BOOL=OFF

// Build with jemalloc (possible values are 'yes', 'no', 'auto')
WITH_JEMALLOC:STRING=auto

// Compile with tcp wrappers support
WITH_LIBWRAP:BOOL=OFF

// Link PARTITION statically to the server
WITH_PARTITION_STORAGE_ENGINE:BOOL=ON

// Link PERFSCHEMA statically to the server
WITH_PERFSCHEMA_STORAGE_ENGINE:BOOL=ON

// Link QUERY_CACHE_INFO statically to the server
WITH_QUERY_CACHE_INFO:BOOL=OFF

// Use bundled readline
WITH_READLINE:BOOL=OFF

// Use safemalloc memory debugger. Will result in slower execution. Options are: ON OFF AUTO.
WITH_SAFEMALLOC:STRING=AUTO

// Link SPHINX statically to the server
WITH_SPHINX_STORAGE_ENGINE:BOOL=OFF

// Options are: no bundled yes(prefer os library if present otherwise use bundled) system(use os library)
WITH_SSL:STRING=no

// Compile MySQL with unit tests
WITH_UNIT_TESTS:BOOL=ON

// Valgrind instrumentation
WITH_VALGRIND:BOOL=OFF

// Link XTRADB statically to the server
WITH_XTRADB_STORAGE_ENGINE:BOOL=ON

// Use bundled zlib
WITH_ZLIB:STRING=bundled

// Path to a program.
gcc_ar:FILEPATH=/usr/bin/gcc-ar

// Path to a program.
gcc_ranlib:FILEPATH=/usr/bin/gcc-ranlib

