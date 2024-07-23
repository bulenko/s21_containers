template <typename T, class Container>
Queue<T, Container>::Queue() {}

template <typename T, class Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> const &items) {
  for (const auto &it : items) Push(it);
}

template <typename T, class Container>
Queue<T, Container>::Queue(const Queue &s) {
  this->container_ = s.container_;
}

template <typename T, class Container>
Queue<T, Container>::Queue(const Container &s) {
  container_(s);
}

template <typename T, class Container>
Queue<T, Container>::Queue(Queue &&s) {
  Swap(s);
}

template <typename T, class Container>
Queue<T, Container>::~Queue() {}

template <typename T, class Container>
Queue<T, Container> &Queue<T, Container>::operator=(
    const Queue<T, Container> &s) {
  if (this != &s) {
    MakeEmptyQueue();
    this->container_ = s.container_;
  }
  return *this;
}

template <typename T, class Container>
Queue<T, Container> &Queue<T, Container>::operator=(Queue &&s) {
  Swap(s);
  s.MakeEmptyQueue();
  return *this;
}

template <typename T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::Front() {
  if (Empty()) {
    throw std::out_of_range("Stack is empty.");
  }
  return container_.Front();
}

template <typename T, class Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::Back() {
  if (Empty()) {
    throw std::out_of_range("Stack is empty.");
  }
  return container_.Back();
}

template <typename T, class Container>
bool Queue<T, Container>::Empty() const {
  return container_.Empty();
}

template <typename T, class Container>
size_t Queue<T, Container>::Size() {
  return container_.Size();
}

template <typename T, class Container>
void Queue<T, Container>::Push(
    typename Queue<T, Container>::const_reference value) {
  container_.PushBack(value);
}

// removes the first element
template <typename T, class Container>
void Queue<T, Container>::Pop() {
  if (!Empty()) {
    container_.PopFront();
  }
}

// swaps the contents
template <typename T, class Container>
void Queue<T, Container>::Swap(Queue &other) {
  Queue temp;
  temp.container_ = other.container_;
  other.container_ = this->container_;
  this->container_ = temp.container_;
}

template <typename T, class Container>
void Queue<T, Container>::MakeEmptyQueue() {
  while (!Empty()) {
    Pop();
  }
}

template <typename T, class Container>
template <class... Args>
void Queue<T, Container>::EmplaceBack(Args &&...args) {
  container_.EmplaceBack(args...);
}
