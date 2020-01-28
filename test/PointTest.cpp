/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   PointTest.cpp
 * @brief  Google Test implementation for unit testing a Point implementation.
 */

#include "PointTest.h"

/* Test DistanceFromOrigin */

TEST_F(PointTest, TestDistanceFromOriginFromOrigin) {
    length_unit expected{ZERO};
    length_unit actual{origin->DistanceFromOrigin()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromOriginFromQuadI) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantI->DistanceFromOrigin()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromOriginFromQuadII) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantII->DistanceFromOrigin()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromOriginFromQuadIII) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantIII->DistanceFromOrigin()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromOriginFromQuadIV) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantIV->DistanceFromOrigin()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

/* Test DistanceFromPoint */


TEST_F(PointTest, TestDistanceFromPointFromOrigin) {
    length_unit expected{ZERO};
    length_unit actual{origin->DistanceFromPoint(*origin)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointFromQuadI) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantI->DistanceFromPoint(*origin)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointFromQuadII) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantII->DistanceFromPoint(*origin)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointFromQuadIII) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantIII->DistanceFromPoint(*origin)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointFromQuadIV) {
    length_unit expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantIV->DistanceFromPoint(*origin)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIAndIII) {
    length_unit expected{2 * EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantI->DistanceFromPoint(*quadrantIII)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIIAndIV) {
    length_unit expected{2 * EXPECTED_DISTANCE_FROM_ORIGIN};
    length_unit actual{quadrantII->DistanceFromPoint(*quadrantIV)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIAndII) {
    length_unit expected{2 * POSITIVE_X_COORD};
    length_unit actual{quadrantI->DistanceFromPoint(*quadrantII)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIIIAndIV) {
    length_unit expected{2 * POSITIVE_X_COORD};
    length_unit actual{quadrantIII->DistanceFromPoint(*quadrantIV)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIAndIV) {
    length_unit expected{2 * POSITIVE_Y_COORD};
    length_unit actual{quadrantI->DistanceFromPoint(*quadrantIV)};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(PointTest, TestDistanceFromPointAcrossQuadrantsIIAndIII) {
    length_unit expected{2 * POSITIVE_Y_COORD};
    length_unit actual{quadrantII->DistanceFromPoint(*quadrantIII)};
    EXPECT_DOUBLE_EQ(expected, actual);
}