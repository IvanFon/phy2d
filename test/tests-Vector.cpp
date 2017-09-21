#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/Vector.hpp"

TEST_CASE("vectors can be created") {
    SECTION("default constructor") {
        phy::Vector a;
        REQUIRE(compare(a.x, 0));
        REQUIRE(compare(a.y, 0));
    }
    SECTION("integer coordinates") {
        phy::Vector a(0, 0);
        REQUIRE(compare(a.x, 0));
        REQUIRE(compare(a.y, 0));

        phy::Vector b(5, -10);
        REQUIRE(compare(b.x, 5));
        REQUIRE(compare(b.y, -10));
        
        phy::Vector c(3, 7);
        REQUIRE(compare(c.x, 3));
        REQUIRE(compare(c.y, 7));

        phy::Vector d(-10, -5);
        REQUIRE(compare(d.x, -10));
        REQUIRE(compare(d.y, -5));
    }
    SECTION("floating point coordinates") {
        phy::Vector a(92.145, 13.44);
        REQUIRE(compare(a.x, 92.145));
        REQUIRE(compare(a.y, 13.44));

        phy::Vector b(12.3, -9.2);
        REQUIRE(compare(b.x, 12.3));
        REQUIRE(compare(b.y, -9.2));

        phy::Vector c(-8.3, 4.0);
        REQUIRE(compare(c.x, -8.3));
        REQUIRE(compare(c.y, 4.0));

        phy::Vector d(-12.22, -99.7000);
        REQUIRE(compare(d.x, -12.22));
        REQUIRE(compare(d.y, -99.7000));
    }
}

/**
 * @todo these check's should probably be require's,
 * everything will break if they fail
 */

TEST_CASE("using overloaded operators") {
    SECTION("addition") {
        phy::Vector a(7.3, 6.23);
        phy::Vector b(-4554.777500, 3.0);
        phy::Vector res = a + b;
        CHECK(compare(res.x, -4547.4775));
        CHECK(compare(res.y, 9.23));
    }
    SECTION("subtraction") {
        phy::Vector a(-8.9436, 92.88);
        phy::Vector b(41.001, 77.2);
        phy::Vector res = a - b;
        CHECK(compare(res.x, -49.9446));
        CHECK(compare(res.y, 15.68));
    }
    SECTION("multiplication") {
        phy::Vector a(-9222.756, 884.2);
        phy::Vector b(-2.12, 37.9);
        phy::Vector res = a * b;
        CHECK(compare(res.x, 19552.24272));
        CHECK(compare(res.y, 33511.18));
    }
    SECTION("division") {
        phy::Vector a(22.37, -9.0);
        phy::Vector b(-2.0, 335.42);
        phy::Vector res = a / b;
        CHECK(compare(res.x, -11.185));
        CHECK(compare(res.y, -0.026832031));
    }
}

TEST_CASE("changing vector position") {
    phy::Vector a(0, 0);

    a.setPos(5, -9);
    CHECK(compare(a.x, 5));
    CHECK(compare(a.y, -9));

    a.setPos(-9912.5633, 100294.001);
    CHECK(compare(a.x, -9912.5633));
    CHECK(compare(a.y, 100294.001));

    a.setPos(0.0, 454.11188424);
    CHECK(compare(a.x, 0.0));
    CHECK(compare(a.y, 454.11188424));
}

TEST_CASE("getting vector magnitude") {
    phy::Vector a(0, 0);
    CHECK(compare(a.mag(), 0));

    phy::Vector b(443.9, -123.223);
    // Compare is weird here
    CHECK(compare(b.mag(), sqrt(pow(b.x, 2) + pow(b.y, 2))));

    phy::Vector c(-22.0, 411.111);
    CHECK(compare(c.mag(), sqrt(pow(c.x, 2) + pow(c.y, 2))));
}

TEST_CASE("find distance between two vectors") {
    phy::Vector a1(0, 0);
    phy::Vector a2(0, 0);
    CHECK(compare(phy::Vector::dist(a1, a2), 0));

    phy::Vector b1(0, 0);
    phy::Vector b2(432.54, -922.3);
    // Compare, still being weird
    CHECK(compare(phy::Vector::dist(b1, b2), sqrt(pow(b2.x - b1.x, 2) + pow(b2.y - b1.y, 2))));

    phy::Vector c1(4.0, -111.2211);
    phy::Vector c2(-442.32, -122.3);
    CHECK(compare(phy::Vector::dist(c1, c2), sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2))));
}

TEST_CASE("normalize vectors") {
    phy::Vector a(4, 12);
    phy::Vector resa = a.norm();
    CHECK(compare(resa.x, 0.316228032));
    CHECK(compare(resa.y, 0.948684096));

    phy::Vector b(221.42, 42.24242);
    phy::Vector resb = b.norm();
    CHECK(compare(resb.x, 0.98228367));
    CHECK(compare(resb.y, 0.18739969));

    phy::Vector c(1.22, 9.81);
    phy::Vector resc = c.norm();
    CHECK(compare(resc.x, 0.123411831));
    CHECK(compare(resc.y, 0.992352513));
}
