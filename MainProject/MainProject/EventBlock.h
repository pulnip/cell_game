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

typedef void (*TriggerEvent)(pObject);

extern List Triggers;
// all Trigger must be in Triggers.

int initTriggers(void);

int checkTriggerArg(Rect, int _vkey);
Trigger* createVanillaTrigger(Rect, int _vkey);
// if success, return Trigger (Non-zero),
// else return 0
Trigger* createVanillaButton(Rect, int _vkey);
Trigger* createToggleButton(Rect, int _vkey);
Trigger** createVerticalScrollBar(Rect, int Up_vkey, int Down_vkey);
// must free the return value (it is heap Object)

int showTrigger(Trigger*);
int hideTrigger(Trigger*);
int getIsHidden(Trigger*);

int setPos(Trigger*, Rect pos);
Rect getPos(Trigger*);

int setKey(Trigger*, int _vkey);
int getKey(Trigger*);

Trigger* searchTriggerByVKey(int _vkey);

int appendOnKeyDownEvent(Trigger*, TriggerEvent func);
int appendKeyDownEvent(Trigger*, TriggerEvent func);
int appendOnKeyUpEvent(Trigger*, TriggerEvent func);
int appendKeyUpEvent(Trigger*, TriggerEvent func);

int removeOnKeyDownEvent(Trigger*, TriggerEvent func);
int removeKeyDownEvent(Trigger*, TriggerEvent func);
int removeOnKeyUpEvent(Trigger*, TriggerEvent func);
int removeKeyUpEvent(Trigger*, TriggerEvent func);

int checkTriggered(void);
// check by bKeyDown (call Event once).
//implemented on Infra

int runOnKeyDownEvent(Trigger*);
int runKeyDownEvent(Trigger*);
int runOnKeyUpEvent(Trigger*);
int runKeyUpEvent(Trigger*);

int deleteTrigger(Trigger*);
StatusFunc deleteTriggers;

// <AnimationEvent>
void VanillaButtonShowAnimation(void*);
void VanillaButtonHideAnimation(void*);
// just for type conversion
void ToggleButtonAnimation(void*);
// </AnimationEvent>

#endif // __INC_EVENT_BLOCK
