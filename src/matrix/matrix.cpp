#include "./matrix.hpp"

Matrix::Matrix(unsigned int width, unsigned int height)
    : Vector(width * height), width(width), height(height) {};

Matrix::Matrix(unsigned int width, unsigned int height,
               const Complex initialValue)
    : Vector(width * height, initialValue), width(width), height(height) {};

Matrix::Matrix(const std::vector<std::vector<Complex>>& values)
    : height(values.size()), width(values.size()) {
  for (unsigned int y = 0; y < values.size(); y++) {
    std::vector<Complex> inner = values[y];
    this->values.insert(this->values.end(), inner.begin(), inner.end());
  }
};

unsigned int Matrix::getWidth() const { return this->width; }
unsigned int Matrix::getHeight() const { return this->height; }

Complex Matrix::get(unsigned int x, unsigned int y) const {
  return this->values[(this->height * y) + x];
};

void Matrix::set(unsigned int x, unsigned int y, Complex value) {
  this->values[(this->height * y) + x] = value;
};

Matrix Matrix::conjugate() const {
  Matrix out = Matrix(this->width, this->height, Complex(0.0f, 0.0f));

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
  Matrix out = Matrix(this->height, this->width, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(y, x, this->get(x, y));
    }
  }

  return out;
}

void Matrix::transposeInplace() {
  Matrix thisTemp = *this;

  values.assign(this->width * this->height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      this->set(y, x, thisTemp.get(x, y));
    }
  }
}

Matrix Matrix::hermitian() const {
  Matrix out = Matrix(this->height, this->width, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      out.set(y, x, this->get(x, y).conjugate());
    }
  }

  return out;
};

void Matrix::hermitianInplace() {
  Matrix thisTemp = *this;

  values.assign(this->width * this->height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      this->set(y, x, thisTemp.get(x, y).conjugate());
    }
  }
};

Matrix Matrix::multiply(const Matrix& other) const {
  Matrix out = Matrix(this->width, this->height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < height; y++) {
    for (unsigned int x = 0; x < width; x++) {
      Complex sum = Complex(0.0f, 0.0f);
      for (unsigned int i = 0; i < width; i++) {
        sum += this->get(i, y) * other.get(x, i);
      }

      out.set(x, y, sum);
    }
  }

  return out;
};

void Matrix::multiplyInplace(const Matrix& other) {
  const Matrix thisTemp = *this;

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      Complex sum = Complex(0.0f, 0.0f);
      for (unsigned int i = 0; i < width; i++) {
        sum += thisTemp.get(i, y) * other.get(x, i);
      }

      this->set(x, y, sum);
    }
  }
};

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix out = Matrix(this->getWidth(), this->getHeight());

  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      out.set(x, y, this->get(x, y) + other.get(x, y));
    }
  }

  return out;
}

void Matrix::operator+=(const Matrix& other) {
  const Matrix thisTemp = *this;

  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      this->set(x, y, thisTemp.get(x, y) + other.get(x, y));
    }
  }
}

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix out = Matrix(this->getWidth(), this->getHeight());

  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      out.set(x, y, this->get(x, y) - other.get(x, y));
    }
  }

  return out;
}

void Matrix::operator-=(const Matrix& other) {
  const Matrix thisTemp = *this;

  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      this->set(x, y, thisTemp.get(x, y) - other.get(x, y));
    }
  }
}

bool Matrix::operator==(const Matrix& other) const {
  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      return false;
    }
  }
  return true;
};

bool Matrix::operator!=(const Matrix& other) const {
  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      return true;
    }
  }
  return false;
};