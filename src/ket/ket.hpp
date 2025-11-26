#include "../vector/vector.hpp"

class Bra;
class Matrix;

class Ket : public Vector {
public:
  using Vector::Vector;

  Ket(const Vector& vector);

  Bra transpose() const;
  Bra hermitian() const;

  Ket multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);

  Matrix outer(const Bra& other) const;

  std::string toString() const;

  Ket operator+(const Ket& other) const;
  void operator+=(const Ket& other);

  Ket operator-(const Ket& other) const;
  void operator-=(const Ket& other);

  bool operator==(const Ket& other) const;
  bool operator!=(const Ket& other) const;
};