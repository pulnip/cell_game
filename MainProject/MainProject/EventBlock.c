#include "EventBlock.h"
#include "Map.h"
#include "Infra.h"

List ToggleButtons;

int initEventTriggerList(void){
    ToggleButtons.head=NULL;
    ToggleButtons.tail=NULL;
}
 #error
 // Change name

int checkToggleButtonArg(Rect rect, int _vkey){
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

int createToggleButton(Rect rect, int _vkey){
    if (checkToggleButtonArg(rect, _vkey)){
        return 0;
    }

    ToggleButton* tb=(ToggleButton*)malloc(sizeof(ToggleButton));
    if(tb==NULL) return 0;

    if(ToggleButtons.tail==NULL){
        tb->id=1;
    } else{
        tb->id=((ToggleButton*)(ToggleButtons.tail->pData))->id+1;
    }

    tb->isHidden=True;

    tb->pos.Left=rect.Left;
    tb->pos.Top=rect.Top;
    tb->pos.Right=rect.Right;
    tb->pos.Bottom=rect.Bottom;

    tb->key=_vkey;

    tb->OnClickEvent.head=NULL;
    tb->OnClickEvent.tail=NULL;

    tb->isToggled=False;

    appendNode(tb, &ToggleButtons);

    return tb->id;
}

// EventBlock spec func
ToggleButton* searchTrigger(int _id){
    if(ToggleButtons.head==NULL) return NULL;
    
    Node* pNode=ToggleButtons.head;

    while(pNode!=NULL){
        if(((ToggleButton*)(pNode->pData))->id == _id){
            return (ToggleButton*)(pNode->pData);
        }

        pNode=pNode->next;
    }

    return NULL;
}

int showTrigger(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->isHidden=False;
    return 0;
}

int hideTrigger(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->isHidden=True;
    return 0;
}

int getIsHidden(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return -1;

    return tb->isHidden;
}

int setPos(int _id, Rect pos){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->pos.Left  =pos.Left;
    tb->pos.Top   =pos.Top;
    tb->pos.Right =pos.Right;
    tb->pos.Bottom=pos.Bottom;

    return 0;
}

Rect getPos(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return (Rect){0, 0, 0, 0}; // return null Rect

    return tb->pos;
}

int setKey(int _id, int _vkey){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->key=_vkey;
    return 0;
}

int getKey(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 0;

    return tb->key;
}

int appendEvent(int _id, ToggleButtonEvent func){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    return appendNode(func, &(tb->OnClickEvent));
}

int deleteEvent(int _id, ToggleButtonEvent func){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    return deleteNode(func, &(tb->OnClickEvent));
}

int drawToggleButtons(void){
    Node* n=ToggleButtons.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        ToggleButton* tb=n->pData;

        SMALL_RECT rect;
        rect.Left  =tb->pos.Left;
        rect.Top   =tb->pos.Top;
        rect.Right =tb->pos.Right;
        rect.Bottom=tb->pos.Bottom;

        COORD ciSize;
        ciSize.X=rect.Right-rect.Left;
        ciSize.Y=rect.Bottom-rect.Top;
        CHAR_INFO ciToggleButton[ciSize.Y][ciSize.X];

        COORD bufferCoord={0, 0};

        for(int i=0, j=0; i<ciSize.Y; ++i){
            for(j=0; j<ciSize.X; ++j){
                ciToggleButton[i][j].Char.AsciiChar=' ';
                ciToggleButton[i][j].Attributes
                =(tb->isToggled ?
                    FG_WHITE|BG_WHITE:
                    FG_BLACK|BG_BLACK
                );
            }
        }

        WriteConsoleOutputA(
            hStdOut,
            (CHAR_INFO*)ciToggleButton, ciSize, bufferCoord,
            &rect
        );

        n=n->next;
    }

    return 0;
}

int checkTriggered(void){
    Node* n=ToggleButtons.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        ToggleButton* tb=n->pData;
        if(keys[tb->key].bPressed){
            runToggleButtonEvent(tb);
        }

        n=n->next;
    }

    return 0;
}

int runToggleButtonEvent(ToggleButton* tb){
    Node* en=tb->OnClickEvent.head; // ToggleButtonEvent Node

    while(en!=NULL){
        ToggleButtonEvent tbe=en->pData;
        tbe(tb);

        en=en->next;
    }

    return 0;
}

#error

// To Do
// id->pointer ?
// pointer->id ?
