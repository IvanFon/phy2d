#include <catch2/catch.hpp>

#include "phy2d/RectBody.hpp"

TEST_CASE("rectangle bodies can be created") {
    SECTION("default constructor") {
        phy::RectBody a;
        REQUIRE(a.pos.x == Approx(0));
        REQUIRE(a.pos.y == Approx(0));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.size.x == Approx(0));
        REQUIRE(a.size.y == Approx(0));
        REQUIRE(a.mass == Approx(0));
    }
    SECTION("other constructors") {
        phy::RectBody a(
            phy::Vector(12.345, -5432.1),
            phy::Vector(32.12, 43.653),
            5.2);
        REQUIRE(a.pos.x == Approx(12.345));
        REQUIRE(a.pos.y == Approx(-5432.1));
        REQUIRE(a.vel.x == Approx(0));
        REQUIRE(a.vel.y == Approx(0));
        REQUIRE(a.size.x == Approx(32.12));
        REQUIRE(a.size.y == Approx(43.653));
        REQUIRE(a.mass == Approx(5.2));
    }
    SECTION("type is correct") {
        phy::RectBody a;
        REQUIRE(a.getType() == phy::RigidBody::Types::RECT);
    }
}
