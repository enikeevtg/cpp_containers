#ifndef CPP_CONTAINERS_LIST_H_
#define CPP_CONTAINERS_LIST_H_

#include <iostream>

// STRUCTS
template <typename T>
struct ListNodeBase {
  ListNodeBase<T>* prev;
  ListNodeBase<T>* next;
};

template <typename T>
struct ListNode : public ListNodeBase<T> {
  T value;
};

// LIST ITERATOR
template <class T>
class ListIterator {
 public:
  using value_type = T;
  using reference = T&;

  ListIterator() noexcept : ptr_(nullptr){};
  ListIterator(ListNode<T>* list_node_ptr) noexcept : ptr_(list_node_ptr){};
  ~ListIterator() noexcept { ptr_ = nullptr; };

  reference operator*() const {
    return ptr_->value;
  }

  ListIterator& operator++() {
    ptr_ = (ListNode<T>*)ptr_->next;
    return *this;
  }

  ListIterator& operator--() {
    ptr_ = (ListNode<T>*)ptr_->prev;
    return *this;
  }

  friend bool operator==(const ListIterator& left, const ListIterator& right) {
    return left.ptr_ == (ListNode<T>*)right.ptr_;
  }

  friend bool operator!=(const ListIterator& left, const ListIterator& right) {
    return !(left == right);
  }

 private:
  ListNode<T>* ptr_;
};

// LIST
template <class T>
class List {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  // using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  List();
  ~List();

  iterator Begin() { return iterator((ListNode<T>*)end_.next); }
  iterator End() { return iterator((ListNode<T>*)&end_); }

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
