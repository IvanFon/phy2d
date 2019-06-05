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
 * @file Forces.hpp
 * @brief Physics forces
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_FORCES_HPP_
#define INC_PHY2D_FORCES_HPP_

#include <cmath>

#include "Constants.hpp"
#include "RigidBody.hpp"
#include "Vector.hpp"

namespace phy {

namespace forces {

/// @brief Calculate gravitational acceleration between two bodies
/// @param a,b The rigid bodies to calculate gravity between
/// @return Gravitational acceleration for a
inline Vector gravity(const RigidBody &a, const RigidBody &b) {
  // Calculate gravitational force
  double fg = (constants::GRAVITY * a.mass * b.mass) / pow(Vector::dist(a.pos, b.pos), 2);

  // Calculate acceleration
  double ag = fg / a.mass;

  // Angle between objects
  double theta = atan2(b.pos.y - a.pos.y, b.pos.x - a.pos.x);

  // Return acceleration
  return Vector(sin(theta) * ag, cos(theta) * ag);
}

}  // namespace forces

}  // namespace phy

#endif  // INC_PHY2D_FORCES_HPP_
