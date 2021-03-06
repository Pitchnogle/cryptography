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

# Set compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

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
add_executable(morse ${TOOLS_DIR}/morse.cpp ${SRC_DIR}/morse_code.cpp)

# Build atbash
add_executable(atbash ${TOOLS_DIR}/atbash.cpp ${SRC_DIR}/atbash_cipher.cpp)

# Build caesar
add_executable(caesar ${TOOLS_DIR}/caesar.cpp ${SRC_DIR}/caesar_cipher.cpp)

# Build vigenere
add_executable(vigenere ${TOOLS_DIR}/vigenere.cpp ${SRC_DIR}/vigenere_cipher.cpp)

# Build scramble
add_executable(scramble ${TOOLS_DIR}/scramble.cpp)

# Build railfence
add_executable(railfence ${TOOLS_DIR}/railfence.cpp)
