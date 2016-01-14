#include <stdio.h>
#include <stdlib.h>
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

void test_for_checking_wheather_we_are_getting_the_position_of_the_given_element(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 4;
  int num3 = 6;
  int num4 = 7;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  add_to_list(&list,&num3);
  assert((indexOf(list,&num1)) == 0);
  assert((indexOf(list,&num3)) == 2);
  assert((indexOf(list,&num4)) == -1);
  assert((indexOf(list,&num2)) == 1);
};

void test_for_deleting_the_element_which_is_in_the_index_provided(){
  LinkedList list = createList();
  int num1 = 2;
  int num2 = 4;
  int num3 = 6;
  int num4 = 7;
  add_to_list(&list,&num1);
  add_to_list(&list,&num2);
  add_to_list(&list,&num3);
  add_to_list(&list,&num4);
  assert((*(int*)deleteElementAt(&list,0)) == 2);
  assert((*(int*)deleteElementAt(&list,2)) == 7);
  assert((*(int*)deleteElementAt(&list,0)) == 4);
  assert(*(int *)list.first_element->value == 6);
  assert(*(int *)list.last_element->value == 6);
  assert(list.length == 1);
};

void test_for_asArray(){
  LinkedList list = createList();
  int array[] = {1,2,3,4,5,6};
  for(int i=0;i<6;i++){
    add_to_list(&list,&array[i]);
  }
  void *dest1 = (int *)calloc(6,8);
  int no_of_ele_added_1 = asArray(list,dest1,6);
  for(int i=0;i<no_of_ele_added_1;i++){
    assert(**(int**)dest1 == array[i]);
    dest1 += 8;
  }

  void *dest2 = (int *)calloc(3,8);
  int no_of_ele_added_2 = asArray(list,dest1,6);
  for(int i=0;i<no_of_ele_added_2;i++){
    assert(**(int**)dest1 == array[i]);
    dest1 += 8;
  }
};

int divisibleByHint(void *hint, void *item){
  return  *(int *)item % *(int *)hint == 0;
};

void test_for_filtering_the_elements_in_the_list(){
  LinkedList list = createList();
  int array[] = {1,2,3,4,5,6};
  for(int i=0;i<6;i++){
    add_to_list(&list,&array[i]);
  }
  int hint = 2;
  LinkedList filtered_list = filter(list, &divisibleByHint, &hint);
  assert(*(int *)filtered_list.first_element->value == 2);
  assert(*(int *)filtered_list.first_element->next->value == 4);
  assert(*(int *)filtered_list.last_element->value == 6);
  assert(filtered_list.length == 3);
}
