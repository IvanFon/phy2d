#include <catch2/catch.hpp>

#include "phy2d/Utils.hpp"

TEST_CASE("hypot function") {
  CHECK(phy::util::hypot(0, 0) == Approx(0));
  CHECK(phy::util::hypot(25, 60) == Approx(65));
  CHECK(phy::util::hypot(5.23, 111.11) == Approx(111.233021176));
  CHECK(phy::util::hypot(883, 54) == Approx(884.649648166));
}
