#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
  struct linkedList *previous;
  struct linkedList *next;
  int value;
} linkedList;

void createLinkedList(linkedList *list, int headValue){
  list->previous = NULL;
  list->next = NULL;
  list->value = headValue;
}

void addNodeAtTheEnd(linkedList *list, int newValue) {
  linkedList *lastElement = list;
  while(lastElement->next != NULL)
  {
    lastElement = lastElement->next;
  }

  lastElement->next = (linkedList*)malloc(sizeof(linkedList));
  lastElement->next->previous = lastElement;
  lastElement->next->next = NULL;
  lastElement->next->value = newValue;
}

void printList(linkedList *list){
  int nodeNumber = 1;
  linkedList *next = list;
  while(next != NULL){
    printf("Node number %d: value is %d\n", nodeNumber, next->value);
    nodeNumber++;
    next = next->next;
  }

}

void freeList(linkedList *list) {
  linkedList* last = list;
  while(last->next != NULL)
    last = last->next;
  while(last->previous != NULL)
  {
    last = last->previous;
    free(last->next);
  }
  free(list);
}

void addNthNode(linkedList *list, int value, int n){
  if(n <= 1) {
    puts("\naddNthNode error: n > 1\n");
    return;
  }
  int position = 1;
  linkedList *element = list;
  while(position < n){
    if(element->next == NULL){
      puts("\naddNthNode error: n > length of list\n");
      return;
    }
    position++;
    element = element->next;
  }
  linkedList *newPrevious = element->previous;
  element->previous = (linkedList*)malloc(sizeof(linkedList));
  element->previous->previous = newPrevious;
  element->previous->next = element;
  element->previous->value = value;
  newPrevious->next = element->previous;
}

void addHead(linkedList **list, int value) {
  (*list)->previous = (linkedList*)malloc(sizeof(linkedList));
  (*list)->previous->previous = NULL;
  (*list)->previous->next = (*list);
  (*list)->previous->value = value;
  (*list) = (*list)->previous;
}

void deleteNthNode(linkedList* list, int n) {
  if(n <= 1) {
    puts("\ndeleteNthNode error: n > 1\n");
    return;
  }
  int position = 1;
  linkedList *element = list;
  while(position < n){
    if(element->next == NULL){
      puts("\ndeleteNthNode error: n > length of list\n");
      return;
    }
    position++;
    element = element->next;
  }
  element->previous->next = element->next;
  element->next->previous = element->previous;
  free(element);
}

void deleteTail(linkedList *list) {
  if(list->next == NULL){
    puts("\nYou can't delete tail if you have head only\n");
    return;
  }
  linkedList *element = list;
  while(element->next != NULL) {
    element = element->next;
  }
  element->previous->next = NULL;
  free(element);
}

void deleteHead(linkedList **list) {
  if((*list)->next == NULL) {
    puts("\nYou can't delete head if it is the only one element\n");
    return;
  }
  linkedList* head = (*list);
  head->next->previous = NULL;
  (*list) = head->next;
  free(head);
}

int sizeOfLinkedList(linkedList *list) {
  int size = 1;
  linkedList *elem = list;
  while(elem->next != NULL) {
    size++;
    elem = elem->next;
  }
  return size;
}

int getValueOfNthElement(linkedList *list, int n) {
  if(n < 1) {
    puts("\ngetValueOfNthElement error: n >= 1, returned 0xDEADBEEF\n");
    return 0xDEADBEEF;
  }
  int position = 1;
  linkedList *element = list;
  while(position < n){
    if(element->next == NULL){
      puts("\ngetValueOfNthElement error: n > length of list, returned 0xDEADBEEF\n");
      return 0xDEADBEEF;
    }
    position++;
    element = element->next;
  }
  return element->value;
}

void printNthPositionAndNextNodes(linkedList *list, int n) {
  if(n < 1) {
    puts("\nprintAfterNthPosition error: n >= 1\n");
  }
  int position = 1;
  linkedList *element = list;
  while(position < n){
    if(element->next == NULL){
      puts("\nprintAfterNthPosition error: n > length of list\n");
    }
    position++;
    element = element->next;
  }
  printList(element);
}

