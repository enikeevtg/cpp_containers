#include <string>

#include "list.h"

int main() {
  // List<std::string> l;
  List<std::string> l(11);
  // List<std::string>
  // l{"List<T>","::","List(","std::initializer_list","<value_type>", "const&",
  // "items)"};
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl;

  l.PrintEndPtr();
  l.PrintNodes();
  l.ReversePrintNodes();

  // std::cout << "*(l.End()) = " << *(l.End()) << std::endl;

  // INSERT
  int i = 1;
  std::string value_to_insert = "value_to_insert";
  for (ListIterator iter = l.Begin(); iter != l.End(); ++iter, ++i) {
    if (iter == l.Begin()) {
      iter = l.Insert(l.End(), value_to_insert);
      iter = l.Insert(--l.End(), value_to_insert);
    }
  }
  l.PrintNodes();
  l.PrintEndPtr();
  std::cout << "size = " << l.Size() << std::endl;

  // ITERATOR++ and ++ITERATOR
  std::cout << "*(l.Begin()++) = " << *(l.Begin()++) << std::endl;
  std::cout << "*(++l.Begin()) = " << *(++l.Begin()) << std::endl;

  l.PushFront("PushFront()");
  l.PrintNodes();
  l.PushBack("PushBack()");
  l.PrintNodes();

  return 0;
}
