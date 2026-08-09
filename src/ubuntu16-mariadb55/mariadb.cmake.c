# cmake .. -LAH
-- Running cmake version 3.5.1
-- MariaDB 5.5.68
-- Packaging as: mariadb-5.5.68-Linux-x86_64
-- Performing Test NEW_READLINE_INTERFACE
-- Performing Test NEW_READLINE_INTERFACE - Success
-- Performing Test READLINE_V5
-- Performing Test READLINE_V5 - Failed
-- Performing Test LIBEDIT_INTERFACE
-- Performing Test LIBEDIT_INTERFACE - Success
CMake Warning at storage/tokudb/CMakeLists.txt:17 (MESSAGE):
  TokuDB is enabled, but jemalloc is not.  This configuration is not
  supported


-- Found ZLIB: zlib
-- Boost version: 1.58.0
-- Performing Test BOOST_OK
-- Performing Test BOOST_OK - Failed
-- Configuring done
-- Generating done
-- Build files have been written to: /usr/local/src/mariadb-5.5.68/build_tmp_dir
-- Cache values
// path to the executable
ACLOCAL_EXECUTABLE:FILEPATH=/usr/bin/aclocal

// Path to a library.
AIO_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libaio.so

// path to the executable
AUTOCONF_EXECUTABLE:FILEPATH=/usr/bin/autoconf

// path to the executable
AUTOHEADER_EXECUTABLE:FILEPATH=/usr/bin/autoheader

// path to the executable
AUTOMAKE_EXECUTABLE:FILEPATH=/usr/bin/automake

//
BACKUP_TEST:BOOL=OFF

// path to the bison executable
BISON_EXECUTABLE:FILEPATH=/usr/bin/bison

// CTest build name
BUILDNAME:STRING=ft-index RelWithDebInfo Linux-6.8.0-136-generic x86_64 GNU c++ 5.4.0

// Build the testing tree.
BUILD_TESTING:BOOL=OFF

// The directory containing a CMake configuration file for Boost.
Boost_DIR:PATH=Boost_DIR-NOTFOUND

// Path to a file.
Boost_INCLUDE_DIR:PATH=/usr/include

// path to the executable
CAT_EXECUTABLE:FILEPATH=/bin/cat

// Path to a program.
CHECKMODULE:FILEPATH=CHECKMODULE-NOTFOUND

// Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

// For backwards compatibility, what version of CMake commands and syntax should this version of CMake try to support.
CMAKE_BACKWARDS_COMPATIBILITY:STRING=2.4

// Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel
CMAKE_BUILD_TYPE:STRING=RelWithDebInfo

// Enable/Disable color output during build.
CMAKE_COLOR_MAKEFILE:BOOL=ON

// CXX compiler
CMAKE_CXX_COMPILER:FILEPATH=/usr/bin/c++

// Flags used by the compiler during all build types.
CMAKE_CXX_FLAGS:STRING=

// Flags used by the compiler during debug builds.
CMAKE_CXX_FLAGS_DEBUG:STRING=-g

// Flags used by the compiler during release builds for minimum size.
CMAKE_CXX_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

// Flags used by the compiler during release builds.
CMAKE_CXX_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

// Flags used by the compiler during release builds with debug info.
CMAKE_CXX_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

// C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

// Flags used by the compiler during all build types.
CMAKE_C_FLAGS:STRING=

// Flags used by the compiler during debug builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

// Flags used by the compiler during release builds for minimum size.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

// Flags used by the compiler during release builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

// Flags used by the compiler during release builds with debug info.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

// Flags used by the linker.
CMAKE_EXE_LINKER_FLAGS:STRING=

// Flags used by the linker during debug builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

// Flags used by the linker during release minsize builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

// Flags used by the linker during release builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

// Flags used by the linker during Release with Debug Info builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

// Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=OFF

// install prefix
CMAKE_INSTALL_PREFIX:PATH=/usr/local/mysql

// Path to a program.
CMAKE_LINKER:FILEPATH=/usr/bin/ld

// Path to a program.
CMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make

// Flags used by the linker during the creation of modules.
CMAKE_MODULE_LINKER_FLAGS:STRING=

// Flags used by the linker during debug builds.
CMAKE_MODULE_LINKER_FLAGS_DEBUG:STRING=

// Flags used by the linker during release minsize builds.
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL:STRING=

// Flags used by the linker during release builds.
CMAKE_MODULE_LINKER_FLAGS_RELEASE:STRING=

// Flags used by the linker during Release with Debug Info builds.
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

// Path to a program.
CMAKE_NM:FILEPATH=/usr/bin/nm

// Path to a program.
CMAKE_OBJCOPY:FILEPATH=/usr/bin/objcopy

// Path to a program.
CMAKE_OBJDUMP:FILEPATH=/usr/bin/objdump

// Path to a program.
CMAKE_RANLIB:FILEPATH=/usr/bin/ranlib

// Flags used by the linker during the creation of dll's.
CMAKE_SHARED_LINKER_FLAGS:STRING=

// Flags used by the linker during debug builds.
CMAKE_SHARED_LINKER_FLAGS_DEBUG:STRING=

// Flags used by the linker during release minsize builds.
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL:STRING=

// Flags used by the linker during release builds.
CMAKE_SHARED_LINKER_FLAGS_RELEASE:STRING=

// Flags used by the linker during Release with Debug Info builds.
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO:STRING=

// If set, runtime paths are not added when installing shared libraries, but are added when building.
CMAKE_SKIP_INSTALL_RPATH:BOOL=NO

// If set, runtime paths are not added when using shared libraries.
CMAKE_SKIP_RPATH:BOOL=NO

// Flags used by the linker during the creation of static libraries.
CMAKE_STATIC_LINKER_FLAGS:STRING=

// Flags used by the linker during debug builds.
CMAKE_STATIC_LINKER_FLAGS_DEBUG:STRING=

// Flags used by the linker during release minsize builds.
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL:STRING=

// Flags used by the linker during release builds.
CMAKE_STATIC_LINKER_FLAGS_RELEASE:STRING=

// Flags used by the linker during Release with Debug Info builds.
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO:STRING=

// Path to a program.
CMAKE_STRIP:FILEPATH=/usr/bin/strip

// Revision of tokudb.
CMAKE_TOKUDB_REVISION:STRING=0

// If this value is on, makefiles will be generated without the .SILENT directive, and all commands will be echoed to the console during the make.  This is useful for debugging only. With Visual Studio IDE projects all commands are done without /nologo.
CMAKE_VERBOSE_MAKEFILE:BOOL=FALSE

// Set to true if this is a community build
COMMUNITY_BUILD:BOOL=ON

// Path to a library.
CURSES_CURSES_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libcurses.so

// Path to a library.
CURSES_FORM_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libform.so

// Path to a file.
CURSES_INCLUDE_PATH:PATH=/usr/include

// Path to a library.
CURSES_NCURSES_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libncurses.so

//
CYBOZU:BOOL=OFF

// Don't build shared libraries, compile code as position-dependent
DISABLE_SHARED:BOOL=OFF

// Path to a program.
DTRACE:FILEPATH=DTRACE-NOTFOUND

// If we should should enable LOAD DATA LOCAL by default (OFF/ON/AUTO)
ENABLED_LOCAL_INFILE:STRING=AUTO

// Enable profiling
ENABLED_PROFILING:BOOL=ON

// Enable gcov (debug, Linux builds only)
ENABLE_GCOV:BOOL=OFF

// Path to a library.
EVENT_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libevent.so

// Single output directory for building all executables.
EXECUTABLE_OUTPUT_PATH:PATH=

// path to the executable
GIT_EXECUTABLE:FILEPATH=/usr/bin/git

// path to the executable
GLIBTOOLIZE_EXECUTABLE:FILEPATH=GLIBTOOLIZE_EXECUTABLE-NOTFOUND

// Path to a program.
GROFF:FILEPATH=GROFF-NOTFOUND

// path to the executable
GTAR_EXECUTABLE:FILEPATH=GTAR_EXECUTABLE-NOTFOUND

// BIN installation directory
INSTALL_BINDIR:STRING=bin

// DOC installation directory
INSTALL_DOCDIR:STRING=docs

// DOCREADME installation directory
INSTALL_DOCREADMEDIR:STRING=.

// INCLUDE installation directory
INSTALL_INCLUDEDIR:STRING=include/mysql

// INFO installation directory
INSTALL_INFODIR:STRING=docs

// Installation directory layout. Options are: STANDALONE (as in zip or tar.gz installer) RPM DEB SVR4
INSTALL_LAYOUT:STRING=STANDALONE

// LIB installation directory
INSTALL_LIBDIR:STRING=lib

// MAN installation directory
INSTALL_MANDIR:STRING=man

// MYSQLDATA installation directory
INSTALL_MYSQLDATADIR:STRING=data

// MYSQLSHARE installation directory
INSTALL_MYSQLSHAREDIR:STRING=share

// MYSQLTEST installation directory
INSTALL_MYSQLTESTDIR:STRING=mysql-test

// PLUGIN installation directory
INSTALL_PLUGINDIR:STRING=lib/plugin

// SBIN installation directory
INSTALL_SBINDIR:STRING=bin

// SCRIPT installation directory
INSTALL_SCRIPTDIR:STRING=scripts

// SHARE installation directory
INSTALL_SHAREDIR:STRING=share

// SQLBENCH installation directory
INSTALL_SQLBENCHDIR:STRING=.

// SUPPORTFILES installation directory
INSTALL_SUPPORTFILESDIR:STRING=support-files

// SYSCONF2 installation directory
INSTALL_SYSCONF2DIR:STRING=

// SYSCONF installation directory
INSTALL_SYSCONFDIR:STRING=

// UNIX_ADDR installation directory
INSTALL_UNIX_ADDRDIR:STRING=/tmp/mysql.sock

// Path to a file.
LIBEDIT_INCLUDE_DIR:PATH=/usr/include/editline

// Path to a library.
LIBEDIT_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libedit.so

