#include <vector>

template <typename T> class Tensor {
protected:
  std::vector<T> values;

public:
  Tensor() {};
  Tensor(unsigned int size, const T initialValue)
      : values(size, initialValue) {};
  Tensor(const std::vector<T>& values) : values(values) {};

  const T& get(unsigned int i) const { return this->values[i]; };
  T& get(unsigned int i) { return this->values[i]; };
  void set(unsigned int i, T value) { this->values[i] = value; };

  const std::vector<T>& getValues() const { return this->values; };

  unsigned int getSize() const { return this->values.size(); };
};