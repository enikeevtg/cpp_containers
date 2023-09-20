#ifndef CPP_CONTAINERS_LIST_H_
#define CPP_CONTAINERS_LIST_H_

#include <iostream>

template <typename T>
struct ListNodeBase {
  ListNodeBase<T>* prev;
  ListNodeBase<T>* next;
};

template <typename T>
struct ListNode : public ListNodeBase<T> {
  T value;
};

template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  // using iterator = ListIterator<T>;
  // using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  List();
  ~List();

  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Clear();
  void PushBack(const_reference value);

  void PrintEndPtr();
  void PrintNodes();

 private:
  ListNodeBase<T> end_;
  size_type size_;
};

#include "list.tpp"

#endif  // CPP_CONTAINERS_LIST_H_
