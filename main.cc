#include "list.h"

int main() {
  List<int> l;
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl << std::endl;
  l.PrintEndPtr();
  int n = 11;
  for (int i = 0; i < n; ++i) {
    l.PushBack(i * i);
  }
  // l.PrintNodes();
  std::cout << "size = " << l.Size() << std::endl;
  return 0;
}
