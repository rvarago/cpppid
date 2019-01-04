#include <gtest/gtest.h>
#include "cpppid/composers/adder.hpp"
#include "cpppid/controllers/derivative.hpp"
#include "cpppid/controllers/integral.hpp"
#include "cpppid/controllers/proportional.hpp"

using namespace cpppid::composers;
using namespace cpppid::controllers;

TEST(CppPIDadder, shouldAddTwoProportionalControllers) {
    auto ctrl_proportional_1 = proportional<int>{2};
    auto ctrl_proportional_2 = proportional<int>{5};

    auto ctrl = adder<proportional<int>, proportional<int>>{
        ctrl_proportional_1, ctrl_proportional_2
    };

    EXPECT_EQ(ctrl(-100), -700);
    EXPECT_EQ(ctrl(-1), -7);
    EXPECT_EQ(ctrl(0), 0);
    EXPECT_EQ(ctrl(1), 7);
    EXPECT_EQ(ctrl(100), 700);
}

TEST(CppPIDadder, shouldComposeToPID) {
    auto ctrl_proportional = proportional<double>{2.5};
    auto ctrl_derivative = derivative<double, double, double>{5.4, 1.0};
    auto ctrl_integral = integral<double, double, double>{7.8, 1.0};

    auto ctrl_pid = adder<proportional<double>, derivative<double, double, double>, integral<double, double, double>>{
        ctrl_proportional, ctrl_derivative, ctrl_integral
    };

    EXPECT_NEAR(ctrl_pid(-100), -1570.0, 1);
    EXPECT_NEAR(ctrl_pid(-1), -255.7, 1);
    EXPECT_NEAR(ctrl_pid(0), -782.4, 1);
    EXPECT_NEAR(ctrl_pid(1), -772.1, 1);
    EXPECT_NEAR(ctrl_pid(100), 784.7, 1);
}