// Single output directory for building all libraries.
LIBRARY_OUTPUT_PATH:PATH=

// Name of libtokufractaltree.so
LIBTOKUDB:STRING=tokufractaltree

// Name of libtokuportability.so
LIBTOKUPORTABILITY:STRING=tokuportability

// path to the executable
LIBTOOLIZE_EXECUTABLE:FILEPATH=/usr/bin/libtoolize

// Set the entity that appears as the manufacturer of packages that support a manufacturer field.
MANUFACTURER:STRING=Built from Source

// default MySQL data directory
MYSQL_DATADIR:PATH=/usr/local/mysql/data

// MySQL maintainer-specific development environment. Options are: ON OFF AUTO.
MYSQL_MAINTAINER_MODE:STRING=AUTO

// MySQL project name
MYSQL_PROJECT_NAME:STRING=MySQL

// Allow linking with GPLv2-incompatible system libraries. Only set it you never plan to distribute the resulting binaries
NOT_FOR_DISTRIBUTION:BOOL=OFF

// No need to use alarm to implement socket timeout
NO_ALARM:BOOL=1

// Path to a program.
NROFF:FILEPATH=NROFF-NOTFOUND

// Path to a file.
READLINE_INCLUDE_DIR:PATH=/usr/include/readline

// Path to a library.
READLINE_LIBRARY:FILEPATH=/usr/lib/x86_64-linux-gnu/libreadline.so

// Path to a program.
SEMODULE_PACKAGE:FILEPATH=SEMODULE_PACKAGE-NOTFOUND

// path to the executable
TAR_EXECUTABLE:FILEPATH=/bin/tar

// PATH to MySQL TMP dir. Defaults to the P_tmpdir macro in <stdio.h>
TMPDIR:PATH=

// Path to data files for tests
TOKUDB_DATA:FILEPATH=/usr/local/src/mariadb-5.5.68/storage/tokudb/ft-index/../tokudb.data

// Enable paranoid asserts.
TOKU_DEBUG_PARANOID:BOOL=OFF

// Use Aria for temporary tables
USE_ARIA_FOR_TMP_TABLES:BOOL=ON

//
USE_BDB:BOOL=OFF

// Use gcov for test coverage.
USE_GCOV:BOOL=OFF

// Build to run safely under valgrind (often slower).
USE_VALGRIND:BOOL=OFF

// OFF
WITHOUT_SERVER:BOOL=OFF

// Link ARCHIVE statically to the server
WITH_ARCHIVE_STORAGE_ENGINE:BOOL=OFF

// Link ARIA statically to the server
WITH_ARIA_STORAGE_ENGINE:BOOL=ON

// Enable address sanitizer
WITH_ASAN:BOOL=OFF

// Implement atomic operations using pthread rwlocks or atomic CPU
instructions for multi-processor or uniprocessor
configuration. By default gcc built-in sync functions are used,
if available and 'smp' configuration otherwise.
WITH_ATOMIC_LOCKS:STRING=

// Link BLACKHOLE statically to the server
WITH_BLACKHOLE_STORAGE_ENGINE:BOOL=OFF

// Compile MySQL with embedded server
WITH_EMBEDDED_SERVER:BOOL=OFF

// Options are: none complex all
WITH_EXTRA_CHARSETS:STRING=all

// Compile with fast mutexes
WITH_FAST_MUTEXES:BOOL=OFF

// Link FEDERATEDX statically to the server
WITH_FEDERATEDX_STORAGE_ENGINE:BOOL=OFF

// Link FEEDBACK statically to the server
WITH_FEEDBACK:BOOL=OFF

// Build with jemalloc (possible values are 'yes', 'no', 'auto')
WITH_JEMALLOC:STRING=auto

// Compile with tcp wrappers support
WITH_LIBWRAP:BOOL=OFF

// Additional linker flags for mysqld
WITH_MYSQLD_LDFLAGS:STRING=

// Link PARTITION statically to the server
WITH_PARTITION_STORAGE_ENGINE:BOOL=ON

// Link PERFSCHEMA statically to the server
WITH_PERFSCHEMA_STORAGE_ENGINE:BOOL=ON

// Generate PIC objects
WITH_PIC:BOOL=OFF

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

// Where to find sources for xz (lzma).
XZ_SOURCE_DIR:FILEPATH=/usr/local/src/mariadb-5.5.68/storage/tokudb/ft-index/third_party/xz-4.999.9beta

// Path to a file.
ZLIB_INCLUDE_DIR:PATH=ZLIB_INCLUDE_DIR-NOTFOUND

// Path to a library.
ZLIB_LIBRARY_DEBUG:FILEPATH=ZLIB_LIBRARY_DEBUG-NOTFOUND

// Path to a library.
ZLIB_LIBRARY_RELEASE:FILEPATH=ZLIB_LIBRARY_RELEASE-NOTFOUND

// Path to a program.
gcc_ar:FILEPATH=/usr/bin/gcc-ar

// Path to a program.
gcc_ranlib:FILEPATH=/usr/bin/gcc-ranlib

