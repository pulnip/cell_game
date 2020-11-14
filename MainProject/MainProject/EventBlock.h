#ifndef __INC_EVENT_BLOCK
#define __INC_EVENT_BLOCK

#ifndef __INC_BASE
#include "base.h"
#endif

#ifndef __INC_LINKED_LIST
#include "LinkedList.h"
#endif

typedef struct _SmallSizeRect{
    SmallSize_t leftward;
    SmallSize_t upward;
    SmallSize_t rightward;
    SmallSize_t downward;
} SmallSizeRect;

typedef union _ControlKey{
    int iKey;
    SmallSizeRect rKey;
} ControlKey;

typedef enum _KeyMask{
    leftward =0x000000ff,
    upward   =0x0000ff00,
    rightward=0x00ff0000,
    downward =0xff000000
} KeyMask;

typedef struct _Trigger{
    TriggerType triggerType;
    int id;
    Bool isHidden;
    Rect pos;
    ControlKey control;
    List OnClickEvent;
} Trigger;

typedef Trigger Button;
// Min Size: 1*1

typedef Trigger Switch;
// Min Size: 2*1

typedef Trigger VerticalScrollBar;
// Min Size: 1*2

typedef Trigger HorizontalScrollBar;
// Min Size: 2*1

// Button is-a Trigger.
// Switch is-a Trigger.
// VerticalScrollBar is-a Trigger.
// HorizontalScrollBar is-a Trigger.

typedef enum _TriggerType{
    tButton,
    tSwitch,
    tVerticalScrollBar,
    tHorizontalScrollBar
} TriggerType;

typedef void (*Event)(void);

extern List eventTrigger;

int initEventTriggerList(void);

Trigger* createTrigger(Rect, int);
// createButton calls createTrigger.
// Others too.

// if createTrigger succeed, return pointer(non-zero);
// else return Zero.

int createButton(Rect, int vkey);
int createSwitch(Rect, int vkey);
int createVerticalScrollBar(Rect, int upward_vkey, int downward_vkey);
int createHorizontalScrollBar(Rect, int leftward_vkey, int rightward_vkey);

// EventTrigger spec func
Trigger* searchTrigger(int id);

int showTrigger(int _id);
int hideTrigger(int _id);
int getIsHidden(int _id);

int setPos(int _id, Rect pos);
Rect getPos(int _id);

int setKey(int _id, ControlKey key);
ControlKey getKey(int _id);

int appendEvent(int _id, Event func);
int deleteEvent(int _id, Event func);

#endif // __INC_EVENT_BLOCK
