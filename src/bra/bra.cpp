#include "./bra.hpp"

#include "../complex/complex.hpp"
#include "../ket/ket.hpp"
#include "../matrix/matrix.hpp"
#include "../vector/vector.hpp"

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

Bra Bra::multiply(const Matrix& other) const {
  Bra out = Bra(this->getSize(), Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < other.getHeight(); y++) {
    Complex sum = Complex(0.0f, 0.0f);
    for (unsigned int x = 0; x < other.getWidth(); x++) {
      sum += this->get(y) * other.get(x, y);
    }
    out.set(y, sum);
  }

  return out;
};

void Bra::multiplyInplace(const Matrix& other) {
  const Bra thisTemp = *this;

  for (unsigned int y = 0; y < other.getHeight(); y++) {
    Complex sum = Complex(0.0f, 0.0f);
    for (unsigned int x = 0; x < other.getWidth(); x++) {
      sum += thisTemp.get(y) * other.get(x, y);
    }
    this->set(y, sum);
  }
};