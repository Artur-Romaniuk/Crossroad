cmake_minimum_required(VERSION 3.10)

project(CrossRoad CXX)

set(CMAKE_CXX_STANDARD 20)

set(BOOST_ROOT "$HOME/usr/local/boost_1_77_0")

find_package (Boost 1.77.0 REQUIRED COMPONENTS system filesystem)
if (Boost_FOUND)
  include_directories (SYSTEM ${Boost_INCLUDE_DIR})
endif ()

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(CrossRoad ${SOURCES})