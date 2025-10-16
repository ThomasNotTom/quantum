#include "./vector.hpp"

Vector::Vector(unsigned int height) : Vector(height, Complex()) {};

Vector Vector::conjugate() const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i).conjugate());
  }

  return out;
};

Vector Vector::conjugate() const {
  const Vector thisTemp = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisTemp.get(i).conjugate());
  }
};

Vector Vector::operator+(const Vector& other) const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i) + other.get(i));
  }
  return out;
};

void Vector::operator+=(const Vector& other) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisCopy.get(i) + other.get(i));
  }
};

Vector Vector::operator-(const Vector& other) const {
  Vector out = Vector(this->getSize());
  for (unsigned int i = 0; i < this->getSize(); i++) {
    out.set(i, this->get(i) - other.get(i));
  }
  return out;
};

void Vector::operator-=(const Vector& other) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getSize(); i++) {
    this->set(i, thisCopy.get(i) - other.get(i));
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

bool Vector::operator==(const Vector& other) const {
  for (unsigned int i = 0; i < this->getSize(); i++) {
    if (this->get(i) != other.get(i)) {
      return false;
    }
  }
  return true;
};

bool Vector::operator!=(const Vector& other) const {
  for (unsigned int i = 0; i < this->getSize(); i++) {
    if (this->get(i) == other.get(i)) {
      return true;
    }
  }
  return false;
};