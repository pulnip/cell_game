#ifndef __INC_LINKED_LIST
#define __INC_LINKED_LIST

#include "SuperHeader.h"

typedef void* pObject;

typedef struct _Node{
    struct _Node* next;
    pObject pObject;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;

extern List userCell, comCell;

int initList(List*);
int appendNode(pObject, List*);
// Append Object(cell, ..) at Tail

// Naming Rule
// remove = entity is alive
// delete = entity is killed
pObject removeNode(pObject, List*);
int deleteNode(pObject, List*);

int removeUselessNode(Node*, List*);

size_t getListLen(List*);
// Get the Number of List Element

int eraseNonHeapObjectList(List*);
// remove all elements
int eraseHeapObjectList(List*);
// delete all elements
int deleteList(List*);
// delete List itself

#endif //__INC_LINKED_LIST
