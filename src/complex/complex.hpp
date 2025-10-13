class Complex {
private:
  float real;
  float imaginary;

public:
  Complex(float real, float imaginary);
  Complex();

  float getReal() const;
  float getImaginary() const;

  void setReal(float real);
  void setImaginary(float imaginary);

  float addReal(float real);
  float addImaginary(float imaginary);

  Complex operator+(const Complex& other) const;
  void operator+=(const Complex& other);

  Complex operator-(const Complex& other) const;
  void operator-=(const Complex& other);

  Complex operator*(float k) const;
  void operator*=(float k);
};