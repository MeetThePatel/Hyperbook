file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${Hyperbook_SOURCE_DIR}/include/hyperbook/*.h")

add_library(hyperbook_lib hyperbook.cpp ${HEADER_LIST})

target_include_directories(hyperbook_lib PUBLIC ../include)

target_compile_features(hyperbook_lib PUBLIC cxx_std_17)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
  )
