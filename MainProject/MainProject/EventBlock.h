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

typedef void TriggerEvent(pObject);
typedef TriggerEvent* pTriggerEvent;

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

int appendOnKeyDownEvent(Trigger*, pTriggerEvent func);
int appendKeyDownEvent(Trigger*, pTriggerEvent func);
int appendOnKeyUpEvent(Trigger*, pTriggerEvent func);
int appendKeyUpEvent(Trigger*, pTriggerEvent func);

int removeOnKeyDownEvent(Trigger*, pTriggerEvent func);
int removeKeyDownEvent(Trigger*, pTriggerEvent func);
int removeOnKeyUpEvent(Trigger*, pTriggerEvent func);
int removeKeyUpEvent(Trigger*, pTriggerEvent func);

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
TriggerEvent VanillaButtonShowAnimation;
TriggerEvent VanillaButtonHideAnimation;
// just for type conversion
TriggerEvent ToggleButtonAnimation;
// </AnimationEvent>

#endif // __INC_EVENT_BLOCK
