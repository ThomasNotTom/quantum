#include "../vector/vector.hpp

class Ket;

class Bra : public Vector {
public:
  using Vector::Vector;

  Bra(const Vector& vector);

  Complex inner(const Ket& other) const;

  Ket transpose() const;
  Ket hermitian() const;
};