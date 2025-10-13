#include "./degree.hpp"

#include <cmath>

#include "./radian.hpp"

Degree::Degree(float value) : value(value) {};
Degree::Degree(const Radian& radian) {
  this->value = radian.getRadians() * 180.0f / M_PI;
};

float Degree::getDegree() const { return this->value; };
void Degree::setDegree(float value) { this->value = value; };
void Degree::addDegree(float value) { this->value += value; };