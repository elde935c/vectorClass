#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorOperatorTest, AddVector) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{1, 2, 3});
    auto v = v0 + v1;
    MyMath::Vector<int> vSolution(std::vector<int>{2, 4, 6});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, AddMultipleVectors) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{4, 5, 6});
    MyMath::Vector<int> v2(std::vector<int>{7, 8, 9});
    auto v = v0 + v1 + v2;
    MyMath::Vector<int> vSolution(std::vector<int>{12, 15, 18});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, AddVectorDifferentSizes) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{1, 2});
    EXPECT_THROW({
        auto v = v0 + v1;
    }, std::invalid_argument);
}

TEST(VectorOperatorTest, SubtractVector) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{1, 2, 3});
    auto v = v0 - v1;
    MyMath::Vector<int> vSolution(std::vector<int>{0, 0, 0});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, UnityMinusOperator) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    auto v = -v0;
    MyMath::Vector<int> vSolution(std::vector<int>{-1,-2,-3});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, SubtractMultipleVectors) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{4, 5, 6});
    MyMath::Vector<int> v2(std::vector<int>{7, 8, 9});
    auto v = v0 - v1 - v2;
    MyMath::Vector<int> vSolution(std::vector<int>{-10, -11, -12});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, MutltiplyWithScalarFront) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    auto v = 2 * v0;
    MyMath::Vector<double> vSolution(std::vector<double>{2, 4, 6});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, MutltiplyWithScalarBack) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    auto v = v0 * 2;
    MyMath::Vector<double> vSolution(std::vector<double>{2, 4, 6});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, DivideWithScalar) {
    MyMath::Vector<double> v0(std::vector<double>{2, 4, 6});
    auto v = v0 / 2;
    MyMath::Vector<double> vSolution(std::vector<double>{1, 2, 3});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, DivideWithScalarZero) {
    MyMath::Vector<double> v0(std::vector<double>{2, 4, 6});
    EXPECT_THROW({
        auto v = v0 / 0;
    }, std::invalid_argument);
}

TEST(VectorOperatorTest, OrderOfOperators) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    MyMath::Vector<double> v1(std::vector<double>{4, 5, 6});
    auto v = v0 + v1 * 2;
    MyMath::Vector<double> vSolution(std::vector<double>{9, 12, 15});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, OrderOfOperatorsBrackets) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    MyMath::Vector<double> v1(std::vector<double>{4, 5, 6});
    auto v = (v0 + v1) * 2;
    MyMath::Vector<double> vSolution(std::vector<double>{10, 14, 18});
    EXPECT_EQ(v, vSolution);
}

TEST(VectorOperatorTest, CompoundAdd) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> v1(std::vector<int>{4, 5, 6});
    v0 += v1;
    MyMath::Vector<int> vSolution(std::vector<int>{5, 7, 9});
    EXPECT_EQ(v0, vSolution);
}

TEST(VectorOperatorTest, CompoundSubtract) {
    MyMath::Vector<int> v0(std::vector<int>{5, 7, 9});
    MyMath::Vector<int> v1(std::vector<int>{1, 2, 3});
    v0 -= v1;
    MyMath::Vector<int> vSolution(std::vector<int>{4, 5, 6});
    EXPECT_EQ(v0, vSolution);
}

TEST(VectorOperatorTest, CompoundMultiply) {
    MyMath::Vector<int> v0(std::vector<int>{1, 2, 3});
    v0 *= 2;
    MyMath::Vector<int> vSolution(std::vector<int>{2, 4, 6});
    EXPECT_EQ(v0, vSolution);
}

TEST(VectorOperatorTest, CompoundDivide) {
    MyMath::Vector<int> v0(std::vector<int>{2, 4, 6});
    v0 /= 2;
    MyMath::Vector<int> vSolution(std::vector<int>{1, 2, 3});
    EXPECT_EQ(v0, vSolution);
}