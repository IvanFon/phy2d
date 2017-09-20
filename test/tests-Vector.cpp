#include "catch.hpp"

#include "phy2d/Vector.hpp"

/// @todo Write a function to compare floats & doubles

TEST_CASE("can create vectors") {
    SECTION("integer coordinates") {
        phy::Vector test1(0, 0);
        REQUIRE(test1.x == 0);
        REQUIRE(test1.y == 0);

        phy::Vector test2(5, -10);
        REQUIRE(test2.x == 5);
        REQUIRE(test2.y == -10);
        
        phy::Vector test3(3, 7);
        REQUIRE(test3.x == 3);
        REQUIRE(test3.y == 7);

        phy::Vector test4(-10, -5);
        REQUIRE(test4.x == -10);
        REQUIRE(test4.y == -5);
    }
    SECTION("floating point coordinates") {
        phy::Vector test1(92.145, 13.44);
        REQUIRE(test1.x == 92.145);
        REQUIRE(test1.y == 13.44);

        phy::Vector test2(12.3, -9.2);
        REQUIRE(test2.x == 12.3);
        REQUIRE(test2.y == -9.2);

        phy::Vector test3(-8.3, 4.0);
        REQUIRE(test3.x == -8.3);
        REQUIRE(test3.y == 4.0);

        phy::Vector test4(-12.22, -99.7000);
        REQUIRE(test4.x == -12.22);
        REQUIRE(test4.y == -99.7000);
    }
}
