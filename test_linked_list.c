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

void test_for_getting_the_first_element_from_the_list(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 3;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  int value = *(int*)get_first_element(list);
  assert(value == 2);
};

void test_for_getting_the_first_element_from_the_list_using_characters(){
  LinkedList list = createList();
  char char1 = 'a';
  char char2 = 'b';
  add_to_list(&list,&char1);
  char value = *(char *)get_first_element(list);
  assert(value == 'a');
  add_to_list(&list,&char2);
  char result = *(char *)get_first_element(list);
  assert(result == 'a');
};

void test_for_getting_the_last_element_from_the_list(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 3;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  int value = *(int*)get_last_element(list);
  assert(value == 3);
};

void test_for_getting_the_last_element_from_the_list_using_characters(){
  LinkedList list = createList();
  char char1 = 'a';
  char char2 = 'b';
  add_to_list(&list,&char1);
  char value = *(char *)get_last_element(list);
  assert(value == 'a');
  add_to_list(&list,&char2);
  char result = *(char *)get_last_element(list);
  assert(result == 'b');
};
