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

#include <cmath>
#include <functional>
#include <vector>

#include "Vector.hpp"
#include "RigidBody.hpp"
#include "RectBody.hpp"
#include "CircleBody.hpp"
#include "Forces.hpp"

namespace phy {

/// @brief Physics world class
class World {
 public:
    /// @brief List of bodies in worldz
    std::vector<RigidBody *> bodies;

    /// @brief Settings for world
    enum Settings {
        // @brief Gravity
        GRAVITY,
        /// @brief Collisions
        COLLIDE
    };

    /// @{
    /// @brief World settings
    bool gravity;
    bool collide;
    /// @}

    /// @brief Create empty world
    World(): gravity(false), collide(false) { }

    /// @brief Access bodies in world
    /// @param index Index of item to access
    /// @return Item
    auto operator[](int index) {
        return bodies[index];
    }

    /// @brief Get number of bodies in world
    /// @return Number of bodies in world
    int size() {
        return bodies.size();
    }

    /// @brief Get index of a body in the world
    /// @param body Body to get index of
    /// @return Index of body, -1 if not found
    int indexOf(const RigidBody &body) {
        // Search bodies
        for (int i = 0; i < bodies.size(); i++) {
            if (bodies[i] == &body) {
                return i;
            }
        }

        // Not found
        return -1;
    }

    /// @brief Add rigid body to world
    /// @param body The rigid body to add
    void add(RigidBody &body) {
        bodies.push_back(&body);
    }

    /// @brief Remove body from world by index
    /// @param index Index of body to remove
    void removeBody(int index) {
        bodies.erase(bodies.begin() + index);
    }

    /// @brief Remove a body from the world
    /// @param body Body to remove
    void removeBody(const RigidBody &body) {
        bodies.erase(bodies.begin() + indexOf(body));
    }

    /// @brief Change a setting
    /// @param setting Setting to change
    /// @param value New setting value
    void set(Settings setting, bool value) {
        switch (setting) {
            case GRAVITY:
                gravity = value;
                break;
            case COLLIDE:
                collide = value;
                break;
        }
    }

    /// @brief Move the world forwards
    /// @param dt Time step to move by in seconds
    void step(double dt) {
        // Bodies to remove
        std::vector<phy::RigidBody *> toRemove;
        // Loop through bodies
        int i = 0;
        for (auto body : bodies) {
            /* Here we use Velocity Verlet integration instead
             * of the more common Euler integration. This gives
             * us more accuracy and not much added complexity.
             * If performance becomes an issue, this can be changed.
             */

            // Move body
            /* doing this first means we use the current
             * frame's position to calculate the new forces
             */
            body->pos += body->vel * dt + (body->lastAcc * 0.5 * pow(dt, 2));

            // Total acceleration this timestep
            Vector totalAcc;

            // Add forces
            // Settings that need to loop through other bodies
            if (gravity || collide) {
                int n = 0;
                for (auto other : bodies) {
                    // Check if this isn't the same body
                    if (i != n) {
                        if (gravity) {
                            totalAcc += phy::forces::gravity(*body, *other);
                        }
                        if (collide) {
                            if (phy::RigidBody::collides(*body, *other)) {
                                toRemove.push_back(body);
                            }
                        }
                    }

                    // Increment counter
                    n++;
                }
            }

            // Average acceleration
            Vector avgAcc = (body->lastAcc + totalAcc) / 2;
            // Set velocity
            body->vel += avgAcc * dt;
            // Save acceleration
            body->lastAcc = avgAcc;

            // Increment counter
            i++;
        }

        // Remove bodies
        for (auto body : toRemove) {
            this->removeBody(*body);
        }
    }
};

}  // namespace phy

#endif  // INC_PHY2D_WORLD_HPP_
