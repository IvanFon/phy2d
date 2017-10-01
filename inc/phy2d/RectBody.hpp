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
 * @file RectBody.hpp
 * @brief Rectangular rigid body class
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_RECTBODY_HPP_
#define INC_PHY2D_RECTBODY_HPP_

#include "Vector.hpp"
#include "RigidBody.hpp"

namespace phy {

/// @brief Rectangular rigid body class
class RectBody: public RigidBody {
 public:
    /// @brief Create body at (0, 0) with velocity 0, size (0, 0) and mass 0
    RectBody(): RigidBody() {
        this->size = Vector(0, 0);
    }

    /// @brief Create body with specified position, velocity, size and mass
    /// @param pos Position
    /// @param size Size
    /// @param mass Mass
    template <typename T>
    RectBody(Vector pos, Vector size, T mass):
        RigidBody(pos, mass) {
        this->size = size;
    }

    /// @brief Get my type
    Types getType() {
        return RECT;
    }
};

}  // namespace phy

#endif  // INC_PHY2D_RECTBODY_HPP_
