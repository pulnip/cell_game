#ifndef __INC_EVENT_BLOCK
#define __INC_EVENT_BLOCK

#ifndef __INC_BASE
#include "base.h"
#endif

#ifndef __INC_LINKED_LIST
#include "LinkedList.h"
#endif

typedef struct _Trigger{
    Bool isHidden;
    Rect pos;
    int key;
    List OnClickEvent;
    Bool isToggled;
} Trigger;

typedef void (*TriggerEvent)(Trigger*);

extern List Triggers;

int initTriggerList(void);

int checkTriggerArg(Rect, int _vkey);
Trigger* createTrigger(Rect, int _vkey);
// if success, return id of Trigger (Non-zero),
// else return 0

int showTrigger(Trigger*);
int hideTrigger(Trigger*);
int getIsHidden(Trigger*);

int setPos(Trigger*, Rect pos);
Rect getPos(Trigger*);

int setKey(Trigger*, int _vkey);
int getKey(Trigger*);

int appendEvent(Trigger*, TriggerEvent func);
int deleteEvent(Trigger*, TriggerEvent func);

int drawTriggers(void);

int checkTriggered(void);
// check by bKeyDown (call Event once).
int runTriggerEvent(Trigger*);

int deleteTrigger(Trigger*);
int deleteTriggers(void);

#endif // __INC_EVENT_BLOCK
