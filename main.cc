#include "list.h"

int main() {
  List<int> l(11);
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl;

  l.PrintEndPtr();

  // PUSHBACK
  // int n = 3;
  // for (int i = 0; i < n; ++i) {
  //   l.PushBack(double(i * i));
  // }
  // std::cout << "empty is " << l.Empty() << std::endl;
  // std::cout << "size = " << l.Size() << std::endl;
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
  ListIterator iter_pre = l.Begin();
  ListIterator iter_post = l.Begin();
  std::cout << "*(++iter_pre) = " << *(++iter_pre) << std::endl;
  std::cout << "*(iter_post)++ = " << *(iter_post)++ << std::endl;
  std::cout << "*iter_post = " << *iter_post << std::endl;

  l.PushFront(800);
  l.PrintNodes();

  return 0;
}
