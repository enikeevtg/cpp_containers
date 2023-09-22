/*
LIST IMPLEMENTATION FILE
*/

template <typename T>
void List<T>::PushFront(const_reference value) {
  Insert(End(), value);
}

template <typename T>
void List<T>::PushBack(const_reference value) {
  Insert(--End(), value);
}
