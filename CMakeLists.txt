cmake_minimum_required (VERSION 3.16)
project (myproj VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

find_package (jsoncpp  REQUIRED)
include_directories(${JSONCPP_INCLUDE_DIRS})

add_executable (myapp main.cpp)
target_link_libraries (myapp jsoncpp)

