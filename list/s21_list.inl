template <typename T>
List<T>::List() {}

template <typename T>
List<T>::List(size_type n) {
  if (n > MaxSize()) {
    throw std::length_error("cannot create std::List larger than max_size()");
  }
  for (size_t i = 0; i != n; ++i) {
    T value = {};
    PushBack(value);
  }
}

template <typename T>
List<T>::List(const List<T> &s) {
  Node *pointer_head = s.head;
  for (size_t i = 0; i != s.Size(); ++i) {
    PushBack(pointer_head->data);
    pointer_head = pointer_head->next;
  }
}

template <typename T>
List<T>::List(List<T> &&v) {
  Swap(v);
}

template <typename T>
List<T>::~List() {
  while (!Empty()) PopBack();
}

// initializer list constructor (allows creating lists with initializer lists
template <typename T>
List<T>::List(std::initializer_list<value_type> const &items) {
  if (items.size() > MaxSize()) {
    throw std::length_error("cannot create std::List larger than max_size()");
  }

  for (const auto &it : items) PushBack(it);
};

template <typename T>
List<T> &List<T>::operator=(List<T> &&s) {
  Swap(s);
  s.Clear();
  return *this;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &s) {
  Clear();
  Node *pointer_head = s.head;
  for (size_t i = 0; i != s.Size(); ++i) {
    PushBack(pointer_head->data);
    pointer_head = pointer_head->next;
  }
  return *this;
}

template <typename T>
bool List<T>::Empty() const {
  return size_ == 0;
}

template <typename T>
size_t List<T>::Size() const {
  return size_;
}

template <typename T>
void s21::List<T>::PushBack(const T &value) {
  Node *newnode = new Node();
  newnode->data = value;
  if (tail == nullptr) {
    tail = newnode;
    head = newnode;
    NIL_ = CreateNIL();
    newnode->next = NIL_;
    newnode->prev = nullptr;
  } else {
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    tail->next = NIL_;
  }
  NIL_->prev = tail;
  ++size_;
}

template <typename T>
void s21::List<T>::PopBack() {
  if (!Empty()) {
    Node *last = tail;
    if (last->prev) tail = last->prev;
    if (tail) {
      tail->next = NIL_;
    } else {
      head = nullptr;
    }
    --size_;
    NIL_->prev = tail;
    delete last;
  }
  if (size_ == 0) {
    delete NIL_;
    NIL_ = nullptr;
  }
}

template <typename T>
void s21::List<T>::PopFront() {
  if (!Empty()) {
    Node *first = head;
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    --size_;
    delete first;
  }
  if (size_ == 0) {
    delete NIL_;
    NIL_ = nullptr;
  }
}

template <typename T>
typename List<T>::const_reference List<T>::Front() {
  if (Empty()) {
    throw std::length_error(
        "cannot create std::List is empty. Don't use front()");
  }
  return head->data;
}

template <typename T>
typename List<T>::const_reference List<T>::Back() {
  if (Empty()) {
    throw std::length_error(
        "cannot create std::List is empty. Don't use back().");
  }
  return tail->data;
}

template <typename T>
typename List<T>::iterator List<T>::Begin() {
  return iterator(*this->head);
}

template <typename T>
typename List<T>::iterator List<T>::End() {
  return iterator(*this->NIL_);
}

template <typename T>
size_t List<T>::MaxSize() {
  return (LLONG_MAX) / (sizeof(Node));
}

template <typename T>
void s21::List<T>::Clear() {
  while (!Empty()) {
    PopBack();
  }
  head = nullptr;
  tail = nullptr;
  if (NIL_) {
    delete NIL_;
    NIL_ = nullptr;
  }
}

template <typename T>
void List<T>::Swap(List<T> &s) {
  std::swap(head, s.head);
  std::swap(tail, s.tail);
  std::swap(size_, s.size_);
  std::swap(NIL_, s.NIL_);
}

template <typename T>
void s21::List<T>::Erase(iterator it) {
  if (it.current_node == nullptr || it.current_node == NIL_) {
    throw std::out_of_range("Iterator points to nullptr");
  } else if (!Empty()) {
    if (Size() == 1) {
      tail = head = nullptr;
    } else if (it.current_node == head) {
      head = it.current_node->next;
      head->prev = nullptr;
    } else if (it.current_node == tail) {
      tail = it.current_node->prev;
      tail->next = NIL_;
      NIL_->prev = tail;
    } else {
      it.current_node->next->prev = it.current_node->prev;
      it.current_node->prev->next = it.current_node->next;
    }
    delete it.current_node;
    it.current_node = nullptr;
    --size_;
    if (size_ == 0 && NIL_) {
      delete NIL_;
      NIL_ = nullptr;
    }
  }
}

template <typename T>
typename s21::List<T>::iterator s21::List<T>::Insert(iterator it,
                                                     const_reference value) {
  if (it.current_node == nullptr || it.current_node == NIL_) {
    PushBack(value);
    return iterator(*tail);
  }
  if (it.current_node != nullptr) {
    if ((size_ + 1) > MaxSize()) {
      std::out_of_range("Error. Pos is out of range.");
    }

    if (it.current_node->prev == nullptr) {
      PushFront(value);
      it = Begin();
    } else {
      Node *new_node = head;
      Node *temp = head;
      for (iterator new_itr = Begin(); new_itr != it; ++new_itr) {
        new_node = temp;
        temp = temp->next;
      }

      Node *insert_node = new Node;
      insert_node->prev = new_node;
      insert_node->next = temp;
      insert_node->data = value;
      temp->prev = insert_node;
      new_node->next = insert_node;
      NIL_->prev = tail;
      tail->next = NIL_;
      ++size_;
      return iterator(*insert_node);
    }
  }
  NIL_->prev = tail;
  return it;
}

