class Complex {
private:
  float real;
  float imaginary;

public:
  float getReal() const;
  float getImaginary() const;

  void setReal(float real);
  void setImaginary(float imaginary);

  float addReal(float real);
  float addImaginary(float imaginary);
};