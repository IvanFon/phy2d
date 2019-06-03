cmake_minimum_required(VERSION 3.5)

project(phy2d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# Code coverage

add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/RunAdder.dir)
  message("Object files will be output to: ${OBJECT_DIR}")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g1 -fprofile-arcs -ftest-coverage")

  target_compile_options(coverage_config
    INTERFACE
    -O0
    -g
    --coverage
  )
  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(coverage_config INTERFACE --coverage)
  else()
    target_link_libraries(coverage_config INTERFACE --coverage)
  endif()
endif(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

# Testing

option(BUILD_TESTING "Build unit tests." ON)
if(BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
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
endif()
