#pragma once

#include <string>

class Polar;

class Complex {
private:
  float real;
  float imaginary;

public:
  Complex(float real, float imaginary);
  Complex(float real);
  Complex();

  Complex(const Polar& polar);

  float getReal() const;
  float getImaginary() const;

  void setReal(float real);
  void setImaginary(float imaginary);

  void addReal(float real);
  void addImaginary(float imaginary);

  Complex conjugate() const;
  void conjugateInplace();

  float modulusSquared() const;
  float modulus() const;

  Complex normalize() const;
  void normalizeInplace();

  std::string toString() const;

  Complex operator+(const Complex& other) const;
  void operator+=(const Complex& other);

  Complex operator+(float k) const;
  void operator+=(float k);

  Complex operator-(const Complex& other) const;
  void operator-=(const Complex& other);

  Complex operator-(float k) const;
  void operator-=(float k);

  Complex operator*(const Complex& other) const;
  void operator*=(const Complex& other);

  Complex operator*(float k) const;
  void operator*=(float k);

  Complex operator/(const Complex& other) const;
  void operator/=(const Complex& other);

  Complex operator/(float k) const;
  void operator/=(float k);

  bool operator==(const Complex& other) const;
  bool operator!=(const Complex& other) const;
};