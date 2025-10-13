#pragma once

#include <vector>

#include "../complex/complex.hpp"

class Matrix {
private:
  std::vector<std::vector<Complex>> values;

public:
  Matrix(unsigned int width, unsigned int height);
  Matrix(unsigned int width, unsigned int height, const Complex initialValue);
  Matrix(const std::vector<std::vector<Complex>>& values);

  Complex get(unsigned int x, unsigned int y) const;
  void set(unsigned int x, unsigned int y, const Complex value);

  Matrix conjugate() const;
  void conjugateInplace();

  Matrix transpose() const;
  void transposeInplace();

  Matrix hermitian() const;
  void hermitianInplace();

  Matrix multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);

  Matrix operator+(const Matrix& other) const;
  void operator+=(const Matrix& other);

  Matrix operator-(const Matrix& other) const;
  void operator-=(const Matrix& other);

  bool operator==(const Matrix& other) const;
  bool operator!=(const Matrix& other) const;
};