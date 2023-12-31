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

// LIST ITERATORS
template <typename T>
class ListIterator {
 public:
  using iterator = ListIterator;
  using value_type = T;
  using reference = T&;
  using size_type = size_t;

  ListIterator() noexcept : ptr_(nullptr){};
  explicit ListIterator(ListNode<T>* list_node_ptr) noexcept
      : ptr_(list_node_ptr){};
  ~ListIterator() noexcept { ptr_ = nullptr; };

  reference operator*() const { return ptr_->value; }

  iterator operator+(size_type offset) const {
    iterator iter{this->ptr_};
    for (size_type i = 0; i < offset; ++i) {
      iter.ptr_ = (ListNode<T>*)iter.ptr_->next;
    }
    return iter;
  }

  iterator& operator++() {
    ptr_ = (ListNode<T>*)ptr_->next;
    return *this;
  }

  iterator operator++(int) {
    iterator tmp = *this;
    ptr_ = (ListNode<T>*)ptr_->next;
    return tmp;
  }

  iterator operator-(size_type offset) const {
    iterator iter{this->ptr_};
    for (size_type i = 0; i < offset; ++i) {
      iter.ptr_ = (ListNode<T>*)iter.ptr_->prev;
    }
    return iter;
  }

  iterator& operator--() {
    ptr_ = (ListNode<T>*)ptr_->prev;
    return *this;
  }

  iterator operator--(int) {
    iterator tmp = *this;
    ptr_ = (ListNode<T>*)ptr_->prev;
    return tmp;
  }

  bool operator==(const iterator& iter) const {
    return ptr_ == (ListNode<T>*)iter.ptr_;
  }

  bool operator!=(const iterator& iter) const { return !(*this == iter); }

 private:
  ListNode<T>* ptr_;

  template <typename>
  friend class List;
};

template <typename T>
class ListConstIterator {
 public:
  using const_iterator = ListConstIterator;
  using value_type = T;
  using const_reference = const T&;
  using size_type = size_t;

  ListConstIterator() noexcept : ptr_(nullptr){};
  ListConstIterator(ListNode<T>* list_node_ptr) noexcept
      : ptr_(list_node_ptr){};
  ~ListConstIterator() noexcept { ptr_ = nullptr; };

  const_reference operator*() const { return ptr_->value; }

  const_iterator operator+(size_type offset) const {
    const_iterator iter{this->ptr_};
    for (size_type i = 0; i < offset; ++i) {
      iter.ptr_ = (ListNode<T>*)iter.ptr_->next;
    }
    return iter;
  }

  const_iterator& operator++() {
    ptr_ = (ListNode<T>*)ptr_->next;
    return *this;
  }

  const_iterator operator++(int) {
    const_iterator tmp = *this;
    ptr_ = (ListNode<T>*)ptr_->next;
    return tmp;
  }

  const_iterator operator-(size_type offset) const {
    const_iterator iter{this->ptr_};
    for (size_type i = 0; i < offset; ++i) {
      iter.ptr_ = (ListNode<T>*)iter.ptr_->prev;
    }
    return iter;
  }

  const_iterator& operator--() {
    ptr_ = (ListNode<T>*)ptr_->prev;
    return *this;
  }

  const_iterator operator--(int) {
    const_iterator tmp = *this;
    ptr_ = (ListNode<T>*)ptr_->prev;
    return tmp;
  }

  bool operator==(const const_iterator& iter) {
    return ptr_ == (ListNode<T>*)iter.ptr_;
  }

  bool operator!=(const const_iterator& iter) { return !(*this == iter); }

 private:
  ListNode<T>* ptr_;

  template <typename>
  friend class List;
};

// LIST CLASS
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
  explicit List(size_type n);
  List(std::initializer_list<value_type> const& items);
  List(const List& other);
  List(List&& other);
  ~List();
  List operator=(List&& other);

  const_reference Front();
  const_reference Front() const;
  const_reference Back();
  const_reference Back() const;

  iterator Begin() noexcept;
  iterator End() noexcept;
  const_iterator Begin() const noexcept;
  const_iterator End() const noexcept;
  const_iterator CBegin() const noexcept;
  const_iterator CEnd() const noexcept;

  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Clear();
  iterator Insert(iterator pos, const_reference value);
  iterator Erase(iterator pos);
  void PushBack(const_reference value);
  void PopBack();
  void PushFront(const_reference value);
  void PopFront();
  void Swap(List& other) noexcept;
  void Merge(List& other);
  void Reverse();
  void Sort();

  template <typename... Args>
  iterator InsertMany(const_iterator pos, Args&&... args);

  void PrintEndPtr();
  void PrintNodes();
  void ReversePrintNodes();

 private:
  void QuickSort(iterator begin, iterator end);

  list_node_base end_;
  size_type size_;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list);

#include "src/list.tpp"
#include "src/list_ctors_detor.tpp"
#include "src/list_extra.tpp"

#endif  // CPP_CONTAINERS_LIST_H_
