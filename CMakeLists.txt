#
# #das-system Networks compat lib
# (c) 2012 png!das-system
#
project(libdsncompat)
cmake_minimum_required(VERSION 2.8)

include(CTest)
enable_testing()

include(CheckFunctionExists)

set(DSNCOMPAT_LIBNAME "dsncompat")
set(DSNCOMPAT_SOURCES)

#
# Check for stricmp (case-insensitive strcmp())
check_function_exists(stricmp HAVE_STRICMP)
if(NOT HAVE_STRICMP)
  set(DSNCOMPAT_SOURCES ${DSNCOMPAT_SOURCES} string/stricmp.c)
  add_executable(test-stricmp string/test-stricmp.c)
  target_link_libraries(test-stricmp ${DSNCOMPAT_LIBNAME})
  add_test(stricmp test-stricmp)
endif(NOT HAVE_STRICMP)

#
# Check for strnicmp (case-insensitive strncmp())
check_function_exists(strnicmp HAVE_STRNICMP)
if(NOT HAVE_STRNICMP)
  set(DSNCOMPAT_SOURCES ${DSNCOMPAT_SOURCES} string/strnicmp.c)
  add_executable(test-strnicmp string/test-strnicmp.c)
  target_link_libraries(test-strnicmp ${DSNCOMPAT_LIBNAME})
  add_test(strnicmp test-strnicmp)
endif(NOT HAVE_STRNICMP)

#
# Generate config.h with check results
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#
# Build the actual library using only the required source files
add_library(dsncompat ${DSNCOMPAT_SOURCES})
