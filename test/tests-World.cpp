#include "catch.hpp"

#include "phy2d/World.hpp"

TEST_CASE("worlds can be created") {
    SECTION("default constructor") {
        phy::World world;
        REQUIRE(world.size() == 0);
    }
}

TEST_CASE("bodies can be added to and retrieved from world") {
    SECTION("rigid bodies") {
        phy::RigidBody a;
        phy::RigidBody b(
            phy::Vector(-5.0, 9.020),
            2);
        phy::RigidBody c(
            phy::Vector(211.95, 2.0),
            3);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(world[0]->pos.x == Approx(0));
        REQUIRE(world[0]->pos.y == Approx(0));
        REQUIRE(world[0]->vel.x == Approx(0));
        REQUIRE(world[0]->vel.y == Approx(0));
        REQUIRE(world[0]->mass == Approx(0));

        REQUIRE(world[1]->pos.x == Approx(-5.0));
        REQUIRE(world[1]->pos.y == Approx(9.020));
        REQUIRE(world[1]->vel.x == Approx(0));
        REQUIRE(world[1]->vel.y == Approx(0));
        REQUIRE(world[1]->mass == Approx(2));

        REQUIRE(world[2]->pos.x == Approx(211.95));
        REQUIRE(world[2]->pos.y == Approx(2.0));
        REQUIRE(world[2]->vel.x == Approx(0));
        REQUIRE(world[2]->vel.y == Approx(0));
        REQUIRE(world[2]->mass == Approx(3));
    }
    SECTION("rectangular bodies") {
        phy::RectBody a;
        phy::RectBody b(
            phy::Vector(9, 5),
            phy::Vector(23.0, 9.3),
            2);
        phy::RectBody c(
            phy::Vector(-922.1, 333.33333),
            phy::Vector(9.4, 3.0),
            3.233);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(world[0]->pos.x == Approx(0));
        REQUIRE(world[0]->pos.y == Approx(0));
        REQUIRE(world[0]->vel.x == Approx(0));
        REQUIRE(world[0]->vel.y == Approx(0));
        REQUIRE(world[0]->size.x == Approx(0));
        REQUIRE(world[0]->size.y == Approx(0));
        REQUIRE(world[0]->mass == Approx(0));

        REQUIRE(world[1]->pos.x == Approx(9));
        REQUIRE(world[1]->pos.y == Approx(5));
        REQUIRE(world[1]->vel.x == Approx(0));
        REQUIRE(world[1]->vel.y == Approx(0));
        REQUIRE(world[1]->size.x == Approx(23.0));
        REQUIRE(world[1]->size.y == Approx(9.3));
        REQUIRE(world[1]->mass == Approx(2));

        REQUIRE(world[2]->pos.x == Approx(-922.1));
        REQUIRE(world[2]->pos.y == Approx(333.33333));
        REQUIRE(world[2]->vel.x == Approx(0));
        REQUIRE(world[2]->vel.y == Approx(0));
        REQUIRE(world[2]->size.x == Approx(9.4));
        REQUIRE(world[2]->size.y == Approx(3.0));
        REQUIRE(world[2]->mass == Approx(3.233));
    }
    SECTION("circular bodies") {
        phy::CircleBody a;
        phy::CircleBody b(
            phy::Vector(-4.0, 12.23),
            10,
            4);
        phy::CircleBody c(
            phy::Vector(1.0, -1.0),
            52,
            9.66);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(world[0]->pos.x == Approx(0));
        REQUIRE(world[0]->pos.y == Approx(0));
        REQUIRE(world[0]->vel.x == Approx(0));
        REQUIRE(world[0]->vel.y == Approx(0));
        REQUIRE(world[0]->radius == Approx(0));
        REQUIRE(world[0]->mass == Approx(0));

        REQUIRE(world[1]->pos.x == Approx(-4.0));
        REQUIRE(world[1]->pos.y == Approx(12.23));
        REQUIRE(world[1]->vel.x == Approx(0));
        REQUIRE(world[1]->vel.y == Approx(0));
        REQUIRE(world[1]->radius == Approx(10));
        REQUIRE(world[1]->mass == Approx(4));

        REQUIRE(world[2]->pos.x == Approx(1.0));
        REQUIRE(world[2]->pos.y == Approx(-1.0));
        REQUIRE(world[2]->vel.x == Approx(0));
        REQUIRE(world[2]->vel.y == Approx(0));
        REQUIRE(world[2]->radius == Approx(52));
        REQUIRE(world[2]->mass == Approx(9.66));
    }
}

TEST_CASE("get index of bodies") {
    phy::World world;

    // In world
    phy::RectBody a;
    phy::CircleBody b;
    phy::RectBody c;
    phy::CircleBody d;
    phy::CircleBody e;
    phy::RectBody f;
    // Not in world
    phy::CircleBody g;
    phy::RectBody h;

    world.add(a);
    world.add(b);
    world.add(c);
    world.add(d);
    world.add(e);
    world.add(f);

    REQUIRE(world.size() == 6);

    SECTION("in world") {
        CHECK(world.indexOf(a) == 0);
        CHECK(world.indexOf(b) == 1);
        CHECK(world.indexOf(c) == 2);
        CHECK(world.indexOf(d) == 3);
        CHECK(world.indexOf(e) == 4);
        CHECK(world.indexOf(f) == 5);
    }

    SECTION("not in world") {
        CHECK(world.indexOf(g) == -1);
        CHECK(world.indexOf(h) == -1);
    }
}

TEST_CASE("bodies can be deleted") {
    phy::World world;

    phy::RectBody a;
    phy::CircleBody b;
    phy::RectBody c;
    phy::CircleBody d;
    phy::CircleBody e;
    phy::RectBody f;

    world.add(a);
    world.add(b);
    world.add(c);
    world.add(d);
    world.add(e);
    world.add(f);

    REQUIRE(world.size() == 6);

    SECTION("by index") {
        world.removeBody(3);
        world.removeBody(1);
    
        REQUIRE(world.size() == 4);
        REQUIRE(world[0] == &a);
        REQUIRE(world[1] == &c);
        REQUIRE(world[2] == &e);
        REQUIRE(world[3] == &f);
    }
    SECTION("by reference") {
        world.removeBody(d);
        world.removeBody(b);

        REQUIRE(world.size() == 4);
        REQUIRE(world[0] == &a);
        REQUIRE(world[1] == &c);
        REQUIRE(world[2] == &e);
        REQUIRE(world[3] == &f);
    }
}

TEST_CASE("change world settings") {
    phy::World world;

    SECTION("gravity") {
        REQUIRE(world.gravity == false);
        world.set(phy::World::Settings::GRAVITY, true);
        REQUIRE(world.gravity == true);
        world.set(phy::World::Settings::GRAVITY, false);
        REQUIRE(world.gravity == false);
    }
}
