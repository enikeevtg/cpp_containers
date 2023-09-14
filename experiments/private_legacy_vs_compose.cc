#include <iostream>

template <typename T>
struct ListNodeBase {
  ListNodeBase* prev;
  ListNodeBase* next;
};

template <typename T>
struct ListNode : public ListNodeBase<T> {
  T* data;
};

template <class T>
class List {
 public:
  List() {
    node_.prev = nullptr;
    node_.next = nullptr;
    node_.data = new int();
    }
  ~List() {}

  void PushBack(){
    ListNode<T> new_node = new ListNode<T>;
    new_node.prev = end_.prev;
    if (new_node.prev != nullptr) {
      *(new_node.prev).next = &new_node;
    }
    
    new_node.next = &end_;
    end_.prev = &new_node;
    // ListNode new_node = new ListNode;
    // node_.next = new_node;
    // new_node.prev = node_;
  }

  void PushFront(){};

 private:
  ListNodeBase<T> end_;
  ListNode<T> node_;
};

template <class T>
class StackLegacy : private List<T> {
 public:
  StackLegacy(){};
  ~StackLegacy(){};
  using List<T>::PushFront;
};

template <class T>
class StackCompose {
 public:
  StackCompose(){};
  ~StackCompose(){};

  void PushFront(){list.PushFront()};

 private:
  List<T>* list;
};

int main() {
  List<int> list;
  list.PushBack();
  list.PushBack();
  StackLegacy<int> s_legacy;
  s_legacy.PushFront();
  StackCompose<int> s_compose;
  s_compose.PushFront();

  return 0;
}
