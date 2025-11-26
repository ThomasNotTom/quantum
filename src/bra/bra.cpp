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

std::string Bra::toString() const {
  std::string out = "[ ";
  for (size_t i = 0; i < this->values.size(); i++) {
    out += this->values[i].toString();
    if (i < this->values.size() - 1) {
      out += "   ";
    }
  }

  out += " ]";

  return out;
};

Bra Bra::operator+(const Bra& other) const {
  Bra out = Bra(this->getSize());

  for (unsigned int y = 0; y < this->getSize(); y++) {
    out.set(y, this->get(y) + other.get(y));
  }

  return out;
}

void Bra::operator+=(const Bra& other) {
  const Bra thisTemp = *this;

  for (unsigned int y = 0; y < this->getSize(); y++) {
    this->set(y, thisTemp.get(y) + other.get(y));
  }
}

Bra Bra::operator-(const Bra& other) const {
  Bra out = Bra(this->getSize());

  for (unsigned int y = 0; y < this->getSize(); y++) {
    out.set(y, this->get(y) - other.get(y));
  }

  return out;
}

void Bra::operator-=(const Bra& other) {
  const Bra thisTemp = *this;

  for (unsigned int y = 0; y < this->getSize(); y++) {
    this->set(y, thisTemp.get(y) - other.get(y));
  }
}

bool Bra::operator==(const Bra& other) const {
  for (unsigned int i = 0; i < this->getSize(); i++) {
    if (this->get(i) != other.get(i)) {
      return false;
    }
  }
  return true;
};

bool Bra::operator!=(const Bra& other) const {
  for (unsigned int i = 0; i < this->getSize(); i++) {
    if (this->get(i) == other.get(i)) {
      return true;
    }
  }
  return false;
};