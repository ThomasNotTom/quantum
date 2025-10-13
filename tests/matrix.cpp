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