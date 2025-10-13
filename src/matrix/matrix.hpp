#include <vector>

#include "../complex/complex.hpp"

class Matrix {
private:
  std::vector<std::vector<Complex>> values;

public:
  Matrix(unsigned int width, unsigned int height);
  Matrix(unsigned int width, unsigned int height, const Complex& initialValue);
};