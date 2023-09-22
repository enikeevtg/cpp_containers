/*
LIST EXTRA METHODS IMPLEMENTATION FILE
*/

template <typename T>
void List<T>::PrintEndPtr() {
  std::cout << "\nPrintEndPtr():" << std::endl;
  std::cout << "&end = " << &end_ << std::endl;
  std::cout << "end_.prev = " << end_.prev << std::endl;
  std::cout << "end_.next = " << end_.next << std::endl;
}

template <typename T>
void List<T>::PrintNodes() {
  std::cout << "\nPrintNodes():" << std::endl;
  int i = 1;
  for (ListIterator iter = Begin(); iter != End(); ++iter, ++i) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
  }
}

template <typename T>
void List<T>::ReversePrintNodes() {
  std::cout << "\nReversePrintNodes():" << std::endl;
  int i = Size();
  for (ListIterator iter = --End(); iter != End(); --iter, --i) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
  }
}
