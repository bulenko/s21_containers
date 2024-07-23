#ifndef SRC_STACK_S21_STACK_H_
#define SRC_STACK_S21_STACK_H_

#include "../vector/s21_vector.h"

namespace s21 {
template <class T, class Container = s21::Vector<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Stack();
  explicit Stack(std::initializer_list<value_type> const &items);
  explicit Stack(const Stack &s);
  explicit Stack(const Container &s);
  explicit Stack(Stack &&s);
  ~Stack();
  Stack<T, Container> &operator=(const Stack &v);
  Stack<T, Container> &operator=(Stack &&s);

  const_reference Top();
  bool Empty() const;
  size_type Size();
  void Push(const_reference value);
  void Pop();
  void Swap(Stack &v);
  void MakeEmptyStack();

  template <class... Args>
  void EmplaceFront(Args &&...args);

 private:
  Container container_;
};
#include "s21_stack.inl"
}  // namespace s21
#endif  // SRC_STACK_S21_STACK_H_
