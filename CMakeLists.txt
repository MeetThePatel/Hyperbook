cmake_minimum_required(VERSION 3.15)

project(
  Hyperbook
  VERSION 0.0.1
  DESCRIPTION "Hyperbook is an order-matching engine used for financial market simulation."
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(CTest)

find_package(Boost REQUIRED)

include(FetchContent)
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  )
FetchContent_MakeAvailable(fmtlib)

add_subdirectory(src)
add_subdirectory(apps)

add_subdirectory(tests)

# TODO: Integrate Doxygen
