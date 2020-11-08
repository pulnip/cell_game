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
int destroyNode(pObject, List*);
size_t getListLen(List*);
void destroyList(List*);

#endif //__INC_LINKED_LIST
