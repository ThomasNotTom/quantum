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
  float imaginary = c.getImaginary();
  REQUIRE(imaginary == FINAL_B);
}

TEST_CASE("Complex add operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_B = 5.0f;
  const float IMAGINARY_B = 7.0f;

  const float REAL_FINAL = REAL_A + REAL_B;
  const float IMAGINARY_FINAL = IMAGINARY_A + IMAGINARY_B;

  const Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);

  const Complex c_final = c_a + c_b;

  float real = c_final.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_final.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
}

TEST_CASE("Complex add-equals operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_B = 5.0f;
  const float IMAGINARY_B = 7.0f;

  const float REAL_FINAL = REAL_A + REAL_B;
  const float IMAGINARY_FINAL = IMAGINARY_A + IMAGINARY_B;

  Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);

  c_a += c_b;

  float real = c_a.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_a.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
}

TEST_CASE("Complex subtract operator", "[complex]") {
  const float REAL_A = 10.0f;
  const float IMAGINARY_A = 7.0f;

  const float REAL_B = 3.0f;
  const float IMAGINARY_B = 2.0f;

  const float REAL_FINAL = REAL_A - REAL_B;
  const float IMAGINARY_FINAL = IMAGINARY_A - IMAGINARY_B;

  const Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);

  const Complex c_final = c_a - c_b;

  float real = c_final.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_final.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
}

TEST_CASE("Complex subtract-equals operator", "[complex]") {
  const float REAL_A = 10.0f;
  const float IMAGINARY_A = 7.0f;

  const float REAL_B = 3.0f;
  const float IMAGINARY_B = 2.0f;

  const float REAL_FINAL = REAL_A - REAL_B;
  const float IMAGINARY_FINAL = IMAGINARY_A - IMAGINARY_B;

  Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);

  c_a -= c_b;

  float real = c_a.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_a.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
}