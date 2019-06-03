cmake_minimum_required(VERSION 3.5)

project(phy2d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(phy2d_VERSION_MAJOR 0)
set(phy2d_VERSION_MINOR 1)
set(phy2d_VERSION_PATCH 3)
set(phy2d_VERSION_STRING "${phy2d_VERSION_MAJOR}.${phy2d_VERSION_MINOR}.${phy2d_VERSION_PATCH}")

add_library(${PROJECT_NAME} INTERFACE)
add_library(sub::phy2d ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
  ${PROJECT_SOURCE_DIR}/inc
)

# Unit tests

find_package(Catch2 REQUIRED)

file(GLOB
  TEST_SOURCES
  "${CMAKE_SOURCE_DIR}/test/*"
)
add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests
  Catch2::Catch2
  phy2d
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
