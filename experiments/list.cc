#include <iostream>
#include <list>
#include <string>

int main() {
  std::list<std::string> l(11);
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  // int:
  std::cout << "int\n";
  std::list<int> l_int{1, 2, 3, 9, 15, 11};
  for (auto i = l_int.begin(); i != l_int.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_int.end()); i != l_int.begin(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_int.end()); i != l_int.end(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  std::cout << "*l_int.end() = " << *l_int.end() << std::endl;
  std::cout << "*l_int.max_size() = " << l_int.max_size() << std::endl;
  //-----------------------------------------------------------------

  // double:
  std::cout << "double\n";
  std::list<double> l_double{1.f, 2.f, 3.f, 9.f};
  for (auto i = l_double.begin(); i != l_double.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_double.end()); i != l_double.begin(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_double.end()); i != l_double.end(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  std::cout << "*l_double.end() = " << *l_double.end() << std::endl;
  //-----------------------------------------------------------------

  // string:
  std::cout << "string\n";
  std::list<std::string> l_str(10);
  // std::list<std::string> l_str{"1.f", "2.f", "3.f", "9.f"};
  for (auto i = l_str.begin(); i != l_str.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_str.end()); i != l_str.begin(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  for (auto i = --(l_str.end()); i != l_str.end(); --i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
  // std::cout << "*l_str.end() = " << *l_str.end();

  return 0;
}
