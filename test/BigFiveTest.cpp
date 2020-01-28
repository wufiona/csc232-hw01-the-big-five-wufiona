/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   BigFiveTest.cpp
 * @brief  Google Test implementation for unit testing a Point Big Five implementations.
 */

#include "BigFiveTest.h"

TEST_F(BigFiveTest, TestCopyConstructor) {
    const TwoDimensionalPoint& original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy{original};
    EXPECT_DOUBLE_EQ(original.GetX(), copy.GetX());
    EXPECT_DOUBLE_EQ(original.GetY(), copy.GetY());
}

TEST_F(BigFiveTest, TestCopyConstructorCreatesDistinctObject) {
    const TwoDimensionalPoint & original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy{original};
    EXPECT_NE(std::addressof(original), std::addressof(copy));
}

TEST_F(BigFiveTest, TestMoveConstructor) {
    TwoDimensionalPoint moved{std::move(TwoDimensionalPoint{POSITIVE_X_COORD, POSITIVE_Y_COORD})};
    EXPECT_DOUBLE_EQ(moved.GetX(), POSITIVE_X_COORD);
    EXPECT_DOUBLE_EQ(moved.GetY(), POSITIVE_Y_COORD);
}

TEST_F(BigFiveTest, TestMoveConstructorCreatesDistinctObject) {
    const TwoDimensionalPoint & original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy{std::move(TwoDimensionalPoint{POSITIVE_X_COORD, POSITIVE_Y_COORD})};
    EXPECT_NE(std::addressof(original), std::addressof(copy));
}

TEST_F(BigFiveTest, TestCopyAssignmentOperator) {
    TwoDimensionalPoint original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy;
    copy = original;
    EXPECT_DOUBLE_EQ(original.GetX(), copy.GetX());
    EXPECT_DOUBLE_EQ(original.GetY(), copy.GetY());
}

TEST_F(BigFiveTest, TestCopyAssignmentOperatorDifferentObjects) {
    TwoDimensionalPoint original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy;
    copy = original;
    EXPECT_NE(std::addressof(original), std::addressof(copy));
}

TEST_F(BigFiveTest, TestMoveAssignmentOperator) {
    TwoDimensionalPoint moved;
    moved = std::move(TwoDimensionalPoint{POSITIVE_X_COORD, POSITIVE_Y_COORD});
    EXPECT_DOUBLE_EQ(moved.GetX(), POSITIVE_X_COORD);
    EXPECT_DOUBLE_EQ(moved.GetY(), POSITIVE_Y_COORD);
}

TEST_F(BigFiveTest, TestMoveAssignmentOperatorDifferentObjects) {
    TwoDimensionalPoint original{POSITIVE_X_COORD, POSITIVE_Y_COORD};
    TwoDimensionalPoint copy;
    copy = std::move(original);
    EXPECT_NE(std::addressof(original), std::addressof(copy));
}
