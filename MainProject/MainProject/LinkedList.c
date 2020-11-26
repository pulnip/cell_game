#include "LinkedList.h"

#include <stdlib.h>

int initList(List* list){
    if(list==NULL) return 1;

    list->head=NULL;
    list->tail=NULL;

    return 0;
}

int appendNode(pObject _pObj, List* list){
    if((_pObj==NULL)||(list==NULL)) return 1;

    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return 1;
    }
    newNode->pObject=_pObj;
    newNode->next=NULL;

    if(list->tail==NULL){
        list->head=newNode;
        list->tail=newNode;
    }
    else{
        list->tail->next=newNode;
        list->tail=newNode;
    }
    return 0;
}

pObject removeNode(pObject _pObj, List* list){
    if((_pObj==NULL)||(list==NULL)) return NULL;

    Node* aheadNode=NULL;
    Node* rmNode=list->head;
    if (rmNode == NULL) return NULL;
    pObject res=NULL;

    while(rmNode!=NULL){
        if (rmNode->pObject == _pObj) {
            res = rmNode->pObject;
            break;
        }

        aheadNode=rmNode;
        rmNode=rmNode->next;
    }

    if     (rmNode==list->head) list->head=rmNode->next;
    else if(rmNode==list->tail) list->tail=aheadNode;
    else {
        if (rmNode != NULL) aheadNode->next = rmNode->next;
    }
    free(rmNode);

    return res;
}
int deleteNode(pObject _pObj, List* list){
    if((_pObj==NULL)||(list==NULL) ) return 1;

    pObject lastRef=removeNode(_pObj, list);
    if(lastRef==NULL) return 1;

    free(lastRef);
    return 0;
}

Bool isNodeInList(const Node* sn, List* list){
    if((sn==NULL)||(list==NULL)) return False;

    Node* n=list->head;

    while(n!=NULL){
        if(sn==n) return True;

        n=n->next;
    }

    return False;
}
int removeUselessNode(const Node* dn, List* list){
    if((dn==NULL)||(list==NULL)) return 1;

    if( !isNodeInList(dn, list) ) return 1;

    Node* aheadNode=NULL;
    Node* n=list->head;

    while(n!=NULL){
        if(dn==n){
            if(n==list->head) list->head=n->next;
            else if(n==list->tail) list->tail=aheadNode;
            else aheadNode->next=n->next;
            
            free(n);

            return 0;
        }

        aheadNode=n;
        n=n->next;
    }

    return 1;
}

size_t getListLen(List* list){
    if(list==NULL) return 0;
    if(list->head==NULL) return 0;

    else {
        size_t len=1;
        Node* temp=list->head;
        while(temp!=list->tail){
            temp=temp->next;
            len+=1;
        }

        return len;
    }
}

int eraseNonHeapObjectList(List* const list) {
    if(list==NULL) return 1;

    Node* n=list->head;
    list->head=NULL;

    while(n!=NULL){
        Node* temp=n->next;
        free(n);

        n=temp;
    }

    list->tail=NULL;

    return 0;
}
int eraseHeapObjectList(List* const list) {
    if(list==NULL) return 1;

    Node* n=list->head;
    list->head=NULL;

    while(n!=NULL){
        Node* temp=n->next;
        free(n->pObject);
        free(n);

        n=temp;
    }

    list->tail=NULL;

    return 0;
}
int deleteList(List* list){
    if(list==NULL) return 1;

    free(list);
    return 0;
}
