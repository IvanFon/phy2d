#include "catch.hpp"

#include "phy2d/RigidBody.hpp"

TEST_CASE("rigid bodies can be created") {
    SECTION("default contructor") {
        phy::RigidBody a;
        REQUIRE(a.pos.x == Approx(0));
        REQUIRE(a.pos.y == Approx(0));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.mass == Approx(0));
    }
    SECTION("other contructors") {
        phy::RigidBody a(
            phy::Vector(4.7, -51.2),
            5.2);
        REQUIRE(a.pos.x == Approx(4.7));
        REQUIRE(a.pos.y == Approx(-51.2));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.mass == Approx(5.2));
    }
}
