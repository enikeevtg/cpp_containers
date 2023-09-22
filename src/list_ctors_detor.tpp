/*
LIST CTORS/DETOR IMPLEMENTATION FILE
*/

template <typename T>
List<T>::List() : size_(0) {
  end_.prev = &end_;
  end_.next = &end_;
}

template <typename T>
List<T>::List(List<T>::size_type n) : List() {
  value_type* default_value = new value_type;
  for (; n > 0; --n) PushBack(*default_value);
  delete default_value;
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) : List() {
  for (typename std::initializer_list<value_type>::const_iterator
           it = items.begin(),
           end_it = items.end();
       it != end_it; ++it) {
    PushBack(*iter);
  }
}

template <typename T>
List<T>::List(const List& other) : List() {
  for (list_node* node_ptr = (list_node*)end_.next;
       node_ptr != (list_node*)&end_; node_ptr = (list_node*)node_ptr->next) {
    PushBack(node_ptr->value);
  }
}

template <typename T>
List<T>::List(List&& other) : List() {
  Swap(other);
}

template <typename T>
List<T>::~List() {
  Clear();
}

template <typename T>
List<T> List<T>::operator=(List&& other) {
  if (*this != other) {
    Clear();
    Swap(other);
  }
  return *this;
}
