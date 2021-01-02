cmake_minimum_required(VERSION 3.15)

project(
  Hyperbook
  VERSION 0.0.1
  DESCRIPTION "Hyperbook is an order-matching engine used for finnacial market simulation."
  LANGUAGES CXX
  )

set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  )
FetchContent_MakeAvailable(fmtlib)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
add_subdirectory(apps)

# TODO: Add testing.
