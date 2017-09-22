#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/RigidBody.hpp"

TEST_CASE("rigid bodies can be created") {
    SECTION("default contructor") {
        phy::RigidBody a;
        REQUIRE(compare(a.pos.x, 0));
        REQUIRE(compare(a.pos.y, 0));
        REQUIRE(compare(a.mass, 0));
    }
    SECTION("other contructors") {
        phy::RigidBody a(phy::Vector(4.7, -51.2), 5.2);
        REQUIRE(compare(a.pos.x, 4.7));
        REQUIRE(compare(a.pos.y, -51.2));
        REQUIRE(compare(a.mass, 5.2));

        phy::RigidBody b(phy::Vector(-221.0, 22.1200));
        REQUIRE(compare(b.pos.x, -221.0));
        REQUIRE(compare(b.pos.y, 22.1200));
        REQUIRE(compare(b.mass, 0));

        phy::RigidBody c(10.897);
        REQUIRE(compare(c.mass, 10.897));
    }
}
