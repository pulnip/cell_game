#include "EventBlock.h"

#include <stdlib.h>

List Triggers;

int initTriggers(void){
    initList(&Triggers);

    return 0;
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

Trigger* createVanillaTrigger(Rect rect, int _vkey){
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
Trigger* createVanillaButton(Rect rect, int _vkey){
    Trigger* t=createVanillaTrigger(rect, _vkey);
    if(t==NULL) return NULL;

    appendOnKeyDownEvent(t, VanillaButtonShowAnimation);
    appendOnKeyUpEvent(  t, VanillaButtonHideAnimation);

    return t;
}
Trigger* createToggleButton(Rect rect, int _vkey){
    Trigger* t=createVanillaTrigger(rect, _vkey);
    if(t==NULL) return NULL;

    appendOnKeyDownEvent(t, ToggleButtonAnimation);

    return t;
}

Trigger** createVerticalScrollBar(Rect rect, int Up_vkey, int Down_vkey){
    if(rect.Bottom-rect.Top < 2) return NULL;

    int mid=((rect.Top+rect.Bottom)>>1)&0x7fffffff;
    Rect URect={rect.Left, rect.Top, rect.Right, mid        };
    Rect DRect={rect.Left, mid     , rect.Right, rect.Bottom};

    Trigger* UT=createVanillaButton(URect,   Up_vkey);
    Trigger* DT=createVanillaButton(DRect, Down_vkey);
    if( (UT==NULL)||(DT==NULL) ) return NULL;

    Trigger** res=malloc(sizeof(Trigger*)*2);
    if (res == NULL) return NULL;
    res[0]=UT;
    res[1]=DT;

    return res;
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
    else return t->pos;
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

Trigger* searchTriggerByVKey(int _vkey){
    Node* n=Triggers.head;

    while(n!=NULL){
        Trigger* t=n->pObject;
        if(t!=NULL){
            if(t->key==_vkey) return t;

            n=n->next;
        }
        else{
            Node* temp=n->next;

            removeUselessNode(n, &Triggers);

            n=temp;
        }
    }

    return NULL;
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

int runOnKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyDownEvent.head;

    while(en!=NULL){
        pTriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyDownEvent.head;

    while(en!=NULL){
        pTriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runOnKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyUpEvent.head;

    while(en!=NULL){
        pTriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyUpEvent.head;

    while(en!=NULL){
        pTriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}

int deleteTrigger(Trigger* t){
    if(t==NULL) return 1;

    eraseNonHeapObjectList(&(t->OnKeyDownEvent));
    eraseNonHeapObjectList(&(t->  KeyDownEvent));
    eraseNonHeapObjectList(&(t->OnKeyUpEvent  ));
    eraseNonHeapObjectList(&(t->  KeyUpEvent  ));

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

void VanillaButtonShowAnimation(void* obj){
    Trigger* t=obj;
    
    showTrigger(t);
}
void VanillaButtonHideAnimation(void* obj){
    Trigger* t=obj;

    hideTrigger(t);
}
void ToggleButtonAnimation(void* obj){
    Trigger* t=obj;

    if((t->log)&0x1){
        hideTrigger(t);
        t->log=((t->log)&0xfffffffeU);
    }
    else{
        showTrigger(t);
        t->log=(t->log)|0x1;
    }
}
