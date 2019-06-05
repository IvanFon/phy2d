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
 * @file RigidBody.hpp
 * @brief Rigid body class
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_RIGIDBODY_HPP_
#define INC_PHY2D_RIGIDBODY_HPP_

#include "Vector.hpp"

namespace phy {

/// @brief Rigid body class
class RigidBody {
 public:
  /// @brief Position
  Vector pos;
  /// @brief Velocity
  Vector vel;
  /// @brief Mass
  double mass;
  /// @brief Acceleration during previous step
  Vector lastAcc;

  /// @brief Size of RectBody child class
  Vector size;

  /// @brief Radius of CircleBody child class
  double radius;

  /// @brief Types of child classes
  enum Types {
    /// @brief Base class
    BASE,
    /// @brief CircleBody
    CIRCLE,
    /// @brief RectBody
    RECT
  };

  /// @brief Create rigid body at (0, 0) with velocity 0 and mass of 0
  RigidBody() : pos(Vector(0, 0)), mass(0), vel(Vector(0, 0)), lastAcc(Vector(0, 0)) {
  }

  /// @brief Create rigid body with specified position and mass
  /// @param pos Position
  /// @param mass Mass
  template <typename T>
  RigidBody(Vector pos, T mass) : pos(pos), mass(mass), vel(Vector(0, 0)), lastAcc(Vector(0, 0)) {
  }

  /// @brief Get child class type
  virtual Types getType() {
    return Types::BASE;
  }

  /// @brief Checks for collision between two rigid bodies
  static bool collides(RigidBody &a, RigidBody &b) {
    // Two circle bodies
    if (a.getType() == Types::CIRCLE && b.getType() == Types::CIRCLE) {
      return (phy::Vector::dist(a.pos, b.pos) < (a.radius + b.radius));
    } else if (a.getType() == Types::RECT && b.getType() == Types::RECT) {
      return (a.pos.x < b.pos.x + b.size.x && a.pos.x + a.size.x > b.pos.x &&
              a.size.y + a.pos.y > b.pos.y);
    }

    /// @todo
    return false;
  }
};

}  // namespace phy

#endif  // INC_PHY2D_RIGIDBODY_HPP_
