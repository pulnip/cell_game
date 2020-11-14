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
    int id;
    Bool isHidden;
    Rect pos;
    ControlKey control;
    List OnClickEvent;
} Trigger;

typedef Trigger Button;
typedef Trigger Switch;
typedef Trigger VerticalScrollBar;
typedef Trigger HorizontalScrollBar;

typedef void (*Event)(void);

extern List eventTrigger;

int initEventTriggerList(void);

int createButton(Rect, int vkey);
int createSwitch(Rect, int vkey);
int createVerticalScrollBar(Rect, int upward_vkey, int downward_vkey);
int createHorizontalScrollBar(Rect, int leftward_vkey, int rightward_vkey);

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
