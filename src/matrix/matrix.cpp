#include "./matrix.hpp"

Matrix::Matrix(unsigned int width, unsigned int height)
    : Matrix(width, height, Complex(0.0f, 0.0f)) {};

Matrix::Matrix(unsigned int width, unsigned int height,
               const Complex initialValue)
    : values(height, std::vector<Complex>(width, initialValue)) {};

Matrix::Matrix(const std::vector<std::vector<Complex>>& values)
    : values(values) {};

Complex Matrix::get(unsigned int x, unsigned int y) const {
  return this->values[y][x];
}

void Matrix::set(unsigned int x, unsigned int y, const Complex value) {
  this->values[y][x] = value;
};

Matrix Matrix::conjugate() const {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(x, y, this->get(x, y).conjugate());
    }
  }

  return out;
};

void Matrix::conjugateInplace() {
  Matrix thisTemp = *this;

  unsigned int width, height;
  height = thisTemp.values.size();
  width = thisTemp.values.size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      this->set(x, y, thisTemp.get(x, y).conjugate());
    }
  }
};

Matrix Matrix::transpose() const {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(y, x, this->get(x, y));
    }
  }

  return out;
}

void Matrix::transposeInplace() {
  Matrix thisTemp = *this;

  unsigned int width, height;
  height = thisTemp.values.size();
  width = thisTemp.values[0].size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      this->set(y, x, thisTemp.get(x, y));
    }
  }
}

Matrix Matrix::hermitian() const {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(x, y, this->get(y, x).conjugate());
    }
  }

  return out;
};

void Matrix::hermitianInplace() {
  Matrix thisTemp = *this;

  unsigned int width, height;
  height = thisTemp.values.size();
  width = thisTemp.values[0].size();

  Matrix out = Matrix(width, height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      this->set(x, y, thisTemp.get(y, x).conjugate());
    }
  }
};

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix out = Matrix(this->values.size(), this->values[0].size());

  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(x, y, this->get(x, y) + other.get(x, y));
    }
  }

  return out;
};

void Matrix::operator+=(const Matrix& other) {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  Matrix out = Matrix(width, height);

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      this->set(x, y, this->get(x, y) + other.get(x, y));
    }
  }
};

bool Matrix::operator==(const Matrix& other) const {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      if (this->get(x, y) != other.get(x, y)) {
        return false;
      }
    }
  }

  return true;
}

bool Matrix::operator!=(const Matrix& other) const {
  unsigned int width, height;
  height = this->values.size();
  width = this->values[0].size();

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      if (this->get(x, y) != other.get(x, y)) {
        return true;
      }
    }
  }

  return false;
}