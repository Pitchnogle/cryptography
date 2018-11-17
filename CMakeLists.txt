# cryptography/CMakeLists.txt
#
# Usage:
# cmake ..
# make
#
cmake_minimum_required (VERSION 2.8)

project (cryptography)

# Set path to c++ compiler
set(CMAKE_CXX_COMPILER /usr/bin/g++)

# Folder alias
set (SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set (TOOLS_DIR ${CMAKE_SOURCE_DIR}/tools)

# Set the include directories
include_directories(/usr/include ${SRC_DIR})

# Build detab
add_executable(detab ${TOOLS_DIR}/detab.cpp)

# Build newline
add_executable(newline ${TOOLS_DIR}/newline.cpp)

# Build regroup
add_executable(regroup ${TOOLS_DIR}/regroup.cpp)

# Build morse
add_executable(morse ${TOOLS_DIR}/morse.cpp ${SRC_DIR}/MorseCode.cpp)
