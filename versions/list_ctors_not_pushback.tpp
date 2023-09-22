/*
LIST CTORS/DETOR IMPLEMENTATION FILE
*/

template <typename T>
List<T>::List(List<T>::size_type n) : size_(n) {
  list_node_base* tmp_prev_node = &end_;
  list_node* new_node;
  while (n-- > 0) {
    new_node = new list_node;
    tmp_prev_node->next = (list_node_base*)new_node;
    new_node->prev = tmp_prev_node;
    new_node->value = (List<T>::value_type)0;
    tmp_prev_node = (list_node_base*)new_node;
  }
  new_node->next = &end_;
  end_.prev = (list_node_base*)new_node;
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const& items) {
  typename std::initializer_list<value_type>::const_iterator iter =
      items.begin();
  typename std::initializer_list<value_type>::const_iterator end_iter =
      items.end();
  list_node_base* tmp_prev_node = &end_;
  list_node* new_node;
  while (iter != end_iter) {
    ++size_;
    new_node = new list_node;
    tmp_prev_node->next = (list_node_base*)new_node;
    new_node->prev = tmp_prev_node;
    new_node->value = *iter;
    tmp_prev_node = (list_node_base*)new_node;
    ++iter;
  }
  new_node->next = &end_;
  end_.prev = (list_node_base*)new_node;
}
