#include "./bra.hpp"

#include "../complex/complex.hpp"
#include "../ket/ket.hpp"
#include "../matrix/matrix.hpp"
#include "../vector/vector.hpp"

Bra::Bra(const Vector& vector) : Bra(vector.getValues()) {};

Complex Bra::inner(const Ket& other) const {
  Complex total = Complex(0.0f, 0.0f);

  for (unsigned int i = 0; i < this->getSize(); i++) {
    total += this->get(i) * other.get(i);
  }

  return total;
};

Ket Bra::transpose() const { return Ket(this->values); };
Ket Bra::hermitian() const {
  Ket out = this->transpose();
  return out.conjugate();
};