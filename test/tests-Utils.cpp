#include "catch.hpp"

#include "utils.cpp"

#include "phy2d/Utils.hpp"

TEST_CASE("hypot function") {
    CHECK(compare(phy::util::hypot(0, 0), 0));
    CHECK(compare(phy::util::hypot(25, 60), 65));
    CHECK(compare(phy::util::hypot(5.23, 111.11), 111.233021176));
    CHECK(compare(phy::util::hypot(883, 54), 884.649648166));
}
