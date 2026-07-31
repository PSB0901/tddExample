#include "factorial.h"
#include <gtest/gtest.h>

TEST(FactorialTest, HandlesZeroAndOne) {
    EXPECT_EQ(factorial(0), 1);
    EXPECT_EQ(factorial(1), 1);
}

TEST(FactorialTest, HandlesPositive) {
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(6), 720);
}
