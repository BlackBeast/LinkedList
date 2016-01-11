typedef struct element{
  void *value;
  struct element *next;
} Element;

typedef struct{
  Element *first_element;
  Element *last_element;
  int length;
}LinkedList;

LinkedList createList(void);

int add_to_list(LinkedList *,void *);

void *get_first_element(LinkedList);

void *get_last_element(LinkedList);
