#include <gtest/gtest.h>
#include "cpppid/pid.hpp"

TEST(pid, pid) {
    //ASSERT_DOUBLE_EQ(0.0, cpppid::pid());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}