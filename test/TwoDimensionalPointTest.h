/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   TwoDimensionalPointTest.h
 * @brief  Google Test specification for unit testing the TwoDimensionalPoint class.
 */

#ifndef HW01_TWO_DIMENSIONAL_POINT_TEST_H
#define HW01_TWO_DIMENSIONAL_POINT_TEST_H

#include "gtest/gtest.h"
#include "Point.h"
#include "TwoDimensionalPoint.h"

namespace {
    class TwoDimensionalPointTest : public ::testing::Test {
    protected:
        TwoDimensionalPointTest() {
            // You can do set-up work for each test here...
        }

        ~TwoDimensionalPointTest() override {
            // You can do clean-up work that doesn't throw exceptions here...
        }

        void SetUp() override {
            // Code here will be called immediately after the constructor
            // right before each test...
            origin = new TwoDimensionalPoint{};
            quadrantI = new TwoDimensionalPoint{POSITIVE_X_COORD, POSITIVE_Y_COORD};
            quadrantII = new TwoDimensionalPoint{NEGATIVE_X_COORD, POSITIVE_Y_COORD};
            quadrantIII = new TwoDimensionalPoint{NEGATIVE_X_COORD, NEGATIVE_Y_COORD};
            quadrantIV = new TwoDimensionalPoint{POSITIVE_X_COORD, NEGATIVE_Y_COORD};
        }

        void TearDown() override {
            // Code here will be called immediately after each test
            // right before the destructor...
            delete origin;
            delete quadrantI;
            delete quadrantII;
            delete quadrantIII;
            delete quadrantIV;
        }

        // Objects declared here can be used by all tests in the test suite
        Point *origin;
        Point *quadrantI;
        Point *quadrantII;
        Point *quadrantIII;
        Point *quadrantIV;
        static constexpr length_unit EXPECTED_DISTANCE_FROM_ORIGIN{5};
        static constexpr length_unit POSITIVE_Y_COORD{4};
        static constexpr length_unit POSITIVE_X_COORD{3};
        static constexpr length_unit ZERO{0};
        static constexpr length_unit NEGATIVE_X_COORD{-3};
        static constexpr length_unit NEGATIVE_Y_COORD{-4};
    };
}


#endif //HW01_TWO_DIMENSIONAL_POINT_TEST_H
