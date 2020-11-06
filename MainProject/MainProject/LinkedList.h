#define __INC_LINKED_LIST

#ifndef __INC_BASE
#include "base.h"
#endif

typedef struct _Node{
    Node* next;
    Cell* pCell;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;

extern List userCell, comCell;

int initList(List*);
int appendNode(Cell*, List*);
int destroyNode(Cell*, List*);
size_t getListLen(List*);
void destroyList(List*);
// </Linked List>