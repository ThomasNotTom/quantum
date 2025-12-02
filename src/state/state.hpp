#pragma once

#include <random>

#include "../vector/vector.hpp"
#include "./basis_coef.hpp"

class State {
private:
  static std::mt19937 rng;
  std::vector<BasisCoefficient> bases;

public:
  State(size_t basisCount);

  void setBasisCoef(Complex coef, size_t baseIndex);

  void normaliseInplace();
  State normalise() const;

  float getProbability(size_t baseIndex) const;
  size_t measure();

  std::string toString() const;
};