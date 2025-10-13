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

TEST_CASE("Complex setter", "[complex]") {
  const float A = 2.0f;
  const float B = 3.0f;

  Complex c;

  c.setReal(A);
  float real = c.getReal();
  REQUIRE(real == A);

  c.setImaginary(B);
  float imaginary = c.getImaginary();
  REQUIRE(imaginary == B);
}

TEST_CASE("Complex adder", "[complex]") {
  const float A = 2.0f;
  const float DELTA_A = 4.0f;
  const float FINAL_A = A + DELTA_A;

  const float B = 3.0f;
  const float DELTA_B = 5.0f;
  const float FINAL_B = B + DELTA_B;

  Complex c = Complex(A, B);

  c.addReal(DELTA_A);
  float real = c.getReal();
  REQUIRE(real == FINAL_A);

  c.addImaginary(DELTA_B);
  float real = c.getReal();
  REQUIRE(real == FINAL_B);
}