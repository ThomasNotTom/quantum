#include "./ket.hpp"

#include "../bra/bra.hpp"
#include "../matrix/matrix.hpp"

Ket::Ket(const Vector& vector) : Ket(vector.getValues()) {};

Bra Ket::transpose() const { return Bra(this->values); };
Bra Ket::hermitian() const {
  Bra out = this->transpose();
  return out.conjugate();
};

Ket Ket::multiply(const Matrix& other) const {
  Ket out = Ket(this->getSize(), Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < other.getHeight(); y++) {
    Complex sum = Complex(0.0f, 0.0f);
    for (unsigned int x = 0; x < other.getWidth(); x++) {
      sum += this->get(y) * other.get(x, y);
    }
    out.set(y, sum);
  }

  return out;
};

void Ket::multiplyInplace(const Matrix& other) {
  const Ket thisTemp = *this;

  for (unsigned int y = 0; y < other.getHeight(); y++) {
    Complex sum = Complex(0.0f, 0.0f);
    for (unsigned int x = 0; x < other.getWidth(); x++) {
      sum += thisTemp.get(y) * other.get(x, y);
    }
    this->set(y, sum);
  }
};

Matrix Ket::outer(const Bra& other) const {
  Matrix out = Matrix(other.getSize(), this->getSize());
  for (unsigned int y = 0; y < this->getSize(); y++) {
    for (unsigned int x = 0; x < other.getSize(); x++) {
      out.set(x, y, this->get(y) * other.get(x));
    }
  }

  return out;
};