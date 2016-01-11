typedef struct{
  int value;
  void *next;
} Element;

typedef struct{
  int length;
  Element *tail;
  Element *head;
}LinkedList;

LinkedList createList(void);
