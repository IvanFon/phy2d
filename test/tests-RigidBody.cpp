#include <catch2/catch.hpp>

#include "phy2d/RigidBody.hpp"

#include "phy2d/CircleBody.hpp"
#include "phy2d/RectBody.hpp"
#include "phy2d/Vector.hpp"

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
    phy::RigidBody a(phy::Vector(4.7, -51.2), 5.2);
    REQUIRE(a.pos.x == Approx(4.7));
    REQUIRE(a.pos.y == Approx(-51.2));
    REQUIRE(a.vel.x == Approx(0));
    REQUIRE(a.vel.y == Approx(0));
    REQUIRE(a.mass == Approx(5.2));
  }
  SECTION("type is correct") {
    phy::RigidBody a;
    REQUIRE(a.getType() == phy::RigidBody::Types::BASE);
  }
}

TEST_CASE("bodies can be collided") {
  SECTION("two circle bodies") {
    phy::CircleBody a(phy::Vector(0, 0), 5, 10);
    phy::CircleBody b(phy::Vector(5, 5), 5, 10);
    REQUIRE(phy::RigidBody::collides(a, b));

    phy::CircleBody c(phy::Vector(10, 10), 5, 10);
    REQUIRE_FALSE(phy::RigidBody::collides(a, c));
  }

  SECTION("two rectangle bodies") {
    phy::RectBody a(phy::Vector(5, 5), phy::Vector(50, 50), 10);
    phy::RectBody b(phy::Vector(20, 10), phy::Vector(10, 10), 10);
    REQUIRE(phy::RigidBody::collides(a, b));

    phy::RectBody c(phy::Vector(5, 40), phy::Vector(15, 15), 10);
    REQUIRE_FALSE(phy::RigidBody::collides(b, c));
  }
}
