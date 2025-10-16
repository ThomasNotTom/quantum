#pragma once

#include "../complex/complex.hpp"
#include "../vector/vector.hpp"

class Bra;
class Matrix;

class Ket : public Vector {
public:
  using Vector::Vector;

  Ket(const Vector& vector);

  Bra transpose() const;
  Bra hermitian() const;

  Ket multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);
};