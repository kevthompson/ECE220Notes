Record *find_record(Record *head, int UIN)
{
  next_node = head->next;
  cur_node = head;
  while(cur_node != NULL && cur_node->UIN <= UIN)
  {
    if(cur_node->UIN == UIN)
    {
      return cur_node
    }
    else
    {
      cur_node = next_node;
      next_node = cur_node->next;
    }
  }
  return NULL;
}

void remove_node(Record ** list, int old_UIN)
{
  cur_node = *(list);
  next_node = cur_node->next;
  next_next_node = next_node->next;
  while(next_node != NULL && cur_node->UIN >= old_UIN)
  {
    if(next_node->UIN == UIN)
    {
      cur_node->next = next_node
    }
  }
}
