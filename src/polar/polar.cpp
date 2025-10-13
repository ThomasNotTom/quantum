#include "./polar.hpp"

#include <cmath>

#include "../angles/radian.hpp"

Polar::Polar(float modulus, float argument)
    : modulus(modulus), argument(Radian(argument)) {};

Polar::Polar(const Complex complex)
    : modulus(complex.modulus()),
      argument(atanf(complex.getImaginary() / complex.getReal())) {};