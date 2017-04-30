AC_INIT([spcol], [0.0.0])
AM_INIT_AUTOMAKE

: ${CXXFLAGS:=-g -Wall}

AC_PROG_CXX
#LT_INIT
dnl AC_PROG_RANLIB

PKG_CHECK_MODULES([ISO3D], [iso3d])

AC_CONFIG_FILES([ \
  Makefile \
  src/Makefile \
])
AC_OUTPUT
