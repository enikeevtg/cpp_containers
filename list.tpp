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
  list_node* ptr = (list_node*)end_.next;
  while (ptr != (list_node*)&end_) {
    list_node* tmp_ptr = (list_node*)ptr->next;
    delete ptr;
    ptr = tmp_ptr;
  }
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
void List<T>::PushFront(const_reference value) {
  // new node
  list_node* new_node = new list_node;
  new_node->prev = &end_;
  new_node->next = end_.next;
  new_node->value = value;

  // exfirst node
  end_.next->prev = (list_node_base*)new_node;

  // node after end node
  if (Empty()) end_.prev = (list_node_base*)new_node;
  end_.next = (list_node_base*)new_node;

  ++size_;
}

// template <typename T>
// void List<T>::PushFront(const_reference value) {
//   Insert(End(), value);
// }

template <typename T>
void List<T>::PushBack(const_reference value) {
  // new node
  list_node* new_node = new list_node;
  new_node->prev = end_.prev;
  new_node->next = &end_;
  new_node->value = value;

  // exlast node
  end_.prev->next = (list_node_base*)new_node;

  // node after end node
  end_.prev = (list_node_base*)new_node;
  if (Empty()) end_.next = (list_node_base*)new_node;

  ++size_;
}

// template <typename T>
// void List<T>::PushBack(const_reference value) {
//   Insert(--End(), value);
// }
