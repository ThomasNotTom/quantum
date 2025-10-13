#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include "../src/complex/complex.hpp"

TEST_CASE("Complex get with no arguments to constructor", "[complex]") {
  Complex c;
  float real, imaginary;
  real = c.getReal();
  REQUIRE(real == 0.0f);
  imaginary = c.getImaginary();
  REQUIRE(imaginary == 0.0f);
}