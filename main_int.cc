#include "list.h"

void ctor_test() {
  std::cout << "ctor_test():\n";
  List<int> l;
  // List<int> l(11);
  // List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // List<int> l_src{21, 20, 0, 1, 2, 3, 4, 5, 6, 11, 7, 8, 9, 10};
  // List<int> l(l_src);
  // List<int> l(std::move(l_src));

  std::cout << "\tlist: " << l;
  std::cout << "\tempty is " << l.Empty() << std::endl;
  std::cout << "\tsize = " << l.Size() << std::endl;
  std::cout << "\tmax size is " << l.MaxSize() << std::endl;

  std::cout << "\n";
}

void insert_test() {
  std::cout << "insert_test():\n";
  List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int value_to_insert = 11;

  std::cout << "\tlist: " << l;
  ListIterator iter = l.Insert(l.Begin(), value_to_insert);
  std::cout << "\t" << value_to_insert << " inserted:\n";
  std::cout << "\t" << l;

  std::cout << "\n";
}

void push_test() {
  std::cout << "push_test():\n";
  List<int> l;
  // List<int> l(11);

  std::cout << "\tlist: " << l;
  l.PushBack(888);
  std::cout << "\tlist after PushBack(): " << l;
  l.PushFront(888);
  std::cout << "\tlist after PushFront(): " << l;

  std::cout << "\n";
}

void incr_iterator_test() {
  std::cout << "incr_iterator_test():\n";
  List<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "\tlist: " << l;
  std::cout << "\t*(l.Begin()++) = " << *(l.Begin()++) << std::endl;
  std::cout << "\t*(++l.Begin()) = " << *(++l.Begin()) << std::endl;

  std::cout << "\n";
}

void sort_test() {
  std::cout << "sort_test():\n";
  // List<int> l{21, 20, 0, 1, 2, 3, 4, 5, 6, 11, 7, 8, 9, 10};
  List<int> l{1, -1, -23, 4, -2};
  std::cout << "\tlist before Sort(): " << l;
  l.Sort();
  std::cout << "\tlist after Sort(): " << l;

  std::cout << "\n";
}

void insert_many_test() {
  std::cout << "insert_many_test():\n";
  List<int> l{5, 6, 7, 8, 9, 10};
  
  std::cout << "\tlist before InsertMany: " << l;
  l.InsertMany(l.CBegin(), 0, 1, 2, 3, 4);
  std::cout << "\tlist after InsertMany: " << l;

  std::cout << "\n";
}

int main() {
  ctor_test();
  insert_test();
  push_test();
  incr_iterator_test();
  sort_test();
  insert_many_test();
  return 0;
}
