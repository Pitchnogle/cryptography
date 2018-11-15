# cryptography/CMakeLists.txt
#
# Usage:
# cmake ..
# make
#
cmake_minimum_required (VERSION 2.8)

# Set path to c++ compiler
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project (cryptography)

# Set path to c++ compiler
#set(CMAKE_CXX_COMPILER /usr/bin/g++)

include(GNUInstallDirs ${PROJECT_SOURCE_DIR})

# Folder alias
set (SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Set the include directories
#include_directories(/usr/include ${SRC_DIR})

# TODO -- make into lib?

# Build morse_encode
add_executable(morse_encode ${SRC_DIR}/morse_encode.cpp)

# Build morse_decode
add_executable(morse_decode ${SRC_DIR}/morse_decode.cpp)

# Build morse_encode_bin
add_executable(morse_encode_bin ${SRC_DIR}/morse_encode_bin.cpp)

# Build morse_decode_bin
add_executable(morse_decode_bin ${SRC_DIR}/morse_decode_bin.cpp)

# Build the utils
subdirs(utils)
