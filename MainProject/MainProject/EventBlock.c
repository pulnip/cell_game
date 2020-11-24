#include "EventBlock.h"

List Triggers;

int initTriggers(void){
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
    ) return 1;

    if( (0    > _vkey) ||
        (0xff < _vkey)
    ) return 1;

    return 0;
}

Trigger* createTrigger(Rect rect, int _vkey){
    if (checkTriggerArg(rect, _vkey)){
        return NULL;
    }

    Trigger* t=(Trigger*)malloc(sizeof(Trigger));
    if(t==NULL) return NULL;

    t->isHidden=True;

    t->pos.Left  =rect.Left;
    t->pos.Top   =rect.Top;
    t->pos.Right =rect.Right;
    t->pos.Bottom=rect.Bottom;

    t->key=_vkey;

    t->OnKeyDownEvent.head=t->OnKeyDownEvent.tail=NULL;
    t->  KeyDownEvent.head=t->  KeyDownEvent.tail=NULL;
    t->OnKeyUpEvent.head  =t->OnKeyUpEvent.tail  =NULL;
    t->  KeyUpEvent.head  =t->  KeyUpEvent.tail  =NULL;

    t->log=0;

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

int appendOnKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnKeyDownEvent));
}
int appendKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->KeyDownEvent));
}
int appendOnKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnKeyUpEvent));
}
int appendKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->KeyUpEvent));
}

int removeOnKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->OnKeyDownEvent)) ) return 1;
    return 0;
}
int removeKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->KeyDownEvent)) ) return 1;
    return 0;
}
int removeOnKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->OnKeyUpEvent)) ) return 1;
    return 0;
}
int removeKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->KeyUpEvent)) ) return 1;
    return 0;
}

int drawTrigger(Trigger* t){
    if(t==NULL) return 1;

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

    return 0;
}
int drawTriggers(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        drawTrigger(n->pObject);

        n=n->next;
    }

    return 0;
}

int checkTriggered(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        Trigger* t=n->pObject;
        n=n->next;
        if(t==NULL) continue;

        if(keys[t->key].bPressed) {
            if(keys[t->key].bKeyDown)runOnKeyDownEvent(t);
            runKeyDownEvent(t);}
        else{
            if(keys[t->key].bKeyUp)  runOnKeyUpEvent(t);
            runKeyUpEvent(t); 
        }
    }

    return 0;
}

int runOnKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyDownEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyDownEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runOnKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyUpEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyUpEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}

int deleteTrigger(Trigger* t){
    if(t==NULL) return 1;

    eraseStaticObjectList(&(t->OnKeyDownEvent));
    eraseStaticObjectList(&(t->  KeyDownEvent));
    eraseStaticObjectList(&(t->OnKeyUpEvent  ));
    eraseStaticObjectList(&(t->  KeyUpEvent  ));

    return deleteNode(t, &Triggers);
}

int deleteTriggers(void){
    Node* n=Triggers.head;

    while(n!=NULL){
        Node* temp=n->next;
        deleteTrigger(n->pObject);

        n=temp;
    }
    //implicit All Node deleted.

    return 0;
}

void ButtonShowAnimation(Trigger* t){
    showTrigger(t);
}
void ButtonHideAnimation(Trigger* t){
    hideTrigger(t);
}
void ToggleButtonAnimation(Trigger* t){
    if((t->log)&0x1){
        hideTrigger(t);
        t->log=((t->log)&(-1U-0x1));
    }
    else{
        showTrigger(t);
        t->log=(t->log)|0x1;
    }
}
