cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(phy2d)

# C++14
set(CMAKE_CXX_STANDARD 14)

# Options
set(TRAVIS "NO" CACHE BOOL "If your name isn't Travis don't touch this.")
set(COVERALLS "NO" CACHE BOOL "Coveralls support")
set(COVERALLS_UPLOAD "NO" CACHE BOOL "Upload to coveralls")

# Fetch some dependencies from Git
include(ExternalProject)
find_package(Git REQUIRED)

# Modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/cmake/"
  "${CMAKE_SOURCE_DIR}/cmake/coveralls-cmake/cmake"
)

if(COVERALLS)
  include(Coveralls)
  set(COVERAGE_FLAGS "-g1 -fno-elide-constructors -fprofile-arcs -ftest-coverage --coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COVERAGE_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_FLAGS}")
endif()

# get sources
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/inc/phy2d/*")

# cppcheck and cpplint
if(NOT TRAVIS)
  set(CPPCHECK_SOURCES ${SOURCES})
  set(CPPLINT_SOURCES ${SOURCES})

  find_package(cppcheck REQUIRED)
  include(cppcheck)

  find_package(cpplint REQUIRED)
  include(cpplint)
endif()

# Get Catch from Github
ExternalProject_Add(catch
  PREFIX ${CMAKE_BINARY_DIR}/catch
  GIT_REPOSITORY https://github.com/philsquared/Catch.git
  TIMEOUT 10
  UPDATE_COMMAND ${GIT_EXECUTABLE} pull
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
  LOG_UPDATE ON
)
# Get Catch include directory and add it as an interface
ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR ${source_dir}/single_include)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Version
set(phy2d_VERSION_MAJOR 0)
set(phy2d_VERSION_MINOR 0)
set(phy2d_VERSION_PATCH 2)
set(phy2d_VERSION_STRING "${phy2d_VERSION_MAJOR}.${phy2d_VERSION_MINOR}.${phy2d_VERSION_PATCH}")

add_library(${PROJECT_NAME} INTERFACE)
add_library(sub::phy2d ALIAS ${PROJECT_NAME})

# Testing
# Get test sources
file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/test/*.cpp)
# Create the executable and link Catch and phy2d
add_executable(unit-tests ${TEST_SOURCES})
target_link_libraries(unit-tests Catch phy2d)

if(COVERALLS)
  coveralls_setup(
    "${SOURCES}"
    ${COVERALLS_UPLOAD}
    "${CMAKE_SOURCE_DIR}/cmake/coveralls-cmake/cmake"
  )
endif()

enable_testing()
add_test(test_all unit-tests)

target_include_directories(${PROJECT_NAME}
  INTERFACE
  ${PROJECT_SOURCE_DIR}/inc
)

# run cppcheck and cpplint with default build
if(NOT TRAVIS)
  add_dependencies(${PROJECT_NAME} cppcheck)
  add_dependencies(${PROJECT_NAME} cpplint)
endif()
