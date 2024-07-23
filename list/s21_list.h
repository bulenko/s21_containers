#ifndef SRC_LIST_S21_LIST_H_
#define SRC_LIST_S21_LIST_H_
#include <climits>
#include <initializer_list>
#include <iostream>

#include "../vector/s21_vector.h"

namespace s21 {
template <typename T>
class List {
  struct Node;

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

  struct Iterator {
    friend class List;
    Iterator() : current_node(nullptr){};
    explicit Iterator(Node &other) : current_node(&other){};

    Iterator &operator++() {
      if (current_node != GetNil(current_node)) {
        current_node = current_node->next;
      }
      return *this;
    };

    Iterator operator++(int) {
      Iterator tempIter = *this;
      ++*this;
      return tempIter;
    };

    bool operator!=(const Iterator &other) const {
      return this->current_node != other.current_node;
    };

    bool operator==(const Iterator &other) const {
      return this->current_node == other.current_node;
    };

    Iterator &operator--() {
      if (current_node != nullptr) {
        current_node = current_node->prev;
      }
      return *this;
    };

    Iterator operator--(int) {
      Iterator tempIter = *this;
      --*this;
      return tempIter;
    };

    T operator*() const {
      if (this->current_node) {
        return this->current_node->data;
      } else {
        throw std::out_of_range("This iterator is nullptr");
      }
    };

   private:
    Node *current_node = nullptr;
  };

  const_reference Front();
  const_reference Back();

  bool Empty() const;
  size_t Size() const;
  size_type MaxSize();
  void Clear();
  void PushBack(const T &value);
  void PopBack();
  void PushFront(const T &value);
  void PopFront();
  void Swap(List<T> &other);
  void Merge(List<T> &other);
  void Unique();
  void Reverse();
  void Sort();
  template <class... Args>
  void EmplaceBack(Args &&...args);

  template <class... Args>
  void EmplaceFront(Args &&...args);

  typedef typename List<T>::Iterator iterator;
  using const_iterator = typename List<T>::Iterator;

  typename List<T>::Iterator Begin();
  typename List<T>::iterator End();

  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator index);
  void Splice(const_iterator pos, List<T> &other);

  template <class... Args>
  iterator Emplace(const_iterator pos, Args &&...args);

 private:
  struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    T data = {};
  };

  Node *head = nullptr;
  Node *tail = nullptr;
  size_type size_ = 0;
  Node *NIL_ = nullptr;
  Node *CreateNIL();
  static Node *GetNil(Node *n);
};
#include "s21_list.inl"
}  // namespace s21
#endif  // SRC_LIST_S21_LIST_H_
