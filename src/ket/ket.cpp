#include "./ket.hpp"

Ket::Ket(unsigned int height) : Ket(height, Complex(0.0f, 0.0f)) {};

Ket::Ket(unsigned int height, const Complex initialValue)
    : values(height, initialValue) {};

Ket::Ket(const std::vector<Complex>& values) : values(values) {};