AC_INIT([spcol], [0.0.0])
AM_INIT_AUTOMAKE

: ${CXXFLAGS:=-g -Wall}

AC_PROG_CXX
#LT_INIT
dnl AC_PROG_RANLIB

PKG_CHECK_MODULES([LOS], [los])
AC_PATH_PROG([LOS_GENTYPES], [los-gentypes])
test x"LOS_GENTYPES" != x || AC_ERROR([los-gentypes not found])

PKG_CHECK_MODULES([AL5], [allegro-debug-5])

AC_CONFIG_FILES([ \
  Makefile \
  src/Makefile \
])
AC_OUTPUT
