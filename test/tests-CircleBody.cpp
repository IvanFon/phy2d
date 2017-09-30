#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/CircleBody.hpp"

TEST_CASE("circle bodies can be created") {
    SECTION("default constructor") {
        phy::CircleBody a;
        REQUIRE(compare(a.pos.x, 0));
        REQUIRE(compare(a.pos.y, 0));
        REQUIRE(compare(a.vel.x, 0));
        REQUIRE(compare(a.vel.y, 0));
        REQUIRE(compare(a.radius, 0));
        REQUIRE(compare(a.mass, 0));
    }
    SECTION("other constructors") {
        phy::CircleBody a(
            phy::Vector(12.345, -5432.1),
            phy::Vector(-933.3566, 232.0),
            922.7, 5.2);
        
        REQUIRE(compare(a.pos.x, 12.345));
        REQUIRE(compare(a.pos.y, -5432.1));
        REQUIRE(compare(a.vel.x, -933.3566));
        REQUIRE(compare(a.vel.y, 232.0));
        REQUIRE(compare(a.radius, 922.7));
        REQUIRE(compare(a.mass, 5.2));
    }
    SECTION("type is correct") {
        phy::CircleBody a;
        REQUIRE(a.getType() == phy::RigidBody::Types::CIRCLE);
    }
}
