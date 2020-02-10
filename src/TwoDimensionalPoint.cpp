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

TwoDimensionalPoint::TwoDimensionalPoint(coordinate_unit xcoor, coordinate_unit ycoor) {
    xcor = new coordinate_unit(xcoor);
    ycor = new coordinate_unit(ycoor);
}

TwoDimensionalPoint::~TwoDimensionalPoint() {
    delete xcor;
    delete ycor;
}

TwoDimensionalPoint::TwoDimensionalPoint(const TwoDimensionalPoint &other) {
    xcor = new coordinate_unit{*other.xcor};
    ycor = new coordinate_unit{*other.ycor};
}

TwoDimensionalPoint::TwoDimensionalPoint(TwoDimensionalPoint &&other) noexcept {
    xcor = other.xcor;
    ycor = other.ycor;
    other.xcor = nullptr;
    other.ycor = nullptr;
}

TwoDimensionalPoint &TwoDimensionalPoint::operator=(const TwoDimensionalPoint &rhs) {
    if (this !=&other) {
        *xcor = *rhs.xcor;
        *ycor = *rhs.ycor;
        return *this;
}

TwoDimensionalPoint &TwoDimensionalPoint::operator=(TwoDimensionalPoint &&rhs) {
    std :: swap(xcor, rhs.xcor);
    std :: swap (ycor, rhs.ycor);
    return *this;

length_unit TwoDimensionalPoint::DistanceFromOrigin() const {
    return static_cast<length_unit>(sqrt(((*xPtr) * (*xPtr) + (*yPtr) * (*yPtr))));
}

length_unit TwoDimensionalPoint::DistanceFromPoint(const Point &other) const {
    const TwoDimensionalPoint &rhs = dynamic_cast<const TwoDimensionalPoint&>(other);
    length_unit deltaX = (*rhs.xPtr) - *xPtr;
    length_unit deltaY = (*rhs.yPtr) - *xPtr;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

length_unit TwoDimensionalPoint::GetX() const {
    return *xcor;
}

length_unit TwoDimensionalPoint::GetY() const {
    return *ycor;
}

bool TwoDimensionalPoint::IsOrigin() const {
    return (*xcor == 0 && * ycor == 0);
}

void TwoDimensionalPoint::Translate(coordinate_unit x, coordinate_unit y) {
    *xcor += x;
    *ycor += y;
}
