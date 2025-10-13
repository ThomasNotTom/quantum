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

TEST_CASE("Complex get with arguments to constructor", "[complex]") {
  const float A = 2.0f;
  const float B = 3.0f;

  Complex c = Complex(A, B);
  float real, imaginary;
  real = c.getReal();
  REQUIRE(real == A);
  imaginary = c.getImaginary();
  REQUIRE(imaginary == B);
}