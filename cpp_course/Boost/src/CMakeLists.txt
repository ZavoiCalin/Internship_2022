cmake_minimum_required( VERSION 3.2 ) 
project(Boost) 

#set( CMAKE_CXX_STANDARD 14 ) 
#set( CMAKE_CXX_STANDARD_REQUIRED ON ) 
#set( CMAKE_CXX_EXTENSIONS OFF ) 

add_executable(main main.cpp)

add_library(Boosting boosting.h main.cpp)
target_include_directories(Boosting PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(main PRIVATE Boosting -lrt)
set( CMAKE_CXX_FLAGS " -pthread -lrt" )
