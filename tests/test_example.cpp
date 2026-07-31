#include "lib.h"
#include <gtest/gtest.h>

TEST(AddTest, Basic) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(-1, 1), 0);
}
