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
};