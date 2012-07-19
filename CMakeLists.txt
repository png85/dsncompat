#
# #das-system Networks compat lib
# (c) 2012 png!das-system
#
project(libdsncompat)
cmake_minimum_required(VERSION 2.8)

#
# add our custom .cmake macros to CMake's module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#
# CTest/CDash related options; see CTestConfig.cmake for more info!
include(CTest)
enable_testing()
set(BUILDNAME "${BUILDNAME}" CACHE STRING "Name of build on CDash dashboard")
mark_as_advanced(BUILDNAME)

#
# CPack configuration to build binary packages
set(CPACK_PACKAGE_DESCRIPTION "#das-system Networks compat library")
set(CPACK_PACKAGE_VENDOR "#das-system Networks GbR")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "99")
set(CPACK_PACKAGE_VERSION_PATCH "2")
include(CPack)

#
# LLVM/clang specific options; see README for info on how to use this!
option(USE_CLANG "build application with clang" OFF)
if(USE_CLANG)
  # Use clang for C code
  set(CMAKE_C_COMPILER "clang")
  set(CMAKE_C_FLAGS "-Wall -std=c99")
  set(CMAKE_C_FLAGS_DEBUG "-g")
  set(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
  set(CMAKE_C_FLAGS_RELEASE "-O4 -DNDEBUG")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

  # Use clang++ for C++ code
  set(CMAKE_CXX_COMPILER "clang++")
  set(CMAKE_CXX_FLAGS "-Wall")
  set(CMAKE_CXX_FLAGS_DEBUG "-g")
  set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O4 -DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

  # Use llvm binutils for linking
  set(CMAKE_AR "llvm-ar-3.0")
  set(CMAKE_LINKER "llvm-ld-3.0")
  set(CMAKE_NM "llvm-nm-3.0")
  set(CMAKE_OBJDUMP "llvm-objdump-3.0")
  # ranlib is currently disabled due to some symbol breakage --png
  #set(CMAKE_RANLIB "llvm-ranlib-3.0")
endif(USE_CLANG)

#
# Name and source file list of our library
set(DSNCOMPAT_LIBNAME "dsncompat")
set(DSNCOMPAT_SOURCES string/strtoupper.c string/strtolower.c)

add_executable(test-strtoupper string/test-strtoupper.c)
target_link_libraries(test-strtoupper ${DSNCOMPAT_LIBNAME})
add_test(test-strtoupper test-strtoupper)

add_executable(test-strtolower string/test-strtolower.c)
target_link_libraries(test-strtolower ${DSNCOMPAT_LIBNAME})
add_test(test-strtolower test-strtolower)

#
# Include macros for platform checks
include(CheckFunctionExists)

#
# Check for strcasecmp (case-insensitive strcmp())
check_function_exists(strcasecmp HAVE_STRCASECMP)
if(NOT HAVE_STRCASECMP)
  set(DSNCOMPAT_SOURCES ${DSNCOMPAT_SOURCES} string/strcasecmp.c)
  add_executable(test-strcasecmp string/test-strcasecmp.c)
  target_link_libraries(test-strcasecmp ${DSNCOMPAT_LIBNAME})
  add_test(strcasecmp test-strcasecmp)
endif(NOT HAVE_STRCASECMP)

#
# Check for strncasecmp (case-insensitive strncmp())
check_function_exists(strncasecmp HAVE_STRNCASECMP)
if(NOT HAVE_STRNCASECMP)
  set(DSNCOMPAT_SOURCES ${DSNCOMPAT_SOURCES} string/strncasecmp.c)
  add_executable(test-strncasecmp string/test-strncasecmp.c)
  target_link_libraries(test-strncasecmp ${DSNCOMPAT_LIBNAME})
  add_test(strncasecmp test-strncasecmp)
endif(NOT HAVE_STRNCASECMP)

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


#
# Check if target has Doxygen installed and add a doc target if it does
include(DocTarget)
