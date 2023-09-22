#include "list.h"

int main() {
  // List<int> l;
  List<int> l(11);
  // List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl;

  l.PrintEndPtr();
  l.PrintNodes();
  l.ReversePrintNodes();

  std::cout << "*(l.End()) = " << *(l.End()) << std::endl;

  // INSERT
  int i = 1;
  int value_to_insert = 11;
  for (ListIterator iter = l.Begin(); iter != l.End(); ++iter, ++i) {
    if (iter == l.Begin()) {
      iter = l.Insert(l.End(), value_to_insert);
      iter = l.Insert(--l.End(), 121);
    }
  }
  l.PrintNodes();
  l.PrintEndPtr();
  std::cout << "size = " << l.Size() << std::endl;

  // ITERATOR++ and ++ITERATOR
  std::cout << "*(l.Begin()++) = " << *(l.Begin()++) << std::endl;
  std::cout << "*(++l.Begin()) = " << *(++l.Begin()) << std::endl;

  l.PushFront(888);
  l.PrintNodes();
  l.PushBack(888);
  l.PrintNodes();

  return 0;
}
