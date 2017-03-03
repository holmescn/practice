cmake_minimum_required (VERSION 3.1)
project (LibUVPractices)

find_package(PkgConfig)
pkg_check_modules(PC_LIBUV REQUIRED libuv)
set(LIBUV_DEFINITIONS ${PC_LIBUV_CFLAGS_OTHER})

find_path(LIBUV_INCLUDE_DIR uv.h
          HINTS ${PC_LIBUV_INCLUDEDIR} ${PC_LIBUV_INCLUDE_DIRS})

find_library(LIBUV_LIBRARY NAMES uv libuv
             HINTS ${PC_LIBUV_LIBDIR} ${PC_LIBUV_LIBRARY_DIRS})

set(LIBUV_LIBRARIES ${LIBUV_LIBRARY})
set(LIBUV_INCLUDE_DIRS ${LIBUV_INCLUDE_DIR})

