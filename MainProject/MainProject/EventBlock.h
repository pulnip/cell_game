#ifndef __INC_EVENT_BLOCK
#define __INC_EVENT_BLOCK

#ifndef __INC_BASE
#include "base.h"
#endif

#ifndef __INC_LINKED_LIST
#include "LinkedList.h"
#endif

typedef struct _ToggleButton{
    int id;
    Bool isHidden;
    Rect pos;
    int key;
    List OnClickEvent;
    Bool isToggled;
} ToggleButton;

typedef void (*ToggleButtonEvent)(ToggleButton*);

extern List ToggleButtons;

int initTriggerList(void);

int checkToggleButtonArg(Rect, int _vkey);
int createToggleButton(Rect, int _vkey);
// if success, return id of ToggleButton (Non-zero),
// else return 0

// EventBlock spec func
ToggleButton* searchTrigger(int id);

int showTrigger(int _id);
int hideTrigger(int _id);
int getIsHidden(int _id);

int setPos(int _id, Rect pos);
Rect getPos(int _id);

int setKey(int _id, int _vkey);
int getKey(int _id);

int appendEvent(int _id, ToggleButtonEvent func);
int deleteEvent(int _id, ToggleButtonEvent func);

int drawToggleButtons(void);

int checkTriggered(void);
int runToggleButtonEvent(ToggleButton*);

#endif // __INC_EVENT_BLOCK
