add_executable(driver driver.cpp)
target_compile_features(driver PRIVATE cxx_std_17)
target_link_libraries(driver PRIVATE hyperbook_lib)
