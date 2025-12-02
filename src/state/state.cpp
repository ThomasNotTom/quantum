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

void State::normaliseInplace() {
  float totalLengthSquared = 0;

  for (size_t i = 0; i < this->bases.size(); i++) {
    totalLengthSquared += this->bases[i].coefficient.modulusSquared();
  }

  float totalLength = sqrtf(totalLengthSquared);

  for (size_t i = 0; i < this->bases.size(); i++) {
    this->bases[i].coefficient /= totalLength;
  }
};

State State::normalise() const {
  State newState = State(this->bases.size());

  float totalLengthSquared = 0;

  for (size_t i = 0; i < this->bases.size(); i++) {
    totalLengthSquared += this->bases[i].coefficient.modulusSquared();
  }

  float totalLength = sqrtf(totalLengthSquared);

  for (size_t i = 0; i < this->bases.size(); i++) {
    newState.setBasisCoef(this->bases[i].coefficient / totalLength, i);
  }

  return newState;
};