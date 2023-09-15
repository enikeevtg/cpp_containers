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
  List() {
    end_.prev = &end_;
    end_.next = &end_;
  }
  ~List() {
    ListNode<T>* ptr = (ListNode<T>*)end_.next;
    while (ptr != (ListNode<T>*)&end_) {
      ListNode<T>* tmp_ptr = (ListNode<T>*)ptr->next;
      delete ptr;
      ptr = tmp_ptr;
    }
  }

  void PushBack(const T& value) {
    ListNode<T>* new_node = new ListNode<T>;
    new_node->prev = end_.prev;
    new_node->next = &end_;
    new_node->value = value;

    (new_node->prev)->next = (ListNodeBase<T>*)new_node;

    end_.prev = (ListNodeBase<T>*)new_node;
    if (end_.next == &end_) end_.next = (ListNodeBase<T>*)new_node;
  }

  void PrintEndPtr() {
    std::cout << "&end = " << &end_ << std::endl;
    std::cout << "end_.prev = " << end_.prev << std::endl;
    std::cout << "end_.next = " << end_.next << std::endl;
  }

  void PrintNodesPtr() {
    ListNode<T>* ptr = (ListNode<T>*)end_.next;
    int i = 1;
    while (ptr != (ListNode<T>*)&end_) {
      std::cout << "node#" << i << " = " << ptr << std::endl;
      std::cout << "node#" << i << ".prev = " << ptr->prev << std::endl;
      std::cout << "node#" << i << ".next = " << ptr->next << std::endl;
      std::cout << "node#" << i << ".value = " << ptr->value << std::endl;
      std::cout << std::endl;
      ptr = (ListNode<T>*)(ptr->next);
      ++i;
    }
  }

 private:
  ListNodeBase<T> end_;
};

// #include "list.tpp"

#endif  // CPP_CONTAINERS_LIST_H_
