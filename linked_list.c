#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList createList(void){
  LinkedList linked_list ;
  linked_list.length = 0;
  linked_list.tail = NULL;
  linked_list.head = NULL;
  return linked_list;
};
