AC_PREREQ([2.71])
AC_INIT([STATS],[0.1],[mike@conlen.org])
AC_CONFIG_SRCDIR([src/test.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])
AC_PROG_CXX([g++])
CXXFLAGS="$CXXFLAGS --std=c++0x"
LDFLAGS="$LDFLAGS"
AM_PROG_AR
LT_INIT
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])
AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/tools/Makefile
])
AC_OUTPUT
