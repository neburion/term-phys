#include "Geometry/Angle.hpp"
#include "Core/Constants.hpp"
#include <gtest/gtest.h>

struct TestData{
    const char* name;
    double testRadians;
    double testDegrees;
};

class AngleTest : public testing::TestWithParam<TestData>{};

TEST_P(AngleTest, TestingGetters){
    auto [name, testRadians, testDegrees] = GetParam();
    
    Angle angle(testRadians);
    EXPECT_DOUBLE_EQ(angle.getRadians(), testRadians);
    EXPECT_DOUBLE_EQ(angle.getDegrees(), testDegrees);
}

TEST_P(AngleTest, TestingSetRadians){
    auto [name, testRadians, testDegrees] = GetParam();
    
    Angle angle(0);
    angle.setRadians(testRadians);
    EXPECT_DOUBLE_EQ(angle.getRadians(), testRadians);
    EXPECT_DOUBLE_EQ(angle.getDegrees(), testDegrees);
}

TEST_P(AngleTest, TestingSetDegrees){
    auto [name, testRadians, testDegrees] = GetParam();
    
    Angle angle(0);
    angle.setDegrees(testDegrees);
    EXPECT_DOUBLE_EQ(angle.getRadians(), testRadians);
    EXPECT_DOUBLE_EQ(angle.getDegrees(), testDegrees);
}

INSTANTIATE_TEST_SUITE_P(AngleTests, AngleTest, testing::Values(
    TestData{"zero",       0.0,    0.0},
    TestData{"quarter",    PI/2,   90.0},
    TestData{"half",       PI,     180.0},
    TestData{"3 qurters", -PI/2, -90.0},
    TestData{"full",       2*PI,   360.0}
));
