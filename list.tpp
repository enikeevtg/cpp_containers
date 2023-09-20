/*
LIST IMPLEMENTATION FILE
*/

template <class T>
List<T>::List() : size_(0) {
  end_.prev = &end_;
  end_.next = &end_;
}

template <class T>
List<T>::~List() {
  Clear();
}

template <class T>
bool List<T>::Empty() const noexcept {
  return size_ == 0;
}

template <class T>
size_t List<T>::Size() const noexcept {
  return size_;
}

template <class T>
size_t List<T>::MaxSize() const noexcept {
  // std::cout << "SIZE_MAX = " << SIZE_MAX << std::endl;
  // std::cout << "sizeof(ListNodeBase<T>) = " << sizeof(ListNodeBase<T>)
  //           << std::endl;
  // std::cout << "sizeof(ListNode<T>) = " << sizeof(ListNode<T>) << std::endl;
  return (SIZE_MAX - sizeof(ListNodeBase<T>)) / sizeof(ListNode<T>);
}

template <class T>
void List<T>::Clear() {
  ListNode<T>* ptr = (ListNode<T>*)end_.next;
  while (ptr != (ListNode<T>*)&end_) {
    ListNode<T>* tmp_ptr = (ListNode<T>*)ptr->next;
    delete ptr;
    ptr = tmp_ptr;
  }
}

template <class T>
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

template <class T>
void List<T>::PrintEndPtr() {
  std::cout << "&end = " << &end_ << std::endl;
  std::cout << "end_.prev = " << end_.prev << std::endl;
  std::cout << "end_.next = " << end_.next << std::endl;
  std::cout << std::endl;
}

template <class T>
void List<T>::PrintNodes() {
  int i = 1;
  for (ListIterator<T> iter = Begin(); iter != End(); ++iter, ++i) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
  }
}

// template <class T>
// void List<T>::PrintNodes() {
//   ListNode<T>* ptr = (ListNode<T>*)end_.next;
//   int i = 1;
//   while (ptr != (ListNode<T>*)&end_) {
//     std::cout << "node#" << i << " = " << ptr << std::endl;
//     std::cout << "node#" << i << ".prev = " << ptr->prev << std::endl;
//     std::cout << "node#" << i << ".next = " << ptr->next << std::endl;
//     std::cout << "node#" << i << ".value = " << ptr->value << std::endl;
//     std::cout << std::endl;
//     ptr = (ListNode<T>*)(ptr->next);
//     ++i;
//   }
// }
