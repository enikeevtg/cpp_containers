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
  for (; n > 0; --n) PushBack(0);
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) : List() {
  for (typename std::initializer_list<value_type>::const_iterator
           iter = items.begin(),
           end_iter = items.end();
       iter != end_iter; ++iter) {
    PushBack(*iter);
  }
}

template <typename T>
List<T>::~List() {
  Clear();
}
