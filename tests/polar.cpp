#include <catch2/catch_test_macros.hpp>

#include "../src/polar/polar.hpp"

#include "../src/complex/complex.hpp"

const float ERROR_THRESHOLD = 0.001;

// Argument

TEST_CASE("Polar from horizontal complex", "[polar]") {
  Polar p = Polar(Complex(1.0f, 0.0f));
  REQUIRE(p.getArgument().getRadians() < ERROR_THRESHOLD);
};

TEST_CASE("Polar from angled complex", "[polar]") {
  Polar p = Polar(Complex(1.4142f, 1.4142f));
  REQUIRE(abs((M_PI / 4) - p.getArgument().getRadians()) < ERROR_THRESHOLD);
};
