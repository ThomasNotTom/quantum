#include <iostream>

#include "./matrix.hpp"

Matrix::Matrix() : Vector(0), width(0), height(0) {};

Matrix::Matrix(unsigned int width, unsigned int height)
    : Vector(width * height), width(width), height(height) {};

Matrix::Matrix(unsigned int width, unsigned int height,
               const Complex initialValue)
    : Vector(width * height, initialValue), width(width), height(height) {};

Matrix::Matrix(const std::vector<std::vector<Complex>>& values)
    : height(values.size()), width(values[0].size()) {
  for (unsigned int y = 0; y < values.size(); y++) {
    std::vector<Complex> inner = values[y];
    this->values.insert(this->values.end(), inner.begin(), inner.end());
  }
};

unsigned int Matrix::getWidth() const { return this->width; }
unsigned int Matrix::getHeight() const { return this->height; }

Complex Matrix::get(unsigned int x, unsigned int y) const {
  return this->values[(this->width * y) + x];
};

void Matrix::set(unsigned int x, unsigned int y, Complex value) {
  this->values[(this->width * y) + x] = value;
};

Matrix Matrix::conjugate() const {
  Matrix out = Matrix(this->width, this->height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      out.set(x, y, this->get(x, y).conjugate());
    }
  }

  return out;
};

void Matrix::conjugateInplace() {
  Matrix thisTemp = *this;

  Matrix out = Matrix(this->width, this->height, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      this->set(x, y, thisTemp.get(x, y).conjugate());
    }
  }
};

Matrix Matrix::transpose() const {
  Matrix out = Matrix(this->height, this->width, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      out.set(y, x, this->get(x, y));
    }
  }

  return out;
}

void Matrix::transposeInplace() {
  Matrix thisTemp = *this;

  values.assign(this->width * this->height, Complex(0.0f, 0.0f));
  this->width = thisTemp.height;
  this->height = thisTemp.width;

  for (unsigned int y = 0; y < thisTemp.height; y++) {
    for (unsigned int x = 0; x < thisTemp.width; x++) {
      this->set(y, x, thisTemp.get(x, y));
    }
  }
}

Matrix Matrix::hermitian() const {
  Matrix out = Matrix(this->height, this->width, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < this->width; x++) {
      out.set(y, x, this->get(x, y).conjugate());
    }
  }

  return out;
};

void Matrix::hermitianInplace() {
  Matrix thisTemp = *this;

  values.assign(this->height * this->width, Complex(0.0f, 0.0f));

  this->width = thisTemp.height;
  this->height = thisTemp.width;

  for (unsigned int y = 0; y < thisTemp.height; y++) {
    for (unsigned int x = 0; x < thisTemp.width; x++) {
      this->set(y, x, thisTemp.get(x, y).conjugate());
    }
  }
};

Matrix Matrix::multiply(const Matrix& other) const {
  Matrix out = Matrix(this->height, other.width, Complex(0.0f, 0.0f));

  for (unsigned int y = 0; y < this->height; y++) {
    for (unsigned int x = 0; x < other.width; x++) {
      Complex sum = Complex(0.0f, 0.0f);
      for (unsigned int i = 0; i < this->width; i++) {
        sum += this->get(i, y) * other.get(x, i);
      }
      out.set(x, y, sum);
    }
  }

  return out;
};

void Matrix::multiplyInplace(const Matrix& other) {
  const Matrix thisTemp = *this;

  this->values.assign(this->height * other.width, Complex(0, 0));
  this->width = other.width;

  for (unsigned int y = 0; y < thisTemp.height; y++) {
    for (unsigned int x = 0; x < other.width; x++) {
      Complex sum = Complex(0.0f, 0.0f);
      for (unsigned int i = 0; i < thisTemp.width; i++) {
        sum += thisTemp.get(i, y) * other.get(x, i);
      }
      this->set(x, y, sum);
    }
  }
};

std::string Matrix::toString() const {
  std::string out = "";

  for (unsigned int y = 0; y < this->height; y++) {
    out += "| ";
    for (unsigned int x = 0; x < this->width; x++) {
      out += this->get(x, y).toString();
      if (x != (this->width - 1)) {
        out += " ";
      }
    }
    out += " |";
    if (y != (this->height - 1)) {
      out += "\n";
    }
  }

  return out;
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
      if (this->get(x, y) != other.get(x, y)) {
        return false;
      }
    }
  }
  return true;
};

bool Matrix::operator!=(const Matrix& other) const {
  for (unsigned int y = 0; y < this->getHeight(); y++) {
    for (unsigned int x = 0; x < this->getWidth(); x++) {
      if (this->get(x, y) != other.get(x, y)) {
        return true;
      }
    }
  };
  return false;
};