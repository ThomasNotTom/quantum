#pragma once

#include <vector>

#include "../complex/complex.hpp"
#include "../vector/vector.hpp"

class Matrix : public Vector {
private:
  unsigned int width, height;

public:
  Matrix(unsigned int width, unsigned int height);
  Matrix(unsigned int width, unsigned int height, const Complex initialValue);
  Matrix(const std::vector<std::vector<Complex>>& values);

  unsigned int getWidth() const;
  unsigned int getHeight() const;

  Complex get(unsigned int x, unsigned int y) const;
  void set(unsigned int x, unsigned int y, Complex value);

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