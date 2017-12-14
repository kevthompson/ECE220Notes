void add_record(Record **list, int new_UIN)
{
  Record* new_node = malloc(sizeof(Record));
  Record* new_node->next = malloc(sizeof(Record));
  new_node->UIN = new_UIN;
  int index = 0;
  while((list[index])->UIN < new_UIN && (list[index]->UIN != NULL))
  {
    index++;
  }
  if(list[index]->UIN == new_UIN)
  {
      printf("Student already in database.\n");
      free(new_node);
      return;
  }
  else
  {
    new_node->next = list[index];
    list[index-1]->next = new_node;
    return;
  }
  printf("something went wrong");
  return -1;
}
