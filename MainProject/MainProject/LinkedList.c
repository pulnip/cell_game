#include "header.h"

int initList(){
    head=NULL;
    tail=NULL;
}

int appendCell(const Cell* const _pCell){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->pCell=_pCell;
    newNode->next=NULL;

    tail->next=newNode;
    tail=newNode;

    if(head==NULL){
        head=tail;
    }
}

int destroyCell(const Cell* const _pCell){
    Node* aheadNode=NULL;
    Node* rmNode=head;

    if(head==NULL){
        while(_pCell!=rmNode->pCell){
            aheadNode=rmNode;
            rmNode=rmNode->next;
            if(rmNode==NULL) break;
        }

        if(rmNode!=NULL){
            aheadNode->next=rmNode->next;
            free(rmNode);

            return 0;
        }
        else return 1;
    }
    else return 1;
}

size_t getListLen(){
    if(head==NULL){
        return 0;
    }
    else {
        size_t len=1;
        Node* temp=head;
        while(temp!=tail){
            temp=temp->next;
            len+=1;
        }

        return len;
    }
}
