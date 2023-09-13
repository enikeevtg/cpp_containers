#include <iostream>
#include <list>

int main() {
  std::list<int> l{1, 2, 3, 9};
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << *l.end();
  return 0;
}
