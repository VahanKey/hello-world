#include <gtest/gtest.h>
#include "fun.h"

TEST(Fun_test, Returns13) {
    EXPECT_EQ(fun(), 13);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}