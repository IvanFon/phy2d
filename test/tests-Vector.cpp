#include "catch.hpp"

#include "phy2d/Vector.hpp"

TEST_CASE("vectors can be created") {
    SECTION("default constructor") {
        phy::Vector a;
        REQUIRE(a.x == Approx(0));
        REQUIRE(a.y == Approx(0));
    }
    SECTION("integer coordinates") {
        phy::Vector a(0, 0);
        REQUIRE(a.x == Approx(0));
        REQUIRE(a.y == Approx(0));

        phy::Vector b(5, -10);
        REQUIRE(b.x == Approx(5));
        REQUIRE(b.y == Approx(-10));
        
        phy::Vector c(3, 7);
        REQUIRE(c.x == Approx(3));
        REQUIRE(c.y == Approx(7));

        phy::Vector d(-10, -5);
        REQUIRE(d.x == Approx(-10));
        REQUIRE(d.y == Approx(-5));
    }
    SECTION("floating point coordinates") {
        phy::Vector a(92.145, 13.44);
        REQUIRE(a.x == Approx(92.145));
        REQUIRE(a.y == Approx(13.44));

        phy::Vector b(12.3, -9.2);
        REQUIRE(b.x == Approx(12.3));
        REQUIRE(b.y == Approx(-9.2));

        phy::Vector c(-8.3, 4.0);
        REQUIRE(c.x == Approx(-8.3));
        REQUIRE(c.y == Approx(4.0));

        phy::Vector d(-12.22, -99.7000);
        REQUIRE(d.x == Approx(-12.22));
        REQUIRE(d.y == Approx(-99.7000));
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
        CHECK(res.x == Approx(-4547.4775));
        CHECK(res.y == Approx(9.23));

        res = res + 5.22;
        CHECK(res.x == Approx(-4547.4775 + 5.22));
        CHECK(res.y == Approx(9.23 + 5.22));

        res += 2;
        CHECK(res.x == Approx(-4547.4775 + 5.22 + 2));
        CHECK(res.y == Approx(9.23 + 5.22 + 2));

        phy::Vector c;
        c += phy::Vector(92.3, -22.0);
        CHECK(c.x == Approx(92.3));
        CHECK(c.y == Approx(-22.0));
    }
    SECTION("subtraction") {
        phy::Vector a(-8.9436, 92.88);
        phy::Vector b(41.001, 77.2);
        phy::Vector res = a - b;
        CHECK(res.x == Approx(-49.9446));
        CHECK(res.y == Approx(15.68));

        res = res - 9;
        CHECK(res.x == Approx(-49.9446 - 9));
        CHECK(res.y == Approx(15.68 - 9));

        res -= 4.21;
        CHECK(res.x == Approx(-49.9446 - 9 - 4.21));
        CHECK(res.y == Approx(15.68 - 9 - 4.21));

        phy::Vector c;
        c -= phy::Vector(4, 2);
        CHECK(c.x == Approx(-4));
        CHECK(c.y == Approx(-2));
    }
    SECTION("multiplication") {
        phy::Vector a(-9222.756, 884.2);
        phy::Vector b(-2.12, 37.9);
        phy::Vector res = a * b;
        CHECK(res.x == Approx(19552.24272));
        CHECK(res.y == Approx(33511.18));

        res = res * 93.12;
        CHECK(res.x == Approx(19552.24272 * 93.12));
        CHECK(res.y == Approx(33511.18 * 93.12));

        res *= -3;
        CHECK(res.x == Approx(19552.24272 * 93.12 * -3));
        CHECK(res.y == Approx(33511.18 * 93.12 * -3));

        phy::Vector c;
        c *= phy::Vector(1.3, 3.7);
        CHECK(c.x == Approx(0));
        CHECK(c.y == Approx(0));
    }
    SECTION("division") {
        phy::Vector a(22.37, -9.0);
        phy::Vector b(-2.0, 335.42);
        phy::Vector res = a / b;
        CHECK(res.x == Approx(-11.185));
        CHECK(res.y == Approx(-0.026832031));

        res = res / 9.20012;
        CHECK(res.x == Approx(-11.185 / 9.20012));
        CHECK(res.y == Approx(-0.026832031 / 9.20012));

        res /= 49;
        CHECK(res.x == Approx(-11.185 / 9.20012 / 49));
        CHECK(res.y == Approx(-0.026832031 / 9.20012 / 49));

        phy::Vector c;
        c /= phy::Vector(44.543, 547.2);
        CHECK(c.x == Approx(0));
        CHECK(c.y == Approx(0));
    }
    SECTION("comparison") {
        phy::Vector aa;
        phy::Vector ab;

        phy::Vector ba(-92.1, 84.7);
        phy::Vector bb(-92.1, 84.7);

        phy::Vector ca(2444.5, -1.001);
        phy::Vector cb(2444.5, -1.001);

        SECTION("equal") {
            CHECK(aa == ab);
            CHECK(ba == bb);
            CHECK(ca == cb);
            CHECK_FALSE(aa == ba);
            CHECK_FALSE(cb == ab);
            CHECK_FALSE(ca == bb);
        }
        SECTION("not equal") {
            CHECK(aa != ba);
            CHECK(cb != ab);
            CHECK(ca != bb);
            CHECK_FALSE(aa != ab);
            CHECK_FALSE(ba != bb);
            CHECK_FALSE(ca != cb);
        }
    }
}

