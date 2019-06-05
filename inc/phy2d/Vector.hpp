/*
phy2d - A small, simple C++ physics library

Copyright (C) 2019 Ivan Fonseca

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

#include "Utils.hpp"

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
  Vector(const T &X, const T &Y) {
    x = X;
    y = Y;
  }

  /// @brief Set position
  /// @param X,Y Coordinates
  template <typename T>
  void setPos(const T &X, const T &Y) {
    x = X;
    y = Y;
  }

  /// @brief Get magnitude of vector
  /// @return Magnitude of vector
  double mag() {
    return hypot(x, y);
  }

  /// @brief Normalize vector
  /// @return Normalized vector
  Vector norm() {
    Vector vect(x / mag(), y / mag());
    return vect;
  }

  /// @brief Rotate vector
  /// @param theta Angle to rotate by
  /// @param centre Centre of rotation
  template <typename T>
  void rotate(const T theta, const Vector &centre) {
    double xx = (cos(theta) * (x - centre.x)) - (sin(theta) * (y - centre.y)) + centre.x;
    double yy = (sin(theta) * (x - centre.x)) + (cos(theta) * (y - centre.y)) + centre.y;
    x = xx;
    y = yy;
  }

  /// @brief Add a vector
  /// @param other The other vector to add
  /// @return Sum of the two vectors
  Vector operator+(const Vector &other) {
    return Vector(x + other.x, y + other.y);
  }

  /// @brief Add a number
  /// @param other The number to add
  /// @return Sum of vector and number
  template <typename T>
  Vector operator+(const T &other) {
    return Vector(x + other, y + other);
  }

  /// @brief Add and set vector
  /// @param other The vector being added
  /// @return Sum of this and other vector
  Vector &operator+=(const Vector &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  /// @brief Add and set vector and number
  /// @param other The number being added
  /// @return Sum of this vector and number
  template <typename T>
  Vector &operator+=(const T &other) {
    x += other;
    y += other;
    return *this;
  }

  /// @brief Subtract another vector
  /// @param other The other vector to subtract
  /// @return Difference of vectors
  Vector operator-(const Vector &other) {
    return Vector(x - other.x, y - other.y);
  }

  /// @brief Subtract a number from vector
  /// @param other The number to subtract
  /// @return Difference of vector and number
  template <typename T>
  Vector operator-(const T &other) {
    return Vector(x - other, y - other);
  }

  /// @brief Subtract from and set vector
  /// @param other The other vector being subtracted
  /// @return Difference of vector and number
  Vector &operator-=(const Vector &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  /// @brief Subtract from and set vector
  /// @param other The number to subtract
  /// @return Difference of vector and number
  template <typename T>
  Vector &operator-=(const T &other) {
    x -= other;
    y -= other;
    return *this;
  }

  /// @brief Multiply by another vector
  /// @param other The other vector to multiply by
  /// @return Product of vectors
  Vector operator*(const Vector &other) {
    return Vector(x * other.x, y * other.y);
  }

  /// @brief Multiply by a number
  /// @param other The number to multiply by
  /// @return Difference
  template <typename T>
  Vector operator*(const T &other) {
    return Vector(x * other, y * other);
  }

  /// @brief Multiply and set vector
  /// @param other THe other vector to multiply by
  /// @return Product of vectors
  Vector &operator*=(const Vector &other) {
    x *= other.x;
    y *= other.y;
    return *this;
  }

  /// @brief Multiply and set vector
  /// @param other The number to multiply by
  /// @return Product of vector and number
  template <typename T>
  Vector &operator*=(const T &other) {
    x *= other;
    y *= other;
    return *this;
  }

  /// @brief Divide by another vector
  /// @param other The other vector to divide by
  Vector operator/(const Vector &other) {
    return Vector(x / other.x, y / other.y);
  }

  /// @brief Divide by a number
  /// @param other The number to divide by
  /// @return Quotient
  template <typename T>
  Vector operator/(const T &other) {
    return Vector(x / other, y / other);
  }

  /// @brief Divide by and set vector
  /// @param other The other vector to divide by
  /// @return Quotient of vectors
  Vector &operator/=(const Vector &other) {
    x /= other.x;
    y /= other.y;
    return *this;
  }

  /// @brief Divide by and set vector
  /// @param other The number to divide by
  /// @return Quotient
  template <typename T>
  Vector &operator/=(const T &other) {
    x /= other;
    y /= other;
    return *this;
  }

  /// @brief Compare if equal to another vector
  /// @param other The other vector being compared
  /// @return true if equal, false otherwise
  bool operator==(const Vector &other) {
    return x == other.x && y == other.y;
  }

  /// @brief Compare if not equal to another vector
  /// @param other The other vector being compared
  /// @return true if not equal, false otherwise
  bool operator!=(const Vector &other) {
    return !(*this == other);
  }

  /// @brief Get distance between two vectors
  /// @param a,b Vectors to get distance between
  /// @return Distance between vectors
  static double dist(Vector a, Vector b) {
    return hypot(b.x - a.x, b.y - a.y);
  }

  /// @brief Cross product
  /// @param a,b Vectors
  /// @return Cross product
  static double cross(const Vector &a, const Vector &b) {
    return (a.x * b.y) - (a.y * b.x);
  }

  /// @{
  /// @brief Cross product
  /// @param a Vector
  /// @param b Scalar
  /// @return Cross product
  template <typename T>
  static Vector cross(const Vector &a, T b) {
    return Vector(b * a.y, -b * a.x);
  }
  template <typename T>
  static Vector cross(T b, const Vector &a) {
    return Vector(-b * a.y, b * a.x);
  }
  /// @}
};

}  // namespace phy

#endif  // INC_PHY2D_VECTOR_HPP_
