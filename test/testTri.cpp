#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;

TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

//three tests that should not pass due to bugs
TEST(TriangleTests, testPerimeterTwo) {
    Triangle *aTriangle = new Triangle(6, 5, 4);
    EXPECT_EQ (aTriangle->getPerimeter(), 15);
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(5, 4, 3);
    EXPECT_DOUBLE_EQ (aTriangle->getArea(), 6.0);
}

TEST(TriangleTests, testTriangleType) {
    Triangle *aTriangle = new Triangle(4, 4, 4);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}

//one expect_death test for invalid input
TEST(TriangleTests, testAscendingOrder) {
    EXPECT_DEATH (Triangle(1, 2, 3), "First side is not the longest");
}

//five tests that should pass
TEST(TriangleTests, testPerimeterNoThrow) {
    Triangle *aTriangle = new Triangle(4, 3, 2);
    EXPECT_NO_THROW (aTriangle->getPerimeter());
}

TEST(TriangleTests, testAreaNoThrow) {
    Triangle *aTriangle = new Triangle(8, 6, 3);
    EXPECT_NO_THROW (aTriangle->getArea());
}

TEST(TriangleTests, testKind) {
    Triangle *aTriangle = new Triangle(6, 6, 4);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::ISOSCELES);
}

TEST(TriangleTests, testKindTwo) {
    Triangle *aTriangle = new Triangle(7, 5, 3);
    EXPECT_EQ (aTriangle->getKind(), Triangle::Kind::SCALENE);
}

TEST(TriangleTests, testNegativeSideLengths) {
    EXPECT_DEATH (new Triangle(-4, -3, -2), "First side is not the longest");
}

// int main (int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }