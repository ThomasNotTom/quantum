#include "../vector/vector.hpp"

class Ket;

class Bra : public Vector {
public:
  using Vector::Vector;

  Bra(const Vector& vector);

  Complex inner(const Ket& other) const;

  Ket transpose() const;
  Ket hermitian() const;

  std::string toString() const;

  Bra operator+(const Bra& other) const;
  void operator+=(const Bra& other);

  Bra operator-(const Bra& other) const;
  void operator-=(const Bra& other);

  bool operator==(const Bra& other) const;
  bool operator!=(const Bra& other) const;
};