#include "./state.hpp"

State::State(size_t basisCount) {
  for (size_t i = 0; i < basisCount; i++) {
    Vector basis = Vector(basisCount);
    basis.set(i, Complex(1, 0));

    bases.push_back(BasisCoefficient(basis, Complex(0, 0)));
  };
}

void State::setBasisCoef(Complex coef, size_t baseIndex) {
  this->bases[baseIndex].coefficient = coef;
};