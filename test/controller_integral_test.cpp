#include <gtest/gtest.h>
#include "cpppid/controllers/integral.hpp"

using namespace cpppid::controllers;

TEST(CppPIDintegral, shouldReturnProportionalToTheIntegralOfTheError) {
    auto ctrl = integral<int, double, int>{2, 3.0};

    EXPECT_NEAR(ctrl(0), 0.000, 0.001);
    EXPECT_NEAR(ctrl(1), 6.000, 0.001);
    EXPECT_NEAR(ctrl(4), 30.000, 0.001);
    EXPECT_NEAR(ctrl(14), 114.000, 0.001);
    EXPECT_NEAR(ctrl(3), 132.000, 0.001);
}

TEST(CppPIDintegral, shouldInferTemplateArg) {
    auto ctrl = integral{2.0, 1};

    EXPECT_DOUBLE_EQ(ctrl(1), 2.0);
}