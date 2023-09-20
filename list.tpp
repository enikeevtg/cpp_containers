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
  return iterator((ListNode<T>*)end_.next);
}

template <typename T>
typename List<T>::const_iterator List<T>::Begin() const noexcept {
  return const_iterator((ListNode<T>*)end_.next);
}

template <typename T>
typename List<T>::iterator List<T>::End() noexcept {
  return iterator((ListNode<T>*)&end_);
}

template <typename T>
typename List<T>::const_iterator List<T>::End() const noexcept {
  return const_iterator((ListNode<T>*)&end_);
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
  return (SIZE_MAX - sizeof(ListNodeBase<T>)) / sizeof(ListNode<T>);
}

// LIST MODIFIERS
template <typename T>
void List<T>::Clear() {
  ListNode<T>* ptr = (ListNode<T>*)end_.next;
  while (ptr != (ListNode<T>*)&end_) {
    ListNode<T>* tmp_ptr = (ListNode<T>*)ptr->next;
    delete ptr;
    ptr = tmp_ptr;
  }
}

template <typename T>
void List<T>::PushBack(const_reference value) {
  ListNode<T>* new_node = new ListNode<T>;
  new_node->prev = end_.prev;
  new_node->next = &end_;
  new_node->value = value;

  (new_node->prev)->next = (ListNodeBase<T>*)new_node;

  end_.prev = (ListNodeBase<T>*)new_node;
  if (end_.next == &end_) end_.next = (ListNodeBase<T>*)new_node;

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
