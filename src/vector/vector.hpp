#pragma once

#include "../complex/complex.hpp"
#include "../tensor/tensor.hpp"

class Matrix;

class Vector : public Tensor<Complex> {
public:
  using Tensor<Complex>::Tensor;

  Vector conjugate() const;
  void conjugateInplace();

  Vector operator+(const Vector& other) const;
  void operator+=(const Vector& other);

  Vector operator-(const Vector& other) const;
  void operator-=(const Vector& other);

  Vector operator*(const Complex& k) const;
  void operator*=(const Complex& k);

  Vector operator/(const Complex& k) const;
  void operator/=(const Complex& k);

  bool operator==(const Vector& other) const;
  bool operator!=(const Vector& other) const;
};