cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(OSQ VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug 
    CACHE STRING 
      "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/data/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/data/")
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Compile executable
add_executable(OSQ src/main.cpp src/app.cpp src/engineUI.cpp src/Physics/physics.cpp src/Entities/block.cpp src/Graphics/sprites.cpp src/World/game.cpp src/World/scene.cpp src/World/chapter.cpp src/Graphics/camera.cpp src/Entities/player.cpp src/Entities/background.cpp src/Entities/npc.cpp src/utils.cpp src/Interactions/indicators.cpp src/Entities/character.cpp src/Graphics/debug_utils.cpp src/Interactions/chat.cpp src/Graphics/text.cpp src/Entities/items.cpp src/Graphics/particles.cpp src/Entities/objects.cpp src/ReadObjects/read_objs.cpp)

# Set include directory search paths
target_include_directories(OSQ 
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

# Set executable RPATH
set_target_properties(OSQ
  PROPERTIES
      INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
  )

# Link executable to required SFML modules
target_link_libraries(OSQ sfml-graphics sfml-audio)

# Set executable install location
install(TARGETS OSQ DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
