cmake_minimum_required(VERSION 2.8)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

project (antihook_test)

add_subdirectory (launcher)
add_subdirectory (sampleDLL)
add_subdirectory (testConsole)
