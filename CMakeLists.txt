cmake_minimum_required(VERSION 3.3)
project(AiSD_2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -W -O2 -static")

set(BUILD_1 sznurki)
set(SOURCE_FILES Pracownia_A/sznurki.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES})

#set(BUILD_2 main_2)
#set(SOURCE_FILES_2 main_2.cc) //where main_2.cc is your second main/program
#add_executable(${BUILD_2} ${SOURCE_FILES_2})