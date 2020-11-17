#include "EventBlock.h"
#include "Screen.h"
#include "Infra.h"

List Triggers;

int initEventTriggerList(void){
    Triggers.head=NULL;
    Triggers.tail=NULL;
}

int checkTriggerArg(Rect rect, int _vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 1   ) ||
        (rect.Bottom-rect.Top < 1   )
    ) {
        return 1;
    }

    if( (0    > _vkey) ||
        (0xff < _vkey)
    ) {
        return 1;
    }

    return 0;
}

Trigger* createTrigger(Rect rect, int _vkey){
    if (checkTriggerArg(rect, _vkey)){
        return NULL;
    }

    Trigger* t=(Trigger*)malloc(sizeof(Trigger));
    if(t==NULL) return NULL;

    t->isHidden=True;

    t->pos.Left=rect.Left;
    t->pos.Top=rect.Top;
    t->pos.Right=rect.Right;
    t->pos.Bottom=rect.Bottom;

    t->key=_vkey;

    t->OnClickEvent.head=NULL;
    t->OnClickEvent.tail=NULL;

    t->isToggled=False;

    appendNode(t, &Triggers);

    return t;
}

int showTrigger(Trigger* t){
    if(t==NULL) return 1;

    t->isHidden=False;
    return 0;
}

int hideTrigger(Trigger* t){
    if(t==NULL) return 1;

    t->isHidden=True;
    return 0;
}

int getIsHidden(Trigger* t){
    if(t==NULL) return -1;

    return t->isHidden;
}

int setPos(Trigger* t, Rect pos){
    if(t==NULL) return 1;

    t->pos.Left  =pos.Left;
    t->pos.Top   =pos.Top;
    t->pos.Right =pos.Right;
    t->pos.Bottom=pos.Bottom;
    return 0;
}

Rect getPos(Trigger* t){
    if(t==NULL) return (Rect){0, 0, 0, 0}; // return null Rect

    return t->pos;
}

int setKey(Trigger* t, int _vkey){
    if(t==NULL) return 1;

    t->key=_vkey;
    return 0;
}

int getKey(Trigger* t){
    if(t==NULL) return -1;

    return t->key;
}

int appendEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnClickEvent));
}

int deleteEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return deleteNode(func, &(t->OnClickEvent));
}

int drawTriggers(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        Trigger* t=n->pData;

        if( !(t->isHidden) ){

            Rect rect=t->pos;

            for(    int i=rect.Top ; i<rect.Bottom; ++i){
                for(int j=rect.Left; j<rect.Right ; ++j){
                    CHAR_INFO* pci=&screen[i][j];
                    pci->Char.AsciiChar=' ';
                    pci->Attributes=FG_WHITE|BG_WHITE;   
                }
            }
        }

        n=n->next;
    }

    return 0;
}

int checkTriggered(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        Trigger* t=n->pData;
        if(keys[t->key].bKeyDown){
            runTriggerEvent(t);
        }

        n=n->next;
    }

    return 0;
}

int runTriggerEvent(Trigger* t){
    Node* en=t->OnClickEvent.head; // TriggerEvent Node

    while(en!=NULL){
        TriggerEvent tbe=en->pData;
        tbe(t);

        en=en->next;
    }

    return 0;
}

int deleteTrigger(Trigger* t){
    Node* en=t->OnClickEvent.head;

    while(en!=NULL){
        en=en->next;
        free(en);
    }

    free(t);
}

int deleteTriggers(void){
    Node* n=Triggers.head;

    while(n!=NULL){
        deleteTrigger(n->pData);

        n=n->next;
        free(n);
    }

    return 0;
}
