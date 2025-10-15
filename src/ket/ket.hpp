#pragma once

#include <vector>

#include "../complex/complex.hpp"

class Bra;
class Matrix;

class Ket {
private:
  std::vector<Complex> values;

public:
  Ket(unsigned int height);
  Ket(unsigned int height, const Complex initialValue);
  Ket(const std::vector<Complex>& values);

  Complex get(unsigned int y) const;
  void set(unsigned int y, const Complex value);

  Complex inner(const Bra& other) const;

  Ket multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);

  Ket operator+(const Ket& other) const;
  void operator+=(const Ket& other);

  Ket operator-(const Ket& other) const;
  void operator-=(const Ket& other);

  bool operator==(const Ket& other) const;
  bool operator!=(const Ket& other) const;
};