#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorConstructorTest, ConstructorSize) {
        MyMath::Vector<int> v(3);
        EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, ConstructorEntriesDouble) {
    MyMath::Vector<double> v(std::vector<double>{1.2, 2.345, 3.234});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, ConstructorEntriesInt) {
    MyMath::Vector<int> v(std::vector<int>{1, 2, 3});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, EmptyVector) {
    MyMath::Vector<int> v(0);
    EXPECT_EQ(v.getSize(), 0);
}

TEST(VectorConstructorTest, SingleElementVector) {
    MyMath::Vector<int> v(std::vector<int>{42});
    EXPECT_EQ(v.getSize(), 1);
}

TEST(VectorConstructorTest, LargeVector) {
    MyMath::Vector<int> v(1000);
    EXPECT_EQ(v.getSize(), 1000);
}

TEST(VectorConstructorTest, VectorWithNegativeNumbers) {
    MyMath::Vector<int> v(std::vector<int>{-1, -2, -3});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, VectorWithMixedNumbers) {
    MyMath::Vector<int> v(std::vector<int>{-1, 0, 1});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, VectorWithFloatingPointNumbers) {
    MyMath::Vector<float> v(std::vector<float>{1.1f, 2.2f, 3.3f});
    EXPECT_EQ(v.getSize(), 3);
}

TEST(VectorConstructorTest, CopyConstructor) {
    MyMath::Vector<int> original(std::vector<int>{1, 2, 3});
    MyMath::Vector<int> copy = original;
    EXPECT_EQ(copy.getSize(), 3);
    EXPECT_EQ(copy.getSize(), original.getSize());
}