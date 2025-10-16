#include <vector>

template <typename T> class Tensor {
protected:
  std::vector<T> values;

public:
  Tensor(unsigned int height, const T initialValue);
  Tensor(const std::vector<T>& values);

  const T& get(unsigned int i) const;
  T& get(unsigned int i);
  void set(unsigned int i, T value) const;

  const std::vector<T>& getValues() const;

  unsigned int getSize() const;
};