file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${Hyperbook_SOURCE_DIR}/include/hyperbook/*.h")

add_library(hyperbook_lib ${HEADER_LIST} hyperbook.cpp OrderBook.cpp Order.cpp)

target_include_directories(hyperbook_lib PUBLIC ../include)
target_link_libraries(hyperbook_lib PRIVATE fmt::fmt)
target_compile_features(hyperbook_lib PUBLIC cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
  )
