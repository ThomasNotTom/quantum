#include "../vector/vector.hpp"

class BasisCoefficient {
public:
  Vector basis;
  Complex coefficient;

  BasisCoefficient(Vector basis, Complex coefficient)
      : basis(basis), coefficient(coefficient) {};
};