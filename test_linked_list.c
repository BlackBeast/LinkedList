#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

void test_for_create_list(){
  LinkedList list = createList();
  assert(list.last_element == NULL);
  assert(list.first_element == NULL);
  assert(list.length == 0);
};

void test_for_checking_add_to_list_with_a_number_providing(){
  LinkedList list = createList();
  int num = 5;
  add_to_list(&list,&num);
  int value = *(int*)list.first_element->value;
  assert(value == 5);
};
