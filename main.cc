#include "list.h"

int main() {
  List<int> l;
  l.PrintEndPtr();
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PushBack(rand() % 10 + 1);
  l.PrintNodesPtr();
  return 0;
}
