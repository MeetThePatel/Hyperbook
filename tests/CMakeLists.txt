FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.4
  )
FetchContent_MakeAvailable(Catch2)

add_executable(hyperbook_test testlib.cpp)
target_compile_features(hyperbook_test PRIVATE cxx_std_17)
target_link_libraries(hyperbook_test PRIVATE hyperbook_lib Catch2::Catch2 fmt::fmt)

add_test(NAME OrderSize COMMAND hyperbook_test)
