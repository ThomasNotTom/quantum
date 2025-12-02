#include "./state.hpp"

#include <iomanip>
#include <sstream>

std::mt19937 State::rng = std::mt19937(std::random_device{}());

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

float State::getProbability(size_t baseIndex) const {
  return this->bases[baseIndex].coefficient.modulusSquared();
};

size_t State::measure() {
  std::vector<float> probabilities;

  for (size_t i = 0; i < this->bases.size(); i++) {
    probabilities.push_back(this->getProbability(i));
  }

  std::discrete_distribution<int> dist(probabilities.begin(),
                                       probabilities.end());
  size_t state = dist(State::rng);

  for (size_t i = 0; i < this->bases.size(); i++) {
    this->bases[i].coefficient = Complex(state == i ? 1 : 0, 0);
  }

  return state;
};

std::string State::toString() const {
  std::string out = "";
  for (size_t i = 0; i < this->bases.size(); i++) {
    float real, imag;
    real = this->bases[i].coefficient.getReal();
    imag = this->bases[i].coefficient.getImaginary();

    if (imag == 0) {
      if (real < 0) {
        out += "-";
        if (i != 0) {
          out += " ";
        }
        if (remainderf(real, 1) == 0) {
          out += std::to_string(static_cast<int>(abs(real)));
        } else {
          std::ostringstream o;
          o << std::fixed << std::setprecision(2) << abs(real);
          out += o.str();
        }

      } else if (this->bases[i].coefficient.getReal() >= 0) {
        if (i != 0) {
          out += "+ ";
        }
        if (this->bases[i].coefficient.getReal() == 0) {
          out += "0";
        } else {
          if (remainderf(real, 1) == 0) {
            out += std::to_string(static_cast<int>(real));
          } else {
            std::ostringstream o;
            o << std::fixed << std::setprecision(2) << real;
            out += o.str();
          }
        }
      }
    } else {
      if (i != 0) {
        out += "+ ";
      }
      out += "(";
      out += this->bases[i].coefficient.toString();
      out += ")";
    }
    out += "|";
    out += std::to_string(i);
    out += "〉";
  }

  return out;
};