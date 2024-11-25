cmake_minimum_required( VERSION 3.2 ) 
project(Task2) 

set( CMAKE_CXX_STANDARD 14 ) 
set( CMAKE_CXX_STANDARD_REQUIRED ON ) 
set( CMAKE_CXX_EXTENSIONS OFF ) 

add_executable(main main.cpp)

target_link_libraries(main PRIVATE Dynamic)

add_library(Dynamic dynamic_array.h main.cpp)
target_include_directories( Dynamic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" )



