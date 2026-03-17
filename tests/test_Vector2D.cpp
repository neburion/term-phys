#include "geometry/Vector2D.hpp"
#include "geometry/Angle.hpp"
#include "core/Constants.hpp"
#include <cmath>
#include <gtest/gtest.h>

struct TestData{
    const char* name;
    double x;
    double y;
    double magnitude;
    double radiansAngle;
};

class Vector2DTest : public testing::TestWithParam<TestData>{};

TEST_P(Vector2DTest, TestingGetters){
    auto [name, x, y, magnitude, radiansAngle] = GetParam();
    
    Vector2D vector(x, y);

    EXPECT_NEAR(vector.getAngle().getRadians(), radiansAngle, 1e-9);
    EXPECT_DOUBLE_EQ(vector.getMagnitude(), magnitude);
    EXPECT_DOUBLE_EQ(vector.getMagnitudeSquared(), magnitude*magnitude);
}

TEST_P(Vector2DTest, TestingSetPolar){
    auto [name, x, y, magnitude, radiansAngle] = GetParam();
    
    Vector2D vector(0, 0);
    vector.setPolar(magnitude, Angle(radiansAngle));

    EXPECT_NEAR(vector.x, x, 1e-9);
    EXPECT_NEAR(vector.y, y, 1e-9);
}

auto NameGen = [](const testing::TestParamInfo<TestData>& info) {
    return std::string(info.param.name);
};

INSTANTIATE_TEST_SUITE_P(Vector2DTests, Vector2DTest, testing::Values(
    TestData{"right",            1.0,  0.0, 1.0,       0.0},
    TestData{"up",               0.0,  1.0, 1.0,       PI/2},
    TestData{"left",            -1.0,  0.0, 1.0,       PI},
    TestData{"down",             0.0, -1.0, 1.0,      -PI/2},
    TestData{"pythagorean",      3.0,  4.0, 5.0,       atan2(4.0, 3.0)},
    TestData{"diagonal",         1.0,  1.0, sqrt(2.0), PI/4},
    TestData{"second_quadrant", -3.0,  4.0, 5.0,       atan2(4.0, -3.0)}
), NameGen);
