cmake_minimum_required( VERSION 3.2 ) 
project(Task3) 

#set( CMAKE_CXX_STANDARD 14 ) 
#set( CMAKE_CXX_STANDARD_REQUIRED ON ) 
#set( CMAKE_CXX_EXTENSIONS OFF ) 

set(CMAKE_BUILD_TYPE "Debug")

add_executable(main_a main_a.cpp)
add_executable(main_t main_t.cpp)

add_library(ACUnit acunit.h main_a.cpp)
target_include_directories(ACUnit PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(Thermo thermostat.h main_t.cpp)
target_include_directories(Thermo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(main_t PRIVATE Thermo -lrt)
set( CMAKE_CXX_FLAGS " -pthread -lrt" )

target_link_libraries(main_a PRIVATE ACUnit -lrt)
set( CMAKE_CXX_FLAGS " -pthread -lrt" )