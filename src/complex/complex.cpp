#include "./complex.hpp"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

#include "../polar/polar.hpp"

std::string Complex::floatToString(float x) {
  if (remainderf(x, 1) == 0) {
    return std::to_string(static_cast<int>(x));
  }

  std::ostringstream o;
  o << std::fixed << std::setprecision(2) << x;
  return o.str();
};

Complex::Complex(float real, float imaginary)
    : real(real), imaginary(imaginary) {};
Complex::Complex(float real) : real(real), imaginary(0.0f) {};
Complex::Complex() : real(0.0f), imaginary(0.0f) {};

Complex::Complex(const Polar& polar) {
  this->real = polar.getModulus() * sinf(polar.getArgument().getRadians());
  this->imaginary = polar.getModulus() * cosf(polar.getArgument().getRadians());
};

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

std::string Complex::toString() const {
  std::ostringstream outStream;

  if (this->real == 0 && this->imaginary == 0) {
    outStream << "0" << std::endl;
  } else {
    if (this->real == 0) {
      if (this->imaginary < 0) {
        outStream << "-";
      }
      outStream << Complex::floatToString(abs(this->imaginary));
      outStream << "i";
    } else if (this->imaginary == 0) {
      outStream << Complex::floatToString(this->real);
    } else {
      outStream << Complex::floatToString(this->real);
      if (this->imaginary > 0) {
        outStream << " + ";
      } else {
        outStream << " - ";
      }

      outStream << Complex::floatToString(abs(this->imaginary));
      outStream << "i";
    }
  }

  return outStream.str();
}

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

bool Complex::operator==(const Complex& other) const {
  return this->real == other.real && this->imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
  return this->real != other.real || this->imaginary != other.imaginary;
}