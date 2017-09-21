/*
phy2d - A small, simple C++ physics library

Copyright (C) 2017 Ivan Fonseca

phy2d is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

phy2d is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with phy2d.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file Vector.hpp
 * @brief 2D vector class
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_VECTOR_HPP_
#define INC_PHY2D_VECTOR_HPP_

#include <cmath>

namespace phy {

/// @brief 2D vector class
class Vector {
 public:
    /// @{
    /// @brief Coordinates of vector
    double x, y;
    /// @}

    /// @brief Creates a vector at (0, 0)
    Vector() {
        x = 0;
        y = 0;
    }

    /// @brief Creates vector at coordinates
    /// @param X,Y Coordinates
    template <typename T>
    Vector(T X, T Y) {
        x = X;
        y = Y;
    }

    /// @brief Set position
    /// @param X X position
    /// @param Y Y position
    template <typename T>
    void setPos(T X, T Y) {
        x = X;
        y = Y;
    }

    /// @brief Get magnitude of vector
    /// @return Magnitude of vector
    double mag() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    /// @brief Add to another vector
    /// @param other The other vector to add
    Vector operator+(Vector other) {
        Vector vect(0, 0);
        vect.x = x + other.x;
        vect.y = y + other.y;
        return vect;
    }

    /// @brief Subtract from another vector
    /// @param other The other vector to subtract from
    Vector operator-(Vector other) {
        Vector vect(0, 0);
        vect.x = x - other.x;
        vect.y = y - other.y;
        return vect;
    }

    /// @brief Multiply by another vector
    /// @param other The other vector to multiply by
    Vector operator*(Vector other) {
        Vector vect(0, 0);
        vect.x = x * other.x;
        vect.y = y * other.y;
        return vect;
    }

    /// @brief Divide by another vector
    /// @param other The other vector to divide by
    Vector operator/(Vector other) {
        Vector vect(0, 0);
        vect.x = x / other.x;
        vect.y = y / other.y;
        return vect;
    }

    /// @brief Get distance between two vectors
    /// @param a,b Vectors to get distance between
    /// @return Distance between vectors
    static double dist(Vector a, Vector b) {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }
};

}  // namespace phy

#endif  // INC_PHY2D_VECTOR_HPP_
