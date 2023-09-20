#include "list.h"

int main() {
  List<double> l;
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
  for (ListIterator iter = --(l.End()); iter != --(l.Begin()); --iter) {
    std::cout << "node#" << i << ".value = " << *iter << std::endl;
    --i;
  }
  std::cout << "*(l.End()) = " << *(l.End()) << std::endl;

  return 0;
}
