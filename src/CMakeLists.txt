add_library(example STATIC lib.cpp factorial.cpp c_funcs.c)
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
