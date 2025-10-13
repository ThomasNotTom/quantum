#include <catch2/catch_test_macros.hpp>

#include "../src/matrix/matrix.hpp"

TEST_CASE("Matrix get with no default value", "[matrix]") {
  Matrix m = Matrix(1, 1);
  Complex value = m.get(0, 0);
  REQUIRE(value == Complex(0.0f, 0.0f));
};

TEST_CASE("Matrix get with default value", "[matrix]") {
  const Complex def = Complex(2.0f, 3.0f);

  Matrix m = Matrix(1, 1, def);
  Complex value = m.get(0, 0);
  REQUIRE(value == def);
};

TEST_CASE("Matrix get with value list", "[matrix]") {
  const Complex def = Complex(2.0f, 3.0f);

  std::vector<std::vector<Complex>> values = {{def}};

  Matrix m = Matrix(values);
  Complex value = m.get(0, 0);
  REQUIRE(value == def);
};

TEST_CASE("Matrix set", "[matrix]") {
  const Complex def = Complex(2.0f, 3.0f);

  Matrix m = Matrix(1, 1);
  m.set(0, 0, def);
  Complex value = m.get(0, 0);
  REQUIRE(value == def);
};

// Conjugate

TEST_CASE("Matrix conjugate", "[matrix]") {
  const Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f),  Complex(1.0f, -1.0f)},
      {Complex(2.0f, -2.0f), Complex(3.0f, -3.0f)}
  });

  Matrix mt = m.conjugate();

  REQUIRE(mt == FINAL);
};

TEST_CASE("Matrix conjugate inplace", "[matrix]") {
  Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f),  Complex(1.0f, -1.0f)},
      {Complex(2.0f, -2.0f), Complex(3.0f, -3.0f)}
  });

  m.conjugateInplace();

  REQUIRE(m == FINAL);
};

// Transpose

TEST_CASE("Matrix transpose", "[matrix]") {
  const Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f), Complex(2.0f, 2.0f)},
      {Complex(1.0f, 1.0f), Complex(3.0f, 3.0f)}
  });

  Matrix mt = m.transpose();

  REQUIRE(mt == FINAL);
};

TEST_CASE("Matrix transpose inplace", "[matrix]") {
  Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f), Complex(2.0f, 2.0f)},
      {Complex(1.0f, 1.0f), Complex(3.0f, 3.0f)}
  });

  m.transposeInplace();

  REQUIRE(m == FINAL);
};

// Hermitian

TEST_CASE("Matrix Hermitian conjugation", "[matrix]") {
  const Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f),  Complex(2.0f, -2.0f)},
      {Complex(1.0f, -1.0f), Complex(3.0f, -3.0f)}
  });

  Matrix mt = m.hermitian();

  REQUIRE(mt == FINAL);
};

TEST_CASE("Matrix Hermitian conjugation inplace", "[matrix]") {
  Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(0.0f, 0.0f),  Complex(2.0f, -2.0f)},
      {Complex(1.0f, -1.0f), Complex(3.0f, -3.0f)}
  });

  m.hermitianInplace();

  REQUIRE(m == FINAL);
};