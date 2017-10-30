#include "catch.hpp"

#include <iostream>

#include "phy2d/Forces.hpp"

#include "phy2d/RigidBody.hpp"
#include "phy2d/Vector.hpp"

TEST_CASE("gravitational acceleration") {
    SECTION("same mass") {
        phy::RigidBody a(phy::Vector(0, 0), 20);
        phy::RigidBody b(phy::Vector(10, 0), 20);

        phy::Vector accelA = phy::forces::gravity(a, b);
        REQUIRE(accelA.x == Approx(0));
        REQUIRE(accelA.y == Approx(1.335e-11));

        phy::Vector accelB = phy::forces::gravity(b, a);
        REQUIRE(accelA.x == Approx(0));
        REQUIRE(accelA.y == Approx(-1.335e-11));
    }
    SECTION("different masses") {
        phy::RigidBody a(phy::Vector(0.0, 822.23), 543.221);
        phy::RigidBody b(phy::Vector(0, 0), 9898.9777);
    
        phy::Vector accelA = phy::forces::gravity(a, b);
        REQUIRE(accelA.x == Approx(-9.771e-13));
        REQUIRE(accelA.y == Approx(0));

        phy::Vector accelB = phy::forces::gravity(b, a);
        REQUIRE(accelB.x == Approx(9.771e-13));
        REQUIRE(accelB.y == Approx(0));
    }
}
