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
 * @file World.hpp
 * @brief Physics world class
 * @author Ivan Fonseca
 * @copyright GPL-3.0
 */

#ifndef INC_PHY2D_WORLD_HPP_
#define INC_PHY2D_WORLD_HPP_

#include <functional>
#include <vector>

#include "Vector.hpp"
#include "RigidBody.hpp"
#include "RectBody.hpp"
#include "CircleBody.hpp"

namespace phy {

/// @brief Physics world class
class World {
 public:
    /// @brief List of bodies in worldz
    std::vector<RigidBody *> bodies;

    /// @brief Create empty world
    World() { }

    /// @brief Add rigid body to world
    /// @param body The rigid body to add
    void add(RigidBody &body) {  /* NOLINT(runtime/references) */
        bodies.push_back(&body);
    }

    /// @brief Get number of bodies in world
    /// @return Number of bodies in world
    int size() {
        return bodies.size();
    }

    /// @brief Access bodies in world
    /// @param index Index of item to access
    /// @return Item
    auto operator[](int index) {
        return bodies[index];
    }

    /// @brief Remove body from world
    /// @param index Index of body to remove
    void removeBody(int index) {
        bodies.erase(bodies.begin() + index);
    }
};

}  // namespace phy

#endif  // INC_PHY2D_WORLD_HPP_
