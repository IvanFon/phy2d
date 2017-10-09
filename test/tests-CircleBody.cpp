#include "catch.hpp"

#include "phy2d/CircleBody.hpp"

TEST_CASE("circle bodies can be created") {
    SECTION("default constructor") {
        phy::CircleBody a;
        REQUIRE(a.pos.x == Approx(0));
        REQUIRE(a.pos.y == Approx(0));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.radius == Approx(0));
        REQUIRE(a.mass == Approx(0));
    }
    SECTION("other constructors") {
        phy::CircleBody a(
            phy::Vector(12.345, -5432.1),
            922.7, 5.2);
        
        REQUIRE(a.pos.x == Approx(12.345));
        REQUIRE(a.pos.y == Approx(-5432.1));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.radius == Approx(922.7));
        REQUIRE(a.mass == Approx(5.2));
    }
    SECTION("type is correct") {
        phy::CircleBody a;
        REQUIRE(a.getType() == phy::RigidBody::Types::CIRCLE);
    }
}
