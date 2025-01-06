#include <gtest/gtest.h>
#include "../include/Vector.h"

TEST(VectorFunctionTest, Norm) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    auto n = v0.norm();
    double nSolution = 3.7416573867739413;
    EXPECT_NEAR(n, nSolution, 1e-10);
}

TEST(VectorFunctionTest, Norm1) {
    MyMath::Vector<double> v0(std::vector<double>{1, -2, 3});
    auto n = v0.norm(1);
    double nSolution = 6;
    EXPECT_NEAR(n, nSolution, 1e-10);
}

TEST(VectorFunctionTest, InfNorm) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, -3});
    auto n = v0.norm(std::numeric_limits<int>::infinity());
    double nSolution = 3;
    EXPECT_NEAR(n, nSolution, 1e-10);
}

TEST(VectorFunctionTest, Dot) {
    MyMath::Vector<double> v0(std::vector<double>{1, 2, 3});
    MyMath::Vector<double> v1(std::vector<double>{4, 5, 6});
    auto d = MyMath::dot(v0, v1);
    double dSolution = 32;
    EXPECT_NEAR(d, dSolution, 1e-10);
}