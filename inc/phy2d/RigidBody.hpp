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
    /// @brief Mass
    double mass;

    /// @brief Create rigid body at (0, 0) with mass of 0
    RigidBody() {
        pos.x = 0;
        pos.y = 0;
        mass = 0;
    }

    /// @brief Create rigid body at specified position with specified mass
    /// @param P Position
    /// @param M Mass
    template <typename T>
    RigidBody(Vector P, T M) {
        pos = P;
        mass = M;
    }

    /// @brief Create rigid body at specified position with mass 0
    /// @param P Position
    RigidBody(Vector P) {
        pos = P;
    }

    /// @brief Create rigid body at (0, 0) with specified mass
    /// @param M Mass
    template <typename T>
    RigidBody(T M) {
        mass = M;
    }
};

}  // namespace phy

#endif  // INC_PHY2D_RIGIDBODY_HPP_