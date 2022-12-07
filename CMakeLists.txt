cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(SFMLBoilerplate VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(SFMLBoilerplate src/main.cpp)
target_include_directories(SFMLBoilerplate 
  PRIVATE "${PROJECT_BINARY_DIR}")

target_link_libraries(SFMLBoilerplate sfml-graphics)

install(TARGETS SFMLBoilerplate DESTINATION bin)
