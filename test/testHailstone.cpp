#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


TEST(HailstoneTests, accurateValueZero) {
    EXPECT_FALSE (satisfiesHailstone(0));
}

TEST(HailstoneTests, checkValueOne) {
    EXPECT_TRUE (satisfiesHailstone(1));
}

TEST(HailstoneTests, checkEvenValues) {
    EXPECT_TRUE (satisfiesHailstone(4));
    EXPECT_TRUE (satisfiesHailstone(6));
}

TEST(HailstoneTests, checkOddValues) {
    EXPECT_TRUE (satisfiesHailstone(5));
    EXPECT_TRUE (satisfiesHailstone(7));
}

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }