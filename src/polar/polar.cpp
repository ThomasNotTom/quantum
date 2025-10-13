#include "./polar.hpp"

#include <cmath>

#include "../angles/radian.hpp"

Polar::Polar(float modulus, float argument)
    : modulus(modulus), argument(Radian(argument)) {};

Polar::Polar(const Complex complex)
    : modulus(complex.modulus()),
      argument(atanf(complex.getImaginary() / complex.getReal())) {};

float Polar::getModulus() const { return this->modulus; };
Radian Polar::getArgument() const { return this->argument; };