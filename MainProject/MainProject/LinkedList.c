#include "base.h"
#include "LinkedList.h"

int initList(List* list){
    list->head=NULL;
    list->tail=NULL;
}

int appendNode(const pObject const _pObject, List* list){
    if(_pObject==NULL) return 1;

    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->pData=_pObject;
    newNode->next=NULL;

    list->tail->next=newNode;
    list->tail=newNode;

    if(list->head==NULL){
        list->head=list->tail;
    }

    return 0;
}

int deleteNode(const pObject const _pObject, List* list){
    Node* aheadNode=NULL;
    Node* rmNode=list->head;

    if(list->head!=NULL){
        while(_pObject!=rmNode->pData){
            aheadNode=rmNode;
            rmNode=rmNode->next;
            if(rmNode==NULL) break;
        }

        if(rmNode!=NULL){
            aheadNode->next=rmNode->next;

            return 0;
        }
        else return 1;
    }
    else return 1;
}

int destroyNode(const pObject const _pObject, List* list){
    Node* aheadNode=NULL;
    Node* rmNode=list->head;

    if(list->head!=NULL){
        while(_pObject!=rmNode->pData){
            aheadNode=rmNode;
            rmNode=rmNode->next;
            if(rmNode==NULL) break;
        }

        if(rmNode!=NULL){
            aheadNode->next=rmNode->next;
            free(rmNode->pData);
            free(rmNode);

            return 0;
        }
        else return 1;
    }
    else return 1;
}

size_t getListLen(List* list){
    if(list->head==NULL){
        return 0;
    }
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

void destroyList(List* list){
    while( (list->head)==(list->tail) ){
        Node* temp=list->head->next;
        free(list->head->pData);
        free(list->head);
        list->head=temp;
    }

    list->tail==NULL;
    free(list->head->pData);
    free(list->head);

    free(list);
}
