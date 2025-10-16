class Bra {
  Bra(unsigned int height);
  Bra(unsigned int height, const Complex initialValue);
  Bra(const std::vector<Complex>& values);

  Complex get(unsigned int y) const;
  void set(unsigned int y, const Complex value);

  Complex inner(const Bra& other) const;

  Bra multiply(const Matrix& other) const;
  void multiplyInplace(const Matrix& other);

  Bra operator+(const Bra& other) const;
  void operator+=(const Bra& other);

  Bra operator-(const Bra& other) const;
  void operator-=(const Bra& other);

  bool operator==(const Bra& other) const;
  bool operator!=(const Bra& other) const;
};