
Iterator() : current_node(nullptr) {}
Iterator(Node &other) : current_node(&other) {}

Iterator &operator++() {
  if (current_node != GetNil(current_node)) {
    current_node = current_node->next;
  }
  return *this;
}

Iterator operator++(int) {
  Iterator tempIter = *this;
  ++*this;
  return tempIter;
}

bool operator!=(const Iterator &other) const {
  return this->current_node != other.current_node;
}

bool operator==(const Iterator &other) const {
  return this->current_node == other.current_node;
}

Iterator &operator--() {
  if (current_node != nullptr) {
    current_node = current_node->prev;
  }
  return *this;
}

Iterator operator--(int) {
  Iterator tempIter = *this;
  --*this;
  return tempIter;
}

T operator*() const {
  if (this->current_node) {
    return this->current_node->data;
  } else {
    throw std::out_of_range("This iterator is nullptr");
  }
}
