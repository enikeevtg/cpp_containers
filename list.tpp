/*
LIST IMPLEMENTATION FILE
*/

template <typename T>
List<T>::List() : size_(0) {
  end_.prev = &end_;
  end_.next = &end_;
}

template <typename T>
List<T>::~List() {
  Clear();
}

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
}

template <typename T>
void List<T>::PushBack(const_reference value) {
  list_node* new_node = new list_node;
  new_node->prev = end_.prev;
  new_node->next = &end_;
  new_node->value = value;

  (new_node->prev)->next = (list_node_base*)new_node;

  end_.prev = (list_node_base*)new_node;
  if (end_.next == &end_) end_.next = (list_node_base*)new_node;

  ++size_;
}

template <typename T>
void List<T>::PrintEndPtr() {
  std::cout << "&end = " << &end_ << std::endl;
  std::cout << "end_.prev = " << end_.prev << std::endl;
  std::cout << "end_.next = " << end_.next << std::endl;
  std::cout << std::endl;
}

template <typename T>
void List<T>::PrintNodes() {
  int i = 1;
  for (ListIterator iter = Begin(); iter != End(); ++iter, ++i) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
  }
}
