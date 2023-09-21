#include "list.h"

int main() {
  List<int> l;
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl << std::endl;

  l.PrintEndPtr();

  int n = 3;
  for (int i = 0; i < n; ++i) {
    l.PushBack(double(i * i));
  }
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  l.PrintNodes();
  std::cout << std::endl;

  int i = l.Size();
  for (ListIterator iter = --(l.End()); iter != --(l.Begin()); --iter, --i) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
  }
  std::cout << "*(l.End()) = " << *(l.End()) << std::endl;

  i = 1;
  int value_to_insert = 11;
  for (ListIterator iter = l.Begin(); iter != l.End(); ++iter, ++i) {
    if (i == 1) {
      iter = l.Insert(iter, value_to_insert);
      iter = l.Insert(iter, 21);
      l.Insert(++iter, 42);
    }
  }
  l.PrintNodes();

  return 0;
}
