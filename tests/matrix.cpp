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

TEST_CASE("Matrix transpose square", "[matrix]") {
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

TEST_CASE("Matrix transpose non-square", "[matrix]") {
  const Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
  });

  const Matrix FINAL = Matrix({{Complex(0.0f, 0.0f)}, {Complex(1.0f, 1.0f)}});

  Matrix mt = m.transpose();

  REQUIRE(mt == FINAL);
};

TEST_CASE("Matrix transpose inplace square", "[matrix]") {
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

TEST_CASE("Matrix transpose inplace non-square", "[matrix]") {
  Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
  });

  const Matrix FINAL = Matrix({{Complex(0.0f, 0.0f)}, {Complex(1.0f, 1.0f)}});

  m.transposeInplace();

  REQUIRE(m == FINAL);
};

// Hermitian

TEST_CASE("Matrix Hermitian conjugation square", "[matrix]") {
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

TEST_CASE("Matrix Hermitian conjugation non-square", "[matrix]") {
  const Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
  });

  const Matrix FINAL = Matrix({{Complex(0.0f, 0.0f)}, {Complex(1.0f, -1.0f)}});

  Matrix mt = m.hermitian();

  REQUIRE(mt == FINAL);
};

TEST_CASE("Matrix Hermitian conjugation inplace square", "[matrix]") {
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

TEST_CASE("Matrix Hermitian conjugation inplace non-square", "[matrix]") {
  Matrix m = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
  });

  const Matrix FINAL = Matrix({{Complex(0.0f, 0.0f)}, {Complex(1.0f, -1.0f)}});

  m.hermitianInplace();

  REQUIRE(m == FINAL);
};

// Multiply operations

TEST_CASE("Matrix multiplication", "[matrix]") {
  const Matrix m_a = Matrix({
      {Complex(1.0f, 2.0f), Complex(2.0f, 3.0f)},
      {Complex(3.0f, 1.0f), Complex(0.0f, 1.0f)}
  });

  const Matrix m_b = Matrix({
      {Complex(3.0f, 1.0f), Complex(1.0f, 2.0f)},
      {Complex(0.0f, 1.0f), Complex(2.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(-2.0f, 9.0f), Complex(-8.0f, 16.0f)},
      {Complex(7.0f,  6.0f), Complex(-2.0f, 9.0f) }
  });

  const Matrix m = m_a.multiply(m_b);

  REQUIRE(m == FINAL);
}

TEST_CASE("Matrix multiplication inplace", "[matrix]") {
  Matrix m_a = Matrix({
      {Complex(1.0f, 2.0f), Complex(2.0f, 3.0f)},
      {Complex(3.0f, 1.0f), Complex(0.0f, 1.0f)}
  });

  const Matrix m_b = Matrix({
      {Complex(3.0f, 1.0f), Complex(1.0f, 2.0f)},
      {Complex(0.0f, 1.0f), Complex(2.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(-2.0f, 9.0f), Complex(-8.0f, 16.0f)},
      {Complex(7.0f,  6.0f), Complex(-2.0f, 9.0f) }
  });

  m_a.multiplyInplace(m_b);

  REQUIRE(m_a == FINAL);
}

// Addition operations

TEST_CASE("Matrix add", "[matrix]") {
  const Matrix M_A = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix M_B = Matrix({
      {Complex(4.0f, 4.0f), Complex(5.0f, 5.0f)},
      {Complex(6.0f, 6.0f), Complex(7.0f, 7.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(4.0f, 4.0f), Complex(6.0f,  6.0f) },
      {Complex(8.0f, 8.0f), Complex(10.0f, 10.0f)}
  });

  Matrix m = M_A + M_B;

  REQUIRE(m == FINAL);
};

TEST_CASE("Matrix add-equals", "[matrix]") {
  Matrix m_a = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix m_b = Matrix({
      {Complex(4.0f, 4.0f), Complex(5.0f, 5.0f)},
      {Complex(6.0f, 6.0f), Complex(7.0f, 7.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(4.0f, 4.0f), Complex(6.0f,  6.0f) },
      {Complex(8.0f, 8.0f), Complex(10.0f, 10.0f)}
  });

  m_a += m_b;

  REQUIRE(m_a == FINAL);
};

// Subtraction operations

TEST_CASE("Matrix subtract", "[matrix]") {
  const Matrix M_A = Matrix({
      {Complex(4.0f, 4.0f), Complex(6.0f,  6.0f) },
      {Complex(8.0f, 8.0f), Complex(10.0f, 10.0f)}
  });

  const Matrix M_B = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(4.0f, 4.0f), Complex(5.0f, 5.0f)},
      {Complex(6.0f, 6.0f), Complex(7.0f, 7.0f)}
  });

  Matrix m = M_A - M_B;

  REQUIRE(m == FINAL);
};
TEST_CASE("Matrix subtract-equals", "[matrix]") {
  Matrix m_a = Matrix({
      {Complex(4.0f, 4.0f), Complex(6.0f,  6.0f) },
      {Complex(8.0f, 8.0f), Complex(10.0f, 10.0f)}
  });

  const Matrix m_b = Matrix({
      {Complex(0.0f, 0.0f), Complex(1.0f, 1.0f)},
      {Complex(2.0f, 2.0f), Complex(3.0f, 3.0f)}
  });

  const Matrix FINAL = Matrix({
      {Complex(4.0f, 4.0f), Complex(5.0f, 5.0f)},
      {Complex(6.0f, 6.0f), Complex(7.0f, 7.0f)}
  });

  m_a -= m_b;

  REQUIRE(m_a == FINAL);
};