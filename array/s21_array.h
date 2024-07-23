#ifndef SRC_ARRAY_S21_ARRAY_H_
#define SRC_ARRAY_S21_ARRAY_H_
#include <climits>
#include <cmath>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, size_t N>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array();
  explicit Array(const Array<T, N> &v);
  explicit Array(Array<T, N> &&v);
  explicit Array(std::initializer_list<value_type> const &items);
  ~Array();
  Array<T, N> &operator=(const Array &v);
  Array<T, N> &operator=(Array &&v);

  reference At(size_type position);
  reference operator[](size_type position);
  const_reference Front();
  const_reference Back();
  iterator Data();

  iterator Begin();
  iterator End();

  bool Empty() const;
  size_t Size() const;
  size_type MaxSize();

  void Swap(Array<T, N> &other);
  void Fill(const_reference value);

 private:
  T arr_[N]{};
};
#include "s21_array.inl"
}  // namespace s21
#endif  // SRC_ARRAY_S21_ARRAY_H_
