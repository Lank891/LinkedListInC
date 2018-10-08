# LinkedListInC
Some Linked List implementation before Prog1 early exam in C
-----------------
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
