#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList createList(void){
  LinkedList linked_list ;
  linked_list.length = 0;
  linked_list.last_element = NULL;
  linked_list.first_element = NULL;
  return linked_list;
};

int add_to_list(LinkedList *linked_list,void *value){
  Element *ele = (Element *)malloc(sizeof(Element));
  ele->value = value;
  ele->next = NULL;
  if (linked_list -> length == 0){
    linked_list -> first_element = ele;
    linked_list -> last_element = ele;
  }else{
    linked_list -> last_element->next = ele;
    linked_list -> last_element = ele;
  }
  linked_list->length++;
  return linked_list -> length;
};
