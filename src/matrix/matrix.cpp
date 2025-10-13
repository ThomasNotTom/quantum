#include "./matrix.hpp"

Matrix::Matrix(unsigned int width, unsigned int height)
    : Matrix(width, height, Complex(0.0f, 0.0f)) {};

Matrix::Matrix(unsigned int width, unsigned int height,
               const Complex initialValue)
    : values(height, std::vector<Complex>(width, initialValue)) {};