#include <catch2/catch_test_macros.hpp>

#include "../src/polar/polar.hpp"

#include "../src/complex/complex.hpp"

const float ERROR_THRESHOLD = 0.001;
const float SQRT2_OVER_2 = sqrtf(2.0f) / 2.0f;

// Modulus

TEST_CASE("Polar modulus from horizontal complex", "[polar]") {
  Polar p = Polar(Complex(1.0f, 0.0f));
  REQUIRE((1.0f - p.getModulus()) < ERROR_THRESHOLD);
};

TEST_CASE("Polar modulus from angled complex", "[polar]") {
  Polar p = Polar(Complex(SQRT2_OVER_2, SQRT2_OVER_2));
  REQUIRE(abs(1.0f - p.getModulus()) < ERROR_THRESHOLD);
};

// Argument

TEST_CASE("Polar argument from horizontal complex", "[polar]") {
  Polar p = Polar(Complex(1.0f, 0.0f));
  REQUIRE(p.getArgument().getRadians() < ERROR_THRESHOLD);
};

TEST_CASE("Polar argument from angled complex", "[polar]") {
  Polar p = Polar(Complex(SQRT2_OVER_2, SQRT2_OVER_2));
  REQUIRE(abs((M_PI / 4) - p.getArgument().getRadians()) < ERROR_THRESHOLD);
};
