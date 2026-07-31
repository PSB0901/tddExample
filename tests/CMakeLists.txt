add_executable(example_test test_example.cpp test_factorial.cpp test_c_example.cpp)
target_link_libraries(example_test PRIVATE example GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(example_test)
