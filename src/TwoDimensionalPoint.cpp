/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   TwoDimensionalPoint.cpp
 * @brief  Implementation of a TwoDimensionalPoint ADT.
 */

#include <algorithm>
#include <cmath>
#include "TwoDimensionalPoint.h"

TwoDimensionalPoint::TwoDimensionalPoint(coordinate_unit x_coordinate, coordinate_unit y_coordinate) {
    // TODO: Add an appropriate initializer list
}

TwoDimensionalPoint::~TwoDimensionalPoint() {
    // TODO: Delete appropriate data members
}

TwoDimensionalPoint::TwoDimensionalPoint(const TwoDimensionalPoint &other) {
    // TODO: Add an appropriate initializer list
}

TwoDimensionalPoint::TwoDimensionalPoint(TwoDimensionalPoint &&other) noexcept {
    // TODO: Add an appropriate initializer list and appropriate body
}

TwoDimensionalPoint &TwoDimensionalPoint::operator=(const TwoDimensionalPoint &rhs) {
    // TODO: Add any appropriate code
    return *this;
}

TwoDimensionalPoint &TwoDimensionalPoint::operator=(TwoDimensionalPoint &&rhs) {
    // TODO: Add any appropriate code
    return *this;
}

length_unit TwoDimensionalPoint::DistanceFromOrigin() const {
    // TODO: Calculate and return the correct value
    return 0;
}

length_unit TwoDimensionalPoint::DistanceFromPoint(const Point &other) const {
    // TODO: Calculate and return the correct value
    return 0;
}

length_unit TwoDimensionalPoint::GetX() const {
    // TODO: Return the appropriate value
    return 0;
}

length_unit TwoDimensionalPoint::GetY() const {
    // TODO: Return the appropriate value
    return 0;
}

bool TwoDimensionalPoint::IsOrigin() const {
    // TODO Return the correct value
    return false;
}

void TwoDimensionalPoint::Translate(coordinate_unit x, coordinate_unit y) {
    // TODO: Implement me
}