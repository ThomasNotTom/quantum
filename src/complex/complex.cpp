#include "./complex.hpp"

Complex::Complex(float real, float imaginary)
    : real(real), imaginary(imaginary) {};
Complex::Complex() : real(0.0f), imaginary(0.0f) {};

float Complex::getReal() const { return this->real; };
float Complex::getImaginary() const { return this->imaginary; };

void Complex::setReal(float real) { this->real = real; };
void Complex::setImaginary(float imaginary) { this->imaginary = imaginary; };

void Complex::addReal(float real) { this->real += real; };
void Complex::addImaginary(float imaginary) { this->imaginary += imaginary; };