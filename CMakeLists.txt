cmake_minimum_required(VERSION 3.16)
project(version C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_library(version SHARED library.c library.def)