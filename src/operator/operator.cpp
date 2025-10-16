#include "./operator.hpp"

Operator::Operator(unsigned int width, unsigned int height)
    : Matrix(width, height) {};

Operator::Operator(unsigned int width, unsigned int height,
                   const Complex initialValue)
    : Matrix(width, height, initialValue) {};

Operator::Operator(const std::vector<std::vector<Complex>>& values)
    : Matrix(values) {};
