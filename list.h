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
template <typename T>
class ListIterator {
 public:
  using value_type = T;
  using reference = T&;

  ListIterator() noexcept : ptr_(nullptr){};
  explicit ListIterator(ListNode<T>* list_node_ptr) noexcept
      : ptr_(list_node_ptr){};
  ~ListIterator() noexcept { ptr_ = nullptr; };

  reference operator*() const { return ptr_->value; }

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

template <typename T>
class ListConstIterator {
 public:
  using value_type = T;
  using const_reference = const T&;

  ListConstIterator() noexcept : ptr_(nullptr){};
  ListConstIterator(ListNode<T>* list_node_ptr) noexcept
      : ptr_(list_node_ptr){};
  ~ListConstIterator() noexcept { ptr_ = nullptr; };

  const_reference operator*() const { return ptr_->value; }

  ListConstIterator& operator++() {
    ptr_ = (ListNode<T>*)ptr_->next;
    return *this;
  }

  ListConstIterator& operator--() {
    ptr_ = (ListNode<T>*)ptr_->prev;
    return *this;
  }

  friend bool operator==(const ListConstIterator& left,
                         const ListConstIterator& right) {
    return left.ptr_ == (ListNode<T>*)right.ptr_;
  }

  friend bool operator!=(const ListConstIterator& left,
                         const ListConstIterator& right) {
    return !(left == right);
  }

 private:
  ListNode<T>* ptr_;
};

// LIST
template <typename T>
class List {
 public:
  using list_node_base = ListNodeBase<T>;
  using list_node = ListNode<T>;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  List();
  ~List();

  iterator Begin() noexcept;
  const_iterator Begin() const noexcept;
  iterator End() noexcept;
  const_iterator End() const noexcept;

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