TEST_CASE("changing vector position") {
    phy::Vector a(0, 0);

    a.setPos(5, -9);
    CHECK(a.x == Approx(5));
    CHECK(a.y == Approx(-9));

    a.setPos(-9912.5633, 100294.001);
    CHECK(a.x == Approx(-9912.5633));
    CHECK(a.y == Approx(100294.001));

    a.setPos(0.0, 454.11188424);
    CHECK(a.x == Approx(0.0));
    CHECK(a.y == Approx(454.11188424));
}

TEST_CASE("getting vector magnitude") {
    phy::Vector a(0, 0);
    CHECK(a.mag() == Approx(0));

    phy::Vector b(443.9, -123.223);
    // Compare is weird here
    CHECK(b.mag() == Approx(460.6854867792125));

    phy::Vector c(-22.0, 411.111);
    CHECK(c.mag() == Approx(411.69922798203055));
}

TEST_CASE("find distance between two vectors") {
    phy::Vector a1(0, 0);
    phy::Vector a2(0, 0);
    CHECK(phy::Vector::dist(a1, a2) == Approx(0));

    phy::Vector b1(0, 0);
    phy::Vector b2(432.54, -922.3);
    // Compare, still being weird
    CHECK(phy::Vector::dist(b1, b2) == Approx(1018.6894235241672));

    phy::Vector c1(4.0, -111.2211);
    phy::Vector c2(-442.32, -122.3);
    CHECK(phy::Vector::dist(c1, c2) == Approx(446.4574833343148));
}

TEST_CASE("normalize vectors") {
    phy::Vector a(4, 12);
    phy::Vector resa = a.norm();
    CHECK(resa.x == Approx(0.316228032));
    CHECK(resa.y == Approx(0.948684096));

    phy::Vector b(221.42, 42.24242);
    phy::Vector resb = b.norm();
    CHECK(resb.x == Approx(0.98228367));
    CHECK(resb.y == Approx(0.18739969));

    phy::Vector c(1.22, 9.81);
    phy::Vector resc = c.norm();
    CHECK(resc.x == Approx(0.123411831));
    CHECK(resc.y == Approx(0.992352513));
}

TEST_CASE("cross product") {
    REQUIRE(phy::Vector::cross(
        phy::Vector(0, 0),
        phy::Vector(0, 0)) == Approx(0));
    REQUIRE(phy::Vector::cross(
        phy::Vector(5, 6),
        phy::Vector(10, 9)) == Approx(-15));
    REQUIRE(phy::Vector::cross(
        phy::Vector(-11.0, 6.57),
        phy::Vector(42.42, 0.0)) == Approx(-278.699));
}
