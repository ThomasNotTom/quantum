#include "../vector/vector.hpp

class Ket;

class Bra : public Vector {
public:
  using Vector::Vector;

  Complex inner(const Ket& other) const;

  Ket transpose() const;
  Ket hermitian() const;

  Bra multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);
};