#include "EventBlock.h"
#include "Map.h"

List EventTrigger;

int initEventTriggerList(void){
    EventTrigger.head=NULL;
    EventTrigger.tail=NULL;
}

Trigger* createTrigger(Rect rect, int vkey){
    Trigger* trigger=(Trigger*)malloc(sizeof(Trigger));
    if(trigger==NULL) return 0;

    if(EventTrigger.tail==NULL){
        trigger->id=1;
    } else{
        trigger->id=((Trigger*)(EventTrigger.tail->pData))->id+1;
    }

    trigger->isHidden=True;

    trigger->pos.Left=rect.Left;
    trigger->pos.Top=rect.Top;
    trigger->pos.Right=rect.Right;
    trigger->pos.Bottom=rect.Bottom;

    trigger->control.iKey=vkey;

    trigger->OnClickEvent.head=NULL;
    trigger->OnClickEvent.tail=NULL;

    appendNode(trigger, &EventTrigger);

    return trigger;
}

int createButton(Rect rect, int vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 1   ) ||
        (rect.Bottom-rect.Top < 1   )
    ) {
        return 1;
    }

    Trigger* trigger=createTrigger(rect, vkey);
    if(trigger==NULL) return 1;

    trigger->triggerType=tButton;

    return 0;
}

int createSwitch(Rect rect, int vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 2   ) ||
        (rect.Bottom-rect.Top < 1   )
    ) {
        return 1;
    }

    Trigger* trigger=createTrigger(rect, vkey);
    if(trigger==NULL) return 1;

    trigger->triggerType=tSwitch;

    return 0;
}

int createVerticalScrollBar(Rect rect, int upward_vkey, int downward_vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 1   ) ||
        (rect.Bottom-rect.Top < 2   )
    ) {
        return 1;
    }

    ControlKey _ckey;
    _ckey.rKey.upward=upward_vkey;
    _ckey.rKey.downward=downward_vkey;

    Trigger* trigger=createTrigger(rect, _ckey.iKey);
    if(trigger==NULL) return 1;

    trigger->triggerType=tVerticalScrollBar;

    return 0;
}

int createHorizontalScrollBar(Rect rect, int leftward_vkey, int rightward_vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 2   ) ||
        (rect.Bottom-rect.Top < 1   )
    ) {
        return 1;
    }

    ControlKey _ckey;
    _ckey.rKey.leftward=leftward_vkey;
    _ckey.rKey.rightward=rightward_vkey;

    Trigger* trigger=createTrigger(rect, _ckey.iKey);
    if(trigger==NULL) return 1;

    trigger->triggerType=tHorizontalScrollBar;

    return 0;
}

// EventTrigger spec func
Trigger* searchTrigger(int _id){
    if(EventTrigger.head==NULL) return NULL;
    
    Node* pNode=EventTrigger.head;

    while(pNode==NULL){
        if(((Trigger*)(pNode->pData))->id == _id){
            return (Trigger*)(pNode->pData);
        }

        pNode=pNode->next;
    }

    return NULL;
}

int showTrigger(int _id){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    t->isHidden=False;
    return 0;
}

int hideTrigger(int _id){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    t->isHidden=True;
    return 0;
}

int getIsHidden(int _id){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    return t->isHidden;
}

int setPos(int _id, Rect pos){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    t->pos.Left=pos.Left;
    t->pos.Left=pos.Left;
    t->pos.Left=pos.Left;
    t->pos.Left=pos.Left;

    return 0;
}

Rect getPos(int _id){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return (Rect){0, 0, 0, 0}; // return null Rect

    return t->pos;
}

int setKey(int _id, ControlKey key){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    t->control=key;
    return 0;
}

ControlKey getKey(int _id){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return (ControlKey)0;

    return t->control;
}

int appendEvent(int _id, Event func){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    appendNode(func, &(t->OnClickEvent));
}

int deleteEvent(int _id, Event func){
    Trigger* t=searchTrigger(_id);
    if(t==NULL) return 1;

    deleteNode(func, &(t->OnClickEvent));
}
