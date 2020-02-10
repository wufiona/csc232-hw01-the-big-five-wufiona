/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   Point.h
 * @brief  Specification of a Point ADT.
 */

#ifndef HW01_POINT_H
#define HW01_POINT_H

using length_unit = double;
using coordinate_unit = double;

/**
 * A Point Interface.
 */
class Point {
public:
    /**
     * Calculate the distance this Point is from the origin.
     * @return The distance this Point is from the origin is returned.
     */
    virtual length_unit DistanceFromOrigin() const = 0;

    /**
     * Calculate the distance this Point is from the given Point.
     * @param other another Point in the plane
     * @return The distance this Point is from the given Point is returned.
     */
    virtual length_unit DistanceFromPoint(const Point &other) const = 0;

    virtual ~Point() = default;
};

#endif //HW01_POINT_H
