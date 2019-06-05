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
 * @file Utils.hpp
 * @brief Assorted useful functions
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_UTILS_HPP_
#define INC_PHY2D_UTILS_HPP_

#include <cmath>

namespace phy {

namespace util {

/// @brief Calculate hypotenuse of a right triangle
/// @param a Length of side a
/// @param b Length of side b
/// @return Length of hypotenuse
template <typename T>
double hypot(T a, T b) {
  return sqrt(pow(a, 2) + pow(b, 2));
}

}  // namespace util

}  // namespace phy

#endif  // INC_PHY2D_UTILS_HPP_
