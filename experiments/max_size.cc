#include <math.h>

#include <iostream>
#include <vector>

int main() {
  std::cout << "SIZE_MAX: " << SIZE_MAX << '\n';
  std::cout << "pow(2, 64): " << pow(2, 64) << '\n';
  std::cout << "SIZE_MAX/sizeof(int)/2: " << SIZE_MAX / sizeof(int) / 2 << '\n';
  std::vector<int> vec;
  std::cout << "vec.max_size(): " << vec.max_size();
}
