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

void square_of(void* item){
  *(int*)item = (*(int*)item)*(*(int*)item);
};


void increment(void *value){
	(*(int *)value)++;
};

void test_for_checking_forEach_using_a_traverse_function(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 4;
  int num3 = 6;
  int num4 = 8;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  add_to_list(&list,&num3);
  add_to_list(&list,&num4);
  forEach(list,&square_of);

	assert(*(int *)get_first_element(list) == 4);
	assert(*(int *)get_last_element(list) == 64);

	forEach(list,&increment);

	assert(*(int *)get_first_element(list) == 5);
	assert(*(int *)get_last_element(list) == 65);
};

void test_for_checking_forEach_using_a_traverse_function_using_characters(){
  LinkedList list = createList();
  char char1 = 'a';
  char char2 = 'b';
  char char3 = 'c';
  char char4 = 'd';
  add_to_list(&list,&char1);
  add_to_list(&list,&char2);
  add_to_list(&list,&char3);
  add_to_list(&list,&char4);

	forEach(list,&increment);

	assert(*(char *)get_first_element(list) == 'b');
	assert(*(char *)get_last_element(list) == 'e');
};

void test_for_checking_wheather_we_are_getting_the_element_at_the_given_position(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 4;
  int num3 = 6;
  int num4 = 7;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  add_to_list(&list,&num3);
  add_to_list(&list,&num4);
  assert((*(int*)getElementAt(list,0)) == 2);
  assert((*(int*)getElementAt(list,2)) == 6);
  assert((*(int*)getElementAt(list,3)) == 7);
  assert((*(int*)getElementAt(list,1)) == 4);
  assert((getElementAt(list,6)) == NULL);
  assert((getElementAt(list,-2)) == NULL);
};
