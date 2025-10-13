#include <catch2/catch_test_macros.hpp>

#include "../src/complex/complex.hpp"

#include <cstdint>

// Getters, setters and adders

const float ERROR_THRESHOLD = 0.001;

TEST_CASE("Complex get with no arguments to constructor", "[complex]") {
  Complex c;
  float real, imaginary;
  real = c.getReal();
  REQUIRE(real == 0.0f);
  imaginary = c.getImaginary();
  REQUIRE(imaginary == 0.0f);
};

TEST_CASE("Complex get with real argument to constructor", "[complex]") {
  const float REAL_A = 2.0f;

  const float IMAGINARY_FINAL = 0.0f;

  Complex c = Complex(REAL_A);
  float real, imaginary;
  real = c.getReal();
  REQUIRE(real == REAL_A);
  imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex get with arguments to constructor", "[complex]") {
  const float A = 2.0f;
  const float B = 3.0f;

  Complex c = Complex(A, B);
  float real, imaginary;
  real = c.getReal();
  REQUIRE(real == A);
  imaginary = c.getImaginary();
  REQUIRE(imaginary == B);
};

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
};

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
};

// Conjugation

TEST_CASE("Complex conjugation", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_FINAL = REAL_A;
  const float IMAGINARY_FINAL = IMAGINARY_A * -1;

  const Complex c = Complex(REAL_A, IMAGINARY_A).conjugate();

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex conjugation inplace", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_FINAL = REAL_A;
  const float IMAGINARY_FINAL = IMAGINARY_A * -1;

  Complex c = Complex(REAL_A, IMAGINARY_A);
  c.conjugateInplace();

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

// Modulus operations

TEST_CASE("Complex modulus squared", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float FINAL = (REAL_A * REAL_A) + (IMAGINARY_A * IMAGINARY_A);

  const Complex c = Complex(REAL_A, IMAGINARY_A);

  float modSquared = c.modulusSquared();

  REQUIRE(modSquared == FINAL);
};

TEST_CASE("Complex modulus", "[complex]") {
  const float REAL_A = 3.0f;
  const float IMAGINARY_A = 4.0f;

  const float FINAL = sqrtf((REAL_A * REAL_A) + (IMAGINARY_A * IMAGINARY_A));

  const Complex c = Complex(REAL_A, IMAGINARY_A);

  float modSquared = c.modulus();

  REQUIRE(modSquared == FINAL);
};

// Normalize operations

TEST_CASE("Complex normalization", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const Complex c = Complex(REAL_A, IMAGINARY_A);
  const Complex c_norm = c.normalize();

  REQUIRE(abs(1 - c_norm.modulus()) < ERROR_THRESHOLD);
}

TEST_CASE("Complex normalization inplace", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  Complex c = Complex(REAL_A, IMAGINARY_A);
  c.normalizeInplace();

  REQUIRE(abs(1 - c.modulus()) < ERROR_THRESHOLD);
}

// Addition operators

TEST_CASE("Complex-complex add operator", "[complex]") {
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
};

TEST_CASE("Complex-complex add-equals operator", "[complex]") {
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
};

TEST_CASE("Complex-real add operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float K = 5.0f;

  const float REAL_FINAL = REAL_A + K;
  const float IMAGINARY_FINAL = IMAGINARY_A;

  const Complex c = Complex(REAL_A, IMAGINARY_A) + K;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-real add-equals operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float K = 5.0f;

  const float REAL_FINAL = REAL_A + K;
  const float IMAGINARY_FINAL = IMAGINARY_A;

  Complex c = Complex(REAL_A, IMAGINARY_A);

  c += K;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

// Subtraction operators

TEST_CASE("Complex-complex subtract operator", "[complex]") {
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
};

TEST_CASE("Complex-complex subtract-equals operator", "[complex]") {
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
};

TEST_CASE("Complex-real subtract operator", "[complex]") {
  const float REAL_A = 10.0f;
  const float IMAGINARY_A = 7.0f;

  const float K = 5.0f;

  const float REAL_FINAL = REAL_A - K;
  const float IMAGINARY_FINAL = IMAGINARY_A;

  const Complex c = Complex(REAL_A, IMAGINARY_A) - K;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-real subtract-equals operator", "[complex]") {
  const float REAL_A = 10.0f;
  const float IMAGINARY_A = 7.0f;

  const float K = 5.0f;

  const float REAL_FINAL = REAL_A - K;
  const float IMAGINARY_FINAL = IMAGINARY_A;

  Complex c = Complex(REAL_A, IMAGINARY_A);

  c -= K;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

// Muliplication operators

TEST_CASE("Complex-real multiplication operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float k = 5.0f;

  const float REAL_FINAL = REAL_A * k;
  const float IMAGINARY_FINAL = IMAGINARY_A * k;

  const Complex c = Complex(REAL_A, IMAGINARY_A) * k;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-real multiplication-equals operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float k = 5.0f;

  const float REAL_FINAL = REAL_A * k;
  const float IMAGINARY_FINAL = IMAGINARY_A * k;

  Complex c = Complex(REAL_A, IMAGINARY_A);
  c *= k;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-complex multiplication operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_B = 5.0f;
  const float IMAGINARY_B = 7.0f;

  const float REAL_FINAL = (REAL_A * REAL_B) - (IMAGINARY_A * IMAGINARY_B);
  const float IMAGINARY_FINAL = (REAL_A * IMAGINARY_B) + (IMAGINARY_A * REAL_B);

  const Complex c = Complex(REAL_A, IMAGINARY_A) * Complex(REAL_B, IMAGINARY_B);

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-complex multiplication-equals operator", "[complex]") {
  const float REAL_A = 2.0f;
  const float IMAGINARY_A = 3.0f;

  const float REAL_B = 5.0f;
  const float IMAGINARY_B = 7.0f;

  const float REAL_FINAL = (REAL_A * REAL_B) - (IMAGINARY_A * IMAGINARY_B);
  const float IMAGINARY_FINAL = (REAL_A * IMAGINARY_B) + (REAL_B * IMAGINARY_A);

  Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);
  c_a *= c_b;

  float real = c_a.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_a.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

// Division operators

TEST_CASE("Complex-real division operator", "[complex]") {
  const float REAL_A = 15.0f;
  const float IMAGINARY_A = 10.0f;

  const float k = 5.0f;

  const float REAL_FINAL = REAL_A / k;
  const float IMAGINARY_FINAL = IMAGINARY_A / k;

  const Complex c = Complex(REAL_A, IMAGINARY_A) / k;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-real division-equals operator", "[complex]") {
  const float REAL_A = 15.0f;
  const float IMAGINARY_A = 10.0f;

  const float k = 5.0f;

  const float REAL_FINAL = REAL_A / k;
  const float IMAGINARY_FINAL = IMAGINARY_A / k;

  Complex c = Complex(REAL_A, IMAGINARY_A);
  c /= k;

  float real = c.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};

TEST_CASE("Complex-complex division operator", "[complex]") {
  const float REAL_A = 1.0f;
  const float IMAGINARY_A = 1.0f;

  const float REAL_B = 1.0f;
  const float IMAGINARY_B = -1.0f;

  const float DIVISOR = (REAL_B * REAL_B) + (IMAGINARY_B * IMAGINARY_B);
  const float REAL_FINAL =
      ((REAL_A * REAL_B) + (IMAGINARY_A * IMAGINARY_B)) / DIVISOR;
  const float IMAGINARY_FINAL =
      ((IMAGINARY_A * REAL_B) - (REAL_A * IMAGINARY_B)) / DIVISOR;

  Complex c_a = Complex(REAL_A, IMAGINARY_A);
  const Complex c_b = Complex(REAL_B, IMAGINARY_B);

  c_a /= c_b;

  float real = c_a.getReal();
  REQUIRE(real == REAL_FINAL);

  float imaginary = c_a.getImaginary();
  REQUIRE(imaginary == IMAGINARY_FINAL);
};