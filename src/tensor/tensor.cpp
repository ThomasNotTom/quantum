#include "./tensor.hpp"

template <typename T>
Tensor<T>::Tensor(unsigned int height, const T initialValue)
    : values(height, initialValue){};

template <typename T>
Tensor<T>::Tensor(const std::vector<T>& values) : values(values){};