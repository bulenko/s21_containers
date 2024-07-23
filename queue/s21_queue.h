#ifndef SRC_QUEUE_S21_QUEUE_H_
#define SRC_QUEUE_S21_QUEUE_H_
#include "../list/s21_list.h"

namespace s21 {
template <typename T, class Container = s21::List<T>>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue();
  explicit Queue(std::initializer_list<value_type> const &items);
  explicit Queue(const Queue &s);
  explicit Queue(const Container &s);
  explicit Queue(Queue &&s);
  ~Queue();
  Queue<T, Container> &operator=(const Queue<T, Container> &s);
  Queue<T, Container> &operator=(Queue &&s);

  const_reference Front();
  const_reference Back();

  bool Empty() const;
  size_type Size();

  void Push(const_reference value);
  void Pop();
  void Swap(Queue &other);
  void MakeEmptyQueue();

  template <class... Args>
  void EmplaceBack(Args &&...args);

 private:
  Container container_;
};
#include "s21_queue.inl"
}  // namespace s21

#endif  // SRC_QUEUE_S21_QUEUE_H_
