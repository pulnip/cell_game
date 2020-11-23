#ifndef __INC_EVENT_BLOCK
#define __INC_EVENT_BLOCK

#include "SuperHeader.h"
#include "LinkedList.h"

typedef struct _Trigger{
    Bool isHidden;
    Rect pos;
    int key;
    List OnKeyDownEvent;
    List KeyDownEvent;
    List OnKeyUpEvent;
    List KeyUpEvent;
    int log;
} Trigger;

typedef void (*TriggerEvent)(Trigger*);

extern List Triggers;
// all Trigger must be in Triggers.

int initTriggers(void);

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

int appendOnKeyDownEvent(Trigger*, TriggerEvent func);
int appendKeyDownEvent(Trigger*, TriggerEvent func);
int appendOnKeyUpEvent(Trigger*, TriggerEvent func);
int appendKeyUpEvent(Trigger*, TriggerEvent func);

int removeOnKeyDownEvent(Trigger*, TriggerEvent func);
int removeKeyDownEvent(Trigger*, TriggerEvent func);
int removeOnKeyUpEvent(Trigger*, TriggerEvent func);
int removeKeyUpEvent(Trigger*, TriggerEvent func);

int drawTrigger(Trigger*);
int drawTriggers(void);

int checkTriggered(void);
// check by bKeyDown (call Event once).
int runOnKeyDownEvent(Trigger*);
int runKeyDownEvent(Trigger*);
int runOnKeyUpEvent(Trigger*);
int runKeyUpEvent(Trigger*);

int deleteTrigger(Trigger*);
int deleteTriggers(void);

// <AnimationEvent>
void ButtonShowAnimation(Trigger*);
void ButtonHideAnimation(Trigger*);
// just for type conversion
void ToggleButtonAnimation(Trigger*);
// </AnimationEvent>


#endif // __INC_EVENT_BLOCK
