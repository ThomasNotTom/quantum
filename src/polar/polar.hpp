#pragma once

#include "../complex/complex.hpp"

#include "../angles/radian.hpp"

class Polar {
private:
  float modulus;
  Radian argument;

public:
  Polar(float modulus, float argument);
  Polar(const Complex complex);
};