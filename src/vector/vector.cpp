#include "./vector.hpp"

Vector Vector::operator+(const Vector& other) const {
  Vector out = Vector(this->getRank());
  for (unsigned int i = 0; i < this->getRank(); i++) {
    out.set(i, this->get(i) + other.get(i));
  }
  return out;
};

void Vector::operator+=(const Vector& other) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getRank(); i++) {
    this->set(i, thisCopy.get(i) + other.get(i));
  }
};

Vector Vector::operator-(const Vector& other) const {
  Vector out = Vector(this->getRank());
  for (unsigned int i = 0; i < this->getRank(); i++) {
    out.set(i, this->get(i) - other.get(i));
  }
  return out;
};

void Vector::operator-=(const Vector& other) {
  const Vector thisCopy = *this;

  for (unsigned int i = 0; i < this->getRank(); i++) {
    this->set(i, thisCopy.get(i) - other.get(i));
  }
};