# libdsncompat
(c) 2012-2013 #das-system Networks

## General info
this small library provides a bunch of non-standard C/C++ functions that are
available on various platforms for targets which don't have them. it is mainly
meant to be used as a submodule from within other  projects to provide a
portable implementation of these functions.

## Building [![Build Status](https://travis-ci.org/png85/dsncompat.png?branch=master)](https://travis-ci.org/png85/dsncompat)
use CMake to configure and build as needed. the library's build process is 
setup so that only the code that isn't present in the target system's libc
gets compiled and the output is a static library iteself which can be linked
into larger projects.

### LLVM/clang based build (experimental)
export CC=clang
export CXX=clang++
cmake -D USE_CLANG=ON /path/to/sources/
