#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/RigidBody.hpp"

TEST_CASE("rigid bodies can be created") {
    SECTION("default contructor") {
        phy::RigidBody a;
        REQUIRE(compare(a.pos.x, 0));
        REQUIRE(compare(a.pos.y, 0));
        REQUIRE(compare(a.vel.x, 0));
        REQUIRE(compare(a.vel.y, 0));
        REQUIRE(compare(a.mass, 0));
    }
    SECTION("other contructors") {
        phy::RigidBody a(
            phy::Vector(4.7, -51.2),
            phy::Vector(55.3, 12.0),
            5.2);
        REQUIRE(compare(a.pos.x, 4.7));
        REQUIRE(compare(a.pos.y, -51.2));
        REQUIRE(compare(a.vel.x, 55.3));
        REQUIRE(compare(a.vel.y, 12.0));
        REQUIRE(compare(a.mass, 5.2));
    }
}
