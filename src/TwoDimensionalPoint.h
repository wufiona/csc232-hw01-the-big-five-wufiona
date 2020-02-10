/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   TwoDimensionalPoint.h
 * @brief  Specification of a TwoDimensionalPoint ADT.
 */

#ifndef HW01_TWODIMENSIONALPOINT_H
#define HW01_TWODIMENSIONALPOINT_H

#include "Point.h"

/**
 * An implementation of the Point interface in a two-dimensional plane.
 */
class TwoDimensionalPoint : public Point {
private:
    coordinate_unit *xcor;
    coordinate_unit *ycor;
public:
    /**
     * Default/initializing constructor.
     * @param x_coordinate the x-coordinate of this Point
     * @param y_coordinate the y-coordinate of this Point
     */
    explicit TwoDimensionalPoint(coordinate_unit x_coordinate = 0, coordinate_unit y_coordinate = 0);

    /* The Big Five */

    /**
     * Destructor responsible for deleting memory occupied by the coordinates of this Point.
     */
    ~TwoDimensionalPoint() override;

    /**
     * Copy constructor used to create a new Point with the same coordinates of the other Point.
     * @param other a Point used as a template for creating this point using copy semantics
     */
    TwoDimensionalPoint(const TwoDimensionalPoint &other);

    /**
     * Move constructor used to create a new Point with the same coordinates of the other Point.
     * @param other a Point used as a template for creating this point using move semantics
     */
    TwoDimensionalPoint(TwoDimensionalPoint &&other) noexcept;

    /**
     * Copy assignment operator used to create a new Point with the same coordinates as the other Point.
     * @param rhs an l-value; the right-hand side of the assignment statement lhs = rhs
     * @return A new Point with the same coordinates as the given (l-value) TwoDimensionalPoint is returned.
     */
    TwoDimensionalPoint &operator=(const TwoDimensionalPoint &rhs);

    /**
     * Move assignment operator used to create a new Point with the same coordinates as the other Point.
     * @param rhs an r-value; the right-hand side of the assignment statement TwoDimensionalPoint lhs = TwoDimensionalPoint{x, y}
     * @return A new Point with the same coordinates as the given (r-value) TwoDimensional Point is returned.
     */
    TwoDimensionalPoint &operator=(TwoDimensionalPoint &&rhs);

    /* Inherited Point behavior */

    /**
     * @copydoc Point::DistanceFromOrigin() const
     */
    length_unit DistanceFromOrigin() const override;

    /**
     * @copydoc Point::DistanceFromPoint(const Point &other) const
     */
    length_unit DistanceFromPoint(const Point &other) const override;

    /* Specific TwoDimensionalPoint behavior */

    /**
     * X-coordinate accessor method.
     * @return The x-coordinate of this Point is returned.
     */
    virtual length_unit GetX() const;

    /**
     * Y-coordinate accessor method.
     * @return The y-coordinate of this Point is returned.
     */
    virtual length_unit GetY() const;

    /**
     * Assess whether this Point is the origin.
     * @return True if this Point is the origin, otherwise false.
     */
    virtual bool IsOrigin() const;

    /**
     * Translates this Point by the given dimensions.
     * @param x the amount to translate in the x-direction
     * @param y the amount to translate in the y-direction
     */
    void Translate(coordinate_unit x = 0, coordinate_unit y = 0);
};


#endif //HW01_TWODIMENSIONALPOINT_H