template <typename T>
void s21::List<T>::PushFront(const T &value) {
  Node *newnode = new Node;
  newnode->data = value;
  if (head == nullptr) {
    head = newnode;
    tail = newnode;
    NIL_ = this->CreateNIL();
    newnode->next = NIL_;
    newnode->prev = nullptr;
    NIL_->prev = tail;
  } else {
    head->prev = newnode;
    newnode->next = head;
    newnode->prev = NIL_;
    head = newnode;
  }
  ++size_;
}

template <typename T>
void s21::List<T>::Merge(List<T> &other) {
  if (&other != this) {
    if (!Empty() && !other.Empty()) {
      tail->next = other.head;
      other.head->prev = tail;
      tail = other.tail;
      tail->next = NIL_;
    } else if (Empty() && !other.Empty()) {
      Swap(other);
    }
    Sort();
    size_ = size_ + other.size_;
    if (other.tail) other.tail = nullptr;
    if (other.head) other.head = nullptr;
    other.size_ = 0;
    if (other.NIL_) {
      delete other.NIL_;
      other.NIL_ = nullptr;
    }
    NIL_->prev = tail;
  }
}

template <typename T>
void s21::List<T>::Splice(const_iterator pos, List<T> &other) {
  Node *second_head = nullptr;
  if (!Empty() && !other.Empty()) {
    if (pos != End()) {
      if (pos != Begin()) {
        second_head = pos.current_node->prev->next;
        pos.current_node->prev->next = other.head;
        other.head->prev = pos.current_node->prev;
      } else {
        second_head = head;
        head = other.head;
      }
      other.tail->next = second_head;
      second_head->prev = other.tail;
    } else {
      tail->next = other.head;
      other.head->prev = tail;
      tail = other.tail;
      tail->next = NIL_;
    }
  } else if (Empty() && !other.Empty()) {
    Swap(other);
  }
  size_ = size_ + other.size_;
  if (other.tail) other.tail = nullptr;
  if (other.head) other.head = nullptr;
  NIL_->prev = tail;
  other.size_ = 0;
  if (other.NIL_) {
    delete other.NIL_;
    other.NIL_ = nullptr;
  }
}

template <typename T>
void s21::List<T>::Reverse() {
  if (!Empty()) {
    Node *current = head;
    Node *temp = nullptr;

    for (size_t i = 0; i != Size(); ++i) {
      temp = current->next;
      current->next = current->prev;
      current->prev = temp;
      current = current->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
    tail->next = NIL_;
    NIL_->prev = tail;
    head->prev = nullptr;
  }
}

template <typename T>
void s21::List<T>::Unique() {
  if (Size() > 1) {
    Iterator it = Begin();
    while (it != End()) {
      if (it.current_node && it.current_node->next &&
          (it.current_node->data == it.current_node->next->data)) {
        ++it;
        Erase(it);
        it = Begin();
      } else {
        ++it;
      }
    }
    NIL_->prev = tail;
  }
}

template <typename T>
void s21::List<T>::Sort() {
  if (!Empty()) {
    Node *current = head;
    Node *next_node = head->next;
    int k = 1;
    iterator it;
    while (k > 0) {
      k = 0;
      for (it = Begin(); it != End(); ++it) {
        if (next_node && next_node != NIL_ && current->data > next_node->data) {
          std::swap(current->data, next_node->data);
          ++k;
        }
        current = next_node;
        if (next_node) next_node = next_node->next;
      }
      it = Begin();
      current = head;
      next_node = head->next;
    }
    NIL_->prev = tail;
  }
}

template <typename T>
typename List<T>::Node *List<T>::GetNil(Node *n) {
  if (n == nullptr) return nullptr;

  Node *p = n;
  while (p->next != nullptr) {
    p = p->next;
  }

  return p;
}

template <typename T>
template <class... Args>
void List<T>::EmplaceBack(Args &&...args) {
  iterator pos = End();
  Emplace(pos, args...);
}

template <typename T>
template <class... Args>
void List<T>::EmplaceFront(Args &&...args) {
  iterator pos = Begin();
  Emplace(pos, args...);
}

template <typename T>
template <class... Args>
typename s21::List<T>::iterator List<T>::Emplace(const_iterator pos,
                                                 Args &&...args) {
  typename List<T>::iterator it;
  s21::Vector<value_type> tempVector{args...};
  if (tempVector.Size() == 0) {
    T tmp = {};
    it = Insert(pos, tmp);
  } else {
    for (size_t i = 0; i < tempVector.Size(); ++i) {
      it = Insert(pos, tempVector[i]);
    }
  }
  return it;
}

template <typename T>
typename List<T>::Node *List<T>::CreateNIL() {
  NIL_ = new Node();
  NIL_->prev = NIL_->next;
  return NIL_;
}
