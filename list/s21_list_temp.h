#ifndef _SRC_LIST_S21_LIST_H_
#define _SRC_LIST_S21_LIST_H_
#include <climits>
#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <list>

namespace s21 {
template <typename T>
class List {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  List();
  explicit List(size_type n);
  explicit List(const List<T> &v);
  explicit List(List<T> &&v);
  explicit List(std::initializer_list<value_type> const &items);
  ~List();
  List<T> &operator=(List &&v);
  List<T> &operator=(const List<T> &s);

  const_reference Front();
  const_reference Back();

  bool Empty() const;
  size_t Size() const;
  size_type MaxSize();
  void Clear();
  void PushBack(const T &value);
  void PushBackEmpty();
  void PopBack();
  void PushFront(const T &value);
  void PopFront();
  void Swap(List<T> &other);
  void Merge(List<T> &other);
  void Unique();
  void Reverse();
  void Sort();

  template <class Type, class... Args>
  void EmplaceBack(Type n, Args... args);

  template <class Type, class... Args>
  void EmplaceFront(Type n, Args... args);

 private:
  struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    T data;
  };

  Node *head = nullptr;
  Node *tail = nullptr;
  size_type size_ = 0;
  Node *NIL_ = nullptr;
  Node *CreateNIL();
  void EmplaceBack();
  void EmplaceFront();
  static Node *GetNil(Node *n);

 public:
  struct Iterator {
    friend class List;
    Iterator();
    explicit Iterator(Node &other);
    Iterator &operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator &other) const;
    bool operator==(const Iterator &other) const;
    Iterator &operator--();
    Iterator operator--(int);
    T operator*() const;

   private:
    Node *current_node = nullptr;
  };

  typedef typename List<T>::Iterator iterator;
  using const_iterator = typename List<T>::Iterator;

  iterator Begin();
  iterator End();

  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator index);
  void Splice(const_iterator pos, List<T> &other);

  template <class Type, class... Args>
  iterator Emplace(iterator pos, Type n, Args... args);

 private:
  iterator Emplace(iterator pos);
};
#include "s21_iterator.inl"
#include "s21_list.inl"
}  // namespace s21
#endif  // _SRC_LIST_S21_LIST_H_
