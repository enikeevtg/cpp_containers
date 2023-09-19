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
  List();
  ~List();

  void PushBack(const T& value);

  void PrintEndPtr();
  void PrintNodes();

 private:
  ListNodeBase<T> end_;
};

#include "list.tpp"

#endif  // CPP_CONTAINERS_LIST_H_