int findFirstIndexOfAValue(linkedList *list, int value) {
  linkedList *element = list;
  int position = 1;
  int propbValue = element->value;
  if(propbValue == value) return position;
  while(element->next != NULL) {
    position++;
    element = element->next;
    propbValue = element->value;
    if(propbValue == value) return position;
  }
  printf("\nfindFirstIndexOfAValue error: did not find value %d, returned 0xDEADBEEF\n", value);
  return 0xDEADBEEF;
}

void useFunctionOnEveryElement(linkedList *list, int(*function)(int)) {
  linkedList *element = list;
  element->value = function(element->value);
  while(element->next != NULL) {
    element = element->next;
    element->value = function(element->value);
  }
}

//Just some simple function that takes one integer, does some operations and returns an integer
int square(int a) {
  return a*a;
}

int main(int argc, char const *argv[]) {
  //Create base node: `linkedList *name = (linkedList*)malloc(sizeof(linkedList));`
  //After creating that use `createLinkedList(name, valueOfHead);`
  //To add node at the end use `addNodeAtTheEnd(name, valueOfNewNode);`
  //To delete node at the end use `deleteTail(name);` ; Can't use if there is only 1 element
  //To add value at nth position (can't be first and can't be last element (use addHead / addNodeAtTheEnd)): `addNthNode(name, valueOfNewNode, position of new node)`
  //To delete value at nth position (can't be first and can't be last element (use deleteHead / deleteTail)): `deleteNthNode(name, position of a node)`
  //To add new head use `addHead(&name, valueOfNewHead);` - remember that you need to use adress of a pointer to the linked list
  //To delete head use `deleteHead(&name);` - remember that you need to use adress of a pointer to the linked list; Can't use if there is only 1 element
  //To print all elements of a list use `printList(name);`
  //To print nth element and all elements after it use `printAfterNthPosition(name, n);`
  //To get size of list (int) use `sizeOfLinkedList(name);`
  //To get value (int) of nth position in list use `getValueOfNthElement(name, position);`  In case of error it returns 0xDEADBEEF
  //To get index of first appearance of some given value use `findFirstIndexOfAValue(name, value);` In case of error it returns 0xDEADBEEF
  //To use some operation on value of every node use function fncptr: `useFunctionOnEveryElement(name, fncptr);` - fncprt takes one int as an argument (value of a node) and returns an int (new value)
  //To free memory (remember about it!) use `freeList(name);`

  puts("\nCreating linked list and head - its value is 10;\n");
  linkedList *LL = (linkedList*)malloc(sizeof(linkedList));
  createLinkedList(LL, 10);

  puts("Adding 3 elements at the end: 11, 12, 13;\n");
  addNodeAtTheEnd(LL, 11);
  addNodeAtTheEnd(LL, 12);
  addNodeAtTheEnd(LL, 13);

  printf("\nThe size of list is %d, the 2nd element has value %d, the whole list is:\n", sizeOfLinkedList(LL), getValueOfNthElement(LL, 2));
  printList(LL);

  puts("\nAdding head: 9;\nAdding head: 8;\n");
  addHead(&LL, 9);
  addHead(&LL, 8);

  printf("\nThe size of list is %d, the 2nd element has value %d, the whole list is:\n", sizeOfLinkedList(LL), getValueOfNthElement(LL, 2));
  printList(LL);

  printf("\nBut you can also print 3rd element and nexts only:\n");
  printNthPositionAndNextNodes(LL, 3);

  printf("\n\nNow it will square all existing elements:\n");
  useFunctionOnEveryElement(LL, square);
  printList(LL);

  puts("\nAdding element at pos 3 with value 7;\n");
  addNthNode(LL, 7, 3);
  puts("Deleting Head and tail;\n");
  deleteHead(&LL);
  deleteTail(LL);

  printf("\nThe size of list is %d, the last element has value %d, the whole list is:\n", sizeOfLinkedList(LL), getValueOfNthElement(LL, sizeOfLinkedList(LL)));
  printList(LL);

  puts("\nDeleting 2nd node;");
  deleteNthNode(LL, 2);
  puts("\nDeleting 3rd node (after 2nd, so it was 4th on just printed list);\n");
  deleteNthNode(LL, 3);

  printf("\nThe size of list is %d, the 1st element has value %d, the whole list is:\n", sizeOfLinkedList(LL), getValueOfNthElement(LL, 1));
  printList(LL);

  printf("\n\n144 is at position %d, but 3 is at position %d:\n", findFirstIndexOfAValue(LL, 144), findFirstIndexOfAValue(LL, 3));

  freeList(LL);
  return 0;
}
