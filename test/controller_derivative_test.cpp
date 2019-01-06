#include <gtest/gtest.h>
#include "cpppid/controllers/derivative.hpp"

using namespace cpppid::controllers;

TEST(CppPIDderivative, shouldReturnProportionalToTheDerivativeOfTheError) {
    auto ctrl = derivative<int, double, int>{2, 3.0, 0};

    EXPECT_NEAR(ctrl(0), 0.000, 0.001);
    EXPECT_NEAR(ctrl(1), 0.667, 0.001);
    EXPECT_NEAR(ctrl(4), 2.000, 0.001);
    EXPECT_NEAR(ctrl(14), 6.667, 0.001);
    EXPECT_NEAR(ctrl(3), -7.333, 0.001);
}

TEST(CppPIDderivative, shouldDefaultToInitialErrorOfZero) {
    auto ctrl = derivative<int, int, int>{2, 1};

    EXPECT_EQ(ctrl(2), 4);
}

TEST(CppPIDderivative, shouldInferTemplateArg) {
    auto ctrl = derivative<>{2.0, 1};

    EXPECT_DOUBLE_EQ(ctrl(1), 2.0);
}