#include <gtest/gtest.h>
#include "cpppid/controllers/onoff.hpp"

using namespace cpppid::controllers;

TEST(CppPIDonoff, shouldLimitTheErrorInARange) {
    auto const lower_bound = boundary<double, double>{-10, -100};
    auto const upper_bound = boundary<double, double>{10, 100};
    auto ctrl = onoff{lower_bound, upper_bound};

    EXPECT_EQ(ctrl(-10), -10);
    EXPECT_EQ(ctrl(10), 10);
    EXPECT_EQ(ctrl(0), 0);
    EXPECT_EQ(ctrl(-11), -100);
    EXPECT_EQ(ctrl(11), 100);
}
