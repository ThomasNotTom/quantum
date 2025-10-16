#include "./vector.hpp"

Vector::Vector(unsigned int height) : Vector(height, Complex()) {};

Vector Vector::conjugate() const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i).conjugate());
  }

  return out;
};

void Vector::conjugateInplace() {
  const Vector thisTemp = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisTemp.get(i).conjugate());
  }
};

Vector Vector::operator*(const Complex& k) const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i) * k);
  }
  return out;
};

void Vector::operator*=(const Complex& k) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisCopy.get(i) * k);
  }
};

Vector Vector::operator/(const Complex& k) const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i) / k);
  }
  return out;
};

void Vector::operator/=(const Complex& k) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisCopy.get(i) / k);
  }
};