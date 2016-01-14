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

void *get_first_element(LinkedList linked_list){
  return linked_list.first_element ->value;
};

void *get_last_element(LinkedList linked_list){
  return linked_list.last_element ->value;
};

void forEach(LinkedList list, ElementProcessor func){
  Element *ele = list.first_element;
  while(ele != NULL){
    func(ele ->value);
    ele = ele -> next;
  }
};

void * getElementAt(LinkedList list, int position){
  if(position < 0 || position > list.length - 1) return NULL;
  for (int i = 0; i < position; i++) {
    list.first_element = list.first_element -> next;
  };
  return list.first_element -> value;
};

int indexOf(LinkedList list, void *element){
  for (int i = 0; i < list.length; i++) {
    if(list.first_element ->value == element) return i;
    list.first_element = list.first_element -> next;
  };
  return -1;
};

void * deleteElementAt(LinkedList *list, int position){
  if(position > list->length || position < 0) return NULL;
    Element *element = list->first_element;
    Element *deletedElement;
    if(position == 0) {
      deletedElement = list->first_element;
      list->first_element = list->first_element->next;
    }else{
      for(int i = 0;i < position - 1; i++){
        element = element->next;
      };
      if(position == list->length-1){
        deletedElement = element->next;
        list->last_element = element;
      }else{
        deletedElement = element->next;
        element->next = element->next->next;
      }
    }
    list->length--;
    free(deletedElement);
    return deletedElement->value;
};

int asArray(LinkedList list, void ** array, int maxElements){
  int limit = (maxElements < list.length) ? maxElements : list.length;
  Element *ele = list.first_element;
  for(int i = 0;i < limit; i++){
    array[i] = ele->value;
    ele = ele->next;
  };
  return limit;
};

LinkedList filter(LinkedList list, MatchFunc func, void *hint){
  LinkedList filtered_list = createList();
  Element *ele = list.first_element;
  for(int i=0; i<list.length; i++){
    if(func(hint, ele->value))
      add_to_list(&filtered_list, ele->value);
    ele = ele->next;
  };
  return filtered_list;
};

LinkedList reverse(LinkedList list){
  LinkedList reversed = createList();
  void *arrayUtil = calloc(list.length,8);
  void **array = arrayUtil;
  asArray(list, array, list.length);
  for(int i = list.length-1; i >= 0; i--){
    add_to_list(&reversed, array[i]);
  };
  return reversed;
};
