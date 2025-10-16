#pragma once

#include "../matrix/matrix.hpp"

class Ket;

class Operator : public Matrix {
public:
  Operator(unsigned int width, unsigned int height);
  Operator(unsigned int width, unsigned int height, const Complex initialValue);
  Operator(const std::vector<std::vector<Complex>>& values);

  Matrix multiply(const Ket& other) const;
};