/*
LIST IMPLEMENTATION FILE
*/

// LIST ITERATORS
template <typename T>
typename List<T>::iterator List<T>::Begin() noexcept {
  return iterator((list_node*)end_.next);
}

template <typename T>
typename List<T>::const_iterator List<T>::Begin() const noexcept {
  return const_iterator((list_node*)end_.next);
}

template <typename T>
typename List<T>::iterator List<T>::End() noexcept {
  return iterator((list_node*)&end_);
}

template <typename T>
typename List<T>::const_iterator List<T>::End() const noexcept {
  return const_iterator((list_node*)&end_);
}

// LIST CAPACITY
template <typename T>
bool List<T>::Empty() const noexcept {
  return size_ == 0;
}

template <class T>
size_t List<T>::Size() const noexcept {
  return size_;
}

template <typename T>
size_t List<T>::MaxSize() const noexcept {
  return (SIZE_MAX - sizeof(list_node_base)) / sizeof(list_node);
}

// LIST MODIFIERS
template <typename T>
void List<T>::Clear() {
  list_node* node_ptr = (list_node*)end_.next;
  list_node* end_node_ptr = (list_node*)&end_;
  while (node_ptr != end_node_ptr) {
    list_node* next_node_ptr = (list_node*)node_ptr->next;
    delete node_ptr;
    node_ptr = next_node_ptr;
  }
  end_.next = &end_;
  end_.prev = &end_;
  size_ = 0;
}

template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos,
                                           const_reference value) {
  list_node* new_node = new list_node;
  new_node->prev = pos.ptr_;
  new_node->next = pos.ptr_->next;
  new_node->value = value;

  pos.ptr_->next->prev = new_node;
  pos.ptr_->next = new_node;

  ++size_;

  return ++pos;
}

template <typename T>
void List<T>::Erase(iterator pos) {
  if (pos != End()) {
    pos.ptr_->prev->next = pos.ptr_->next;
    pos.ptr_->next->prev = pos.ptr_->prev;
    delete pos.ptr_;
    --size_;
  }
}

template <typename T>
void List<T>::PushBack(const_reference value) {
  // new node
  list_node* new_node = new list_node;
  new_node->prev = end_.prev;
  new_node->next = &end_;
  new_node->value = value;

  // exlast node
  end_.prev->next = (list_node_base*)new_node;

  // node after last node
  end_.prev = (list_node_base*)new_node;
  if (Empty()) end_.next = (list_node_base*)new_node;

  ++size_;
}

template <typename T>
void List<T>::PushFront(const_reference value) {
  // new node
  list_node* new_node = new list_node;
  new_node->prev = &end_;
  new_node->next = end_.next;
  new_node->value = value;

  // exfirst node
  end_.next->prev = (list_node_base*)new_node;

  // node after last node
  if (Empty()) end_.prev = (list_node_base*)new_node;
  end_.next = (list_node_base*)new_node;

  ++size_;
}

template <typename T>
void List<T>::Swap(List& other) noexcept {
  std::swap(end_.next, other.end_.next);
  std::swap(end_.prev, other.end_.prev);
  std::swap(size_, other.size_);

  if (size_ == 0) {
    end_.prev = &end_;
    end_.next = &end_;
  } else {
    end_.prev->next = &end_;
    end_.next->prev = &end_;
  }

  if (other.size_ == 0) {
    other.end_.prev = &other.end_;
    other.end_.next = &other.end_;
  } else {
    other.end_.prev->next = &other.end_;
    other.end_.next->prev = &other.end_;
  }
}
