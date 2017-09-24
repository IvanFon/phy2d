#include "catch.hpp"

#include "utils.cpp"

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
        phy::RigidBody b(phy::Vector(-5.0, 9.020), 2);
        phy::RigidBody c(phy::Vector(211.95, 2.0), 3);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(compare(world[0]->pos.x, 0));
        REQUIRE(compare(world[0]->pos.y, 0));
        REQUIRE(compare(world[0]->mass, 0));

        REQUIRE(compare(world[1]->pos.x, -5.0));
        REQUIRE(compare(world[1]->pos.y, 9.020));
        REQUIRE(compare(world[1]->mass, 2));

        REQUIRE(compare(world[2]->pos.x, 211.95));
        REQUIRE(compare(world[2]->pos.y, 2.0));
        REQUIRE(compare(world[2]->mass, 3));
    }
    SECTION("rectangular bodies") {
        phy::RectBody a;
        phy::RectBody b(phy::Vector(9, 5), phy::Vector(23.0, 9.3), 2);
        phy::RectBody c(phy::Vector(-922.1, 333.33333), phy::Vector(9.4, 3.0), 3.233);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(compare(world[0]->pos.x, 0));
        REQUIRE(compare(world[0]->pos.y, 0));
        REQUIRE(compare(world[0]->size.x, 0));
        REQUIRE(compare(world[0]->size.y, 0));
        REQUIRE(compare(world[0]->mass, 0));

        REQUIRE(compare(world[1]->pos.x, 9));
        REQUIRE(compare(world[1]->pos.y, 5));
        REQUIRE(compare(world[1]->size.x, 23.0));
        REQUIRE(compare(world[1]->size.y, 9.3));
        REQUIRE(compare(world[1]->mass, 2));

        REQUIRE(compare(world[2]->pos.x, -922.1));
        REQUIRE(compare(world[2]->pos.y, 333.33333));
        REQUIRE(compare(world[2]->size.x, 9.4));
        REQUIRE(compare(world[2]->size.y, 3.0));
        REQUIRE(compare(world[2]->mass, 3.233));
    }
    SECTION("circular bodies") {
        phy::CircleBody a;
        phy::CircleBody b(phy::Vector(-4.0, 12.23), 10, 4);
        phy::CircleBody c(phy::Vector(1.0, -1.0), 52, 9.66);

        phy::World world;
        world.add(a);
        world.add(b);
        world.add(c);

        REQUIRE(world.size() == 3);

        REQUIRE(compare(world[0]->pos.x, 0));
        REQUIRE(compare(world[0]->pos.y, 0));
        REQUIRE(compare(world[0]->radius, 0));
        REQUIRE(compare(world[0]->mass, 0));

        REQUIRE(compare(world[1]->pos.x, -4.0));
        REQUIRE(compare(world[1]->pos.y, 12.23));
        REQUIRE(compare(world[1]->radius, 10));
        REQUIRE(compare(world[1]->mass, 4));

        REQUIRE(compare(world[2]->pos.x, 1.0));
        REQUIRE(compare(world[2]->pos.y, -1.0));
        REQUIRE(compare(world[2]->radius, 52));
        REQUIRE(compare(world[2]->mass, 9.66));
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

    world.removeBody(3);
    world.removeBody(1);

    REQUIRE(world.size() == 4);
}
