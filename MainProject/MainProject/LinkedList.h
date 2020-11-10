#ifndef __INC_LINKED_LIST
#define __INC_LINKED_LIST

#ifndef __INC_BASE
#include "base.h"
#endif

typedef void* pObject;

typedef struct _Node{
    Node* next;
    pObject pData;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;

extern List userCell, comCell;

int initList(List*);
int appendNode(pObject, List*);
// Append Object(cell, ..) at Tail

int destroyNode(pObject, List*);
// Destroy specific Object from List
// if the Object is in List,
// destroy from the List and, destroy Object itself.

size_t getListLen(List*);
// Get the Number of List Element

void destroyList(List*);
// destroy All Element and List

#endif //__INC_LINKED_LIST
