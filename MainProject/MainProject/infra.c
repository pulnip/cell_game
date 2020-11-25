#include "Infra.h"

KeyState keys[0x100];

int initInfra(void) {
    initScreen();

    initTriggers();
    makeTrigger();
    // add ...

    waitUntilKeyInput();

    return 0;
}

int FastEscape(void) {
    if( GetKeyState(VK_ESCAPE)&0x8000 ) return 1;
    return 0;
}
int updateInfra1(void){
    if(FastEscape()) return 1;
    getKBInput();
    checkTriggered();

    return 0;
}
int updateInfra2(void){
    updateScreen();

    return 0;
}

int deleteInfra(void){
    deleteTriggers();

    return 0;
}
void waitUntilKeyInput(void) {
    Bool isAnyKeyPressed=False;
    do{
        getKBInput();
        isAnyKeyPressed=False;

        for(int i=0; i<0xff; ++i){
            isAnyKeyPressed |= keys[i].bPressed;
        }
    } while(!isAnyKeyPressed);
}

void getKBInput(void) {
    for(int i=0; i<0x100; ++i){
        KeyState lastState=keys[i];
        
        short tmpKey=GetKeyState(i);
        keys[i].bPressed = (tmpKey&0x8000)>>(8*sizeof(short)-1)&0x1;
        keys[i].bToggled = tmpKey&0x1;

        Bool isChanged=(lastState.bPressed)^(keys[i].bPressed);
        
        keys[i].bKeyDown =   keys[i].bPressed & isChanged;
        keys[i].bKeyUp   = (!keys[i].bPressed)&0x1 & isChanged ;
    }
}

int checkTriggered(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        Trigger* t=n->pObject;
        n=n->next;
        if(t==NULL) continue;

        if(keys[t->key].bPressed) {
            if(keys[t->key].bKeyDown)runOnKeyDownEvent(t);
            runKeyDownEvent(t);}
        else{
            if(keys[t->key].bKeyUp)  runOnKeyUpEvent(t);
            runKeyUpEvent(t); 
        }
    }

    return 0;
}
int makeTrigger(void) {
    Rect rectq={3, 34, 19, 35};
    Rect rectw={22, 34, 31, 35};

    Trigger* tq=createTrigger(rectq, 'Q');
    if(tq==NULL) return 1;
    Trigger* tw=createTrigger(rectw, 'W');
    if(tw==NULL) return 1;

    if( appendOnKeyDownEvent(tq, ToggleButtonAnimation) ||
        appendOnKeyDownEvent(tw, ButtonShowAnimation) ||
        appendOnKeyUpEvent(tw, ButtonHideAnimation)
    ) return 1;

    return 0;
}
