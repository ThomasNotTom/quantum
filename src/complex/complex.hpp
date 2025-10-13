#pragma once

class Complex {
private:
  float real;
  float imaginary;

public:
  Complex(float real, float imaginary);
  Complex();

  float getReal() const;
  float getImaginary() const;

  void setReal(float real);
  void setImaginary(float imaginary);

  void addReal(float real);
  void addImaginary(float imaginary);

  Complex operator+(const Complex& other) const;
  void operator+=(const Complex& other);

  Complex operator-(const Complex& other) const;
  void operator-=(const Complex& other);

  Complex operator*(float k) const;
  void operator*=(float k);

  Complex operator*(const Complex& other) const;
  void operator*=(const Complex& other);

  Complex operator/(float k) const;
  void operator/=(float k);

  Complex operator/(const Complex& other) const;
  void operator/=(const Complex& other);
};