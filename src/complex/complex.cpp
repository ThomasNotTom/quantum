#include "./complex.hpp"

#include <cmath>

Complex::Complex(float real, float imaginary)
    : real(real), imaginary(imaginary) {};
Complex::Complex(float real) : real(real), imaginary(0.0f) {};
Complex::Complex() : real(0.0f), imaginary(0.0f) {};

float Complex::getReal() const { return this->real; };
float Complex::getImaginary() const { return this->imaginary; };

void Complex::setReal(float real) { this->real = real; };
void Complex::setImaginary(float imaginary) { this->imaginary = imaginary; };

void Complex::addReal(float real) { this->real += real; };
void Complex::addImaginary(float imaginary) { this->imaginary += imaginary; };

Complex Complex::conjugate() const {
  return Complex(this->real, this->imaginary * -1);
}

void Complex::conjugateInplace() { this->imaginary *= -1; }

float Complex::modulusSquared() const {
  return (this->real * this->real) + (this->imaginary * this->imaginary);
};

float Complex::modulus() const {
  return sqrtf((this->real * this->real) + (this->imaginary * this->imaginary));
};

Complex Complex::normalize() const { return *this / this->modulus(); };
void Complex::normalizeInplace() {
  const Complex thisTemp = *this;
  const float mod = this->modulus();
  this->real /= mod;
  this->imaginary /= mod;
};

Complex Complex::operator+(const Complex& other) const {
  return Complex(this->real + other.real, this->imaginary + other.imaginary);
};

void Complex::operator+=(const Complex& other) {
  this->real += other.real;
  this->imaginary += other.imaginary;
};

Complex Complex::operator+(float k) const {
  return Complex(this->real + k, this->imaginary);
};

void Complex::operator+=(float k) { this->real += k; };

Complex Complex::operator-(const Complex& other) const {
  return Complex(this->real - other.real, this->imaginary - other.imaginary);
};

void Complex::operator-=(const Complex& other) {
  this->real -= other.real;
  this->imaginary -= other.imaginary;
};

Complex Complex::operator-(float k) const {
  return Complex(this->real - k, this->imaginary);
};

void Complex::operator-=(float k) { this->real -= k; };

Complex Complex::operator*(float k) const {
  return Complex(this->real * k, this->imaginary * k);
};

void Complex::operator*=(float k) {
  this->real *= k;
  this->imaginary *= k;
};

Complex Complex::operator*(const Complex& other) const {
  return Complex(
      (this->real * other.real) - (this->imaginary * other.imaginary),
      (this->real * other.imaginary) + (this->imaginary * other.real));
};

void Complex::operator*=(const Complex& other) {
  const Complex thisTemp = *this;

  this->real =
      (thisTemp.real * other.real) - (thisTemp.imaginary * other.imaginary);
  this->imaginary =
      (thisTemp.real * other.imaginary) + (thisTemp.imaginary * other.real);
};

Complex Complex::operator/(float k) const {
  return Complex(this->real / k, this->imaginary / k);
};

void Complex::operator/=(float k) {
  this->real /= k;
  this->imaginary /= k;
};

Complex Complex::operator/(const Complex& other) const {
  const float divisor =
      (other.real * other.real) + (other.imaginary * other.imaginary);

  return Complex(
      ((this->real * other.real) + (this->imaginary * other.imaginary)) /
          divisor,
      ((this->imaginary * other.real) - (this->real * other.imaginary)) /
          divisor);
};

void Complex::operator/=(const Complex& other) {
  const Complex thisTemp = *this;

  const float divisor =
      (other.real * other.real) + (other.imaginary * other.imaginary);

  this->real =
      ((thisTemp.real * other.real) + (thisTemp.imaginary * other.imaginary)) /
      divisor;
  this->imaginary =
      ((thisTemp.imaginary * other.real) - (thisTemp.real * other.imaginary)) /
      divisor;
};