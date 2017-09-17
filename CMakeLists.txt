cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(phy2d)

# Version
set(phy2d_VERSION_MAJOR 0)
set(phy2d_VERSION_MINOR 0)
set(phy2d_VERSION_PATCH 1)
set(phy2d_VERSION_STRING "${phy2d_VERSION_MAJOR}.${phy2d_VERSION_MINOR}.${phy2d_VERSION_PATCH}")

# C++14
set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} INTERFACE)
add_library(sub::phy2d ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
  ${PROJECT_SOURCE_DIR}/inc
)
