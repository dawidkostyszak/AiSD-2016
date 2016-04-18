cmake_minimum_required(VERSION 3.3)
project(AiSD_2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -W -O2 -static")

set(BUILD_1 sznurki)
set(SOURCE_FILES Pracownia_A/sznurki.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES})

set(BUILD_2 skoczek)
set(SOURCE_FILES_2 Pracownia_B/skoczek.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 trojkaty)
set(SOURCE_FILES_3 Pracownia_C/trojkaty.cpp)
add_executable(${BUILD_3} ${SOURCE_FILES_3})