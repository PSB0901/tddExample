#include "../src/c_funcs.h"
#include <gtest/gtest.h>

TEST(CFuncsTest, GcdPositive) {
    EXPECT_EQ(gcd(48, 18), 6);
    EXPECT_EQ(gcd(7, 3), 1);
}

TEST(CFuncsTest, GcdWithZeroAndNegative) {
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(-12, 8), 4);
    EXPECT_EQ(gcd(12, -8), 4);
}

TEST(FizzBuzz, testFizzBuzz)
{
    ASSERT_EQ(fizzbuzz(3), 300);
}

TEST(FizzBuzz, testBuzz)
{
    ASSERT_EQ(fizzbuzz(5), 500);
}

TEST(FizzBuzz, testFizzBuzzAndBuzz)
{
    ASSERT_EQ(fizzbuzz(15), 15000);
}