#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/RectBody.hpp"

TEST_CASE("rectangle bodies can be created") {
    SECTION("default constructor") {
        phy::RectBody a;
        REQUIRE(compare(a.pos.x, 0));
        REQUIRE(compare(a.pos.y, 0));
        REQUIRE(compare(a.size.x, 0));
        REQUIRE(compare(a.size.y, 0));
        REQUIRE(compare(a.mass, 0));
    }
    SECTION("other constructors") {
        phy::RectBody a(
            phy::Vector(12.345, -5432.1),
            phy::Vector(32.12, 43.653),
            5.2);
        
        REQUIRE(compare(a.pos.x, 12.345));
        REQUIRE(compare(a.pos.y, -5432.1));
        REQUIRE(compare(a.size.x, 32.12));
        REQUIRE(compare(a.size.y, 43.653));
        REQUIRE(compare(a.mass, 5.2));
    }
}
