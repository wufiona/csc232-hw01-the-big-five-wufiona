/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   TwoDimensionalPointTest.cpp
 * @brief  Google Test implementation for unit testing the TwoDimensionalPoint class.
 */

#include "TwoDimensionalPointTest.h"

/* Test Constructors */

TEST_F(TwoDimensionalPointTest, OriginXCoordIsZero) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    length_unit expected{ZERO};
    length_unit actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, OriginYCoordIsZero) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    length_unit expected{ZERO};
    length_unit actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIXCoordIsPositive) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantI);
    length_unit expected{POSITIVE_X_COORD};
    length_unit actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIYCoordIsPositive) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantI);
    length_unit expected{POSITIVE_Y_COORD};
    length_unit actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIIXCoordIsNegative) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantII);
    length_unit expected{NEGATIVE_X_COORD};
    length_unit actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIIYCoordIsPositive) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantII);
    length_unit expected{POSITIVE_Y_COORD};
    length_unit actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIIIXCoordIsNegative) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIII);
    length_unit expected{NEGATIVE_X_COORD};
    length_unit actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIIIYCoordIsNegative) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIII);
    length_unit expected{NEGATIVE_Y_COORD};
    length_unit actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIVXCoordIsPositive) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIV);
    length_unit expected{POSITIVE_X_COORD};
    length_unit actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, QuadIVYCoordIsNegative) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIV);
    length_unit expected{NEGATIVE_Y_COORD};
    length_unit actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

/* Test IsOrigin */

TEST_F(TwoDimensionalPointTest, DefaultPointIsOrigin) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    EXPECT_TRUE(point->IsOrigin());
}

TEST_F(TwoDimensionalPointTest, QuadrantIIsNotOrigin) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantI);
    EXPECT_FALSE(point->IsOrigin());
}

TEST_F(TwoDimensionalPointTest, QuadrantIIIsNotOrigin) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantII);
    EXPECT_FALSE(point->IsOrigin());
}

TEST_F(TwoDimensionalPointTest, QuadrantIIIIsNotOrigin) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIII);
    EXPECT_FALSE(point->IsOrigin());
}

TEST_F(TwoDimensionalPointTest, QuadrantIVIsNotOrigin) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(quadrantIV);
    EXPECT_FALSE(point->IsOrigin());
}

/* Test Translate */

TEST_F(TwoDimensionalPointTest, TranslateZeroTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate();
    auto expected{ZERO};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateXTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(EXPECTED_DISTANCE_FROM_ORIGIN);
    auto expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateYTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(ZERO, EXPECTED_DISTANCE_FROM_ORIGIN);
    auto expected{EXPECTED_DISTANCE_FROM_ORIGIN};
    auto actual{point->GetY()};
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateXPosYPosTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(POSITIVE_X_COORD, POSITIVE_Y_COORD);
    auto expected{POSITIVE_X_COORD};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
    expected = POSITIVE_Y_COORD;
    actual = point->GetY();
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateXPosYNegTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(POSITIVE_X_COORD, NEGATIVE_Y_COORD);
    auto expected{POSITIVE_X_COORD};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
    expected = NEGATIVE_Y_COORD;
    actual = point->GetY();
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateXNegYPosTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(NEGATIVE_X_COORD, POSITIVE_Y_COORD);
    auto expected{NEGATIVE_X_COORD};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
    expected = POSITIVE_Y_COORD;
    actual = point->GetY();
    EXPECT_DOUBLE_EQ(expected, actual);
}

TEST_F(TwoDimensionalPointTest, TranslateXNegYNegTest) {
    auto point = dynamic_cast<TwoDimensionalPoint*>(origin);
    point->Translate(NEGATIVE_X_COORD, NEGATIVE_Y_COORD);
    auto expected{NEGATIVE_X_COORD};
    auto actual{point->GetX()};
    EXPECT_DOUBLE_EQ(expected, actual);
    expected = NEGATIVE_Y_COORD;
    actual = point->GetY();
    EXPECT_DOUBLE_EQ(expected, actual);
}