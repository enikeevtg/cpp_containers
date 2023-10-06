#include "list.h"

void ctor_test() {
  List<int> l;
  // List<int> l(11);
  // List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // List<int> l_src{21, 20, 0, 1, 2, 3, 4, 5, 6, 11, 7, 8, 9, 10};
  // List<int> l(l_src);
  // List<int> l(std::move(l_src));

  l.PrintNodes();
  std::cout << "empty is " << l.Empty() << std::endl;
  std::cout << "size = " << l.Size() << std::endl;
  std::cout << "max size is " << l.MaxSize() << std::endl;
}

void insert_test() {
  List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int value_to_insert = 11;

  // l.PrintNodes();
  std::cout << l;
  ListIterator iter = l.Insert(l.Begin(), value_to_insert);
  std::cout << value_to_insert << " inserted:\n";
  // l.PrintNodes();
  std::cout << l;
}

void push_test() {
  List<int> l(11);

  l.PrintNodes();
  l.PushFront(888);
  l.PrintNodes();
  l.PushBack(888);
  l.PrintNodes();
}

void incr_iterator_test() {
  List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "*(l.Begin()++) = " << *(l.Begin()++) << std::endl;
  std::cout << "*(++l.Begin()) = " << *(++l.Begin()) << std::endl;
}

void sort_test() {
  // List<int> l_src{21, 20, 0, 1, 2, 3, 4, 5, 6, 11, 7, 8, 9, 10};
  List<int> l_src{1, -1, -23, 4, -2};
  l_src.Sort();
  l_src.PrintNodes();
}

int main() {
  // ctor_test();
  insert_test();
  // push_test();
  // incr_iterator_test();
  // sort_test();
  return 0;
}
