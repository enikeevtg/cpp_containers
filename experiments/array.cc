#include <array>
#include <iostream>

template <class T, std::size_t N>
struct array_ {
  T data[N];
  T operator[](int i) { return data[i]; }
};

int main() {
  // std::array<int, 3> b;
  // for (int i = 0; i < 3; ++i) {
  //   std::cout << b[i] << std::endl;
  // }

  // array_<int, 5> arr = {1, 2, 3, 4, 5};
  // for (int i = 0; i < 5; ++i) {
  //   std::cout << arr[i] << std::endl;
  // }

  array_<int, 3> arr1;
  for (int i = 0; i < 3; ++i) {
    std::cout << arr1[i] << std::endl;
  }

  return 0;
}
