#include "./radian.hpp"

#include <cmath>

#include "./degree.hpp"

Radian::Radian(float value) : value(value) {};
Radian::Radian(const Degree& degree) {
  this->value = M_PI * degree.getDegree() / 180.0f;
};

float Radian::getRadians() const { return this->value; };
void Radian::setRadians(float value) { this->value = value; };
void Radian::addRadians(float value) { this->value += value; };