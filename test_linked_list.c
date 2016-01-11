#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

void test_for_create_list(){
  LinkedList list = createList();
  assert(list.tail == NULL);
  assert(list.head == NULL);
  assert(list.length == 0);
};
