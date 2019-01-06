#include <gtest/gtest.h>
#include "cpppid/controllers/proportional.hpp"

using namespace cpppid::controllers;

TEST(CppPIDproportional, shouldResetTheError) {
    auto ctrl = proportional<int>{0};

    EXPECT_EQ(ctrl(-100), 0);
    EXPECT_EQ(ctrl(-1), 0);
    EXPECT_EQ(ctrl(0), 0);
    EXPECT_EQ(ctrl(1), 0);
    EXPECT_EQ(ctrl(100), 0);
}

TEST(CppPIDproportional, shouldSquareTheError) {
    auto ctrl = proportional<int>{2};

    EXPECT_EQ(ctrl(-10), -20);
    EXPECT_EQ(ctrl(-1), -2);
    EXPECT_EQ(ctrl(0), 0);
    EXPECT_EQ(ctrl(1), 2);
    EXPECT_EQ(ctrl(10), 20);
}

TEST(CppPIDproportional, shouldReturnDoubleIfErrorIsDouble) {
    auto ctrl = proportional<int>{3};

    EXPECT_DOUBLE_EQ(ctrl(0.0), 0.0);
    EXPECT_DOUBLE_EQ(ctrl(1.5), 4.5);
}

TEST(CppPIDproportional, shouldInferTemplateArg) {
    auto ctrl = proportional{2.0};

    EXPECT_DOUBLE_EQ(ctrl(1), 2.0);
}