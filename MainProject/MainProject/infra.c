#include "Infra.h"

KeyState keys[0x100];
VerticalScrollWindow vsw;

UserInput userInput;

int initInfra(void) {
    initScreen();

    initTriggers();
    makeTrigger();
    // initScrollWindow is in makeTrigger

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

    updateScreen1();

    checkTriggered();
    updateScrollWindow();

    return 0;
}
int updateInfra2(void){
    

    updateScreen2();

    return 0;
}

int deleteInfra(void){
    deleteTriggers();
    deleteScrollWindow();

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

        int key1=(t->key)&0xff;

        if(keys[key1].bPressed) {
            if(keys[key1].bKeyDown)runOnKeyDownEvent(t);
            runKeyDownEvent(t);}
        else{
            if(keys[key1].bKeyUp)  runOnKeyUpEvent(t);
            runKeyUpEvent(t); 
        }
    }

    return 0;
}
int makeTrigger(void) {
    Rect rectq={ 14, 31, 29, 32};
    Rect recte={ 32, 31, 40, 32};
    Rect rectsc={ 2, 32,  5, 39};

    Trigger* tq=createToggleButton(rectq, 'Q');
    if(tq==NULL) return 1;
    Trigger* te=createVanillaButton(recte, 'E');
    if(te==NULL) return 1;
    Trigger** VSBar=createVerticalScrollBar(rectsc, 'W', 'S');
    if(VSBar==NULL) return 1;

    initScrollWindow(VSBar[0], VSBar[1]);

    free(VSBar);
    return 0;
}

int initScrollWindow(Trigger* ut, Trigger* dt){
    vsw.pUpTrigger=ut;
    vsw.pDownTrigger=dt;

    initList(&(vsw.messageList));
    initList(&(vsw.msgTriggers));

    char* msg1="MESSAGE 1";
    char* msg2="MESSAGE 2";
    char* msg3="MESSAGE 3";
    char* msg4="MESSAGE 4";
    char* msg5="MESSAGE 5";
    char* msg6="MESSAGE 6";
    char* msg7="MESSAGE 7";
    char* msg8="MESSAGE 8";
    char* msg9="MESSAGE 9";
    char* msga="MESSAGE 10";

    appendNode(msg1, &(vsw.messageList));
    appendNode(msg2, &(vsw.messageList));
    appendNode(msg3, &(vsw.messageList));
    appendNode(msg4, &(vsw.messageList));
    appendNode(msg5, &(vsw.messageList));
    appendNode(msg6, &(vsw.messageList));
    appendNode(msg7, &(vsw.messageList));
    appendNode(msg8, &(vsw.messageList));
    appendNode(msg9, &(vsw.messageList));
    appendNode(msga, &(vsw.messageList));

    Trigger* t1=createVanillaButton((Rect){0, 0, 1, 1}, '1');
    Trigger* t2=createVanillaButton((Rect){0, 0, 1, 1}, '2');
    Trigger* t3=createVanillaButton((Rect){0, 0, 1, 1}, '3');

    appendNode(t1, &(vsw.msgTriggers));
    appendNode(t2, &(vsw.msgTriggers));
    appendNode(t3, &(vsw.msgTriggers));

    appendOnKeyDownEvent(ut,   ScrollUpMsgPos);
    appendOnKeyDownEvent(dt, ScrollDownMsgPos);

    vsw.msglistPos=0;

    return 0;
}
int updateScrollWindow(void){
    Node* mn=vsw.messageList.head;
    Node* tn=vsw.msgTriggers.head;

    size_t msglistLen=getListLen(&(vsw.messageList));

    Coord msgOrigin={
        vsw.pUpTrigger->pos.Right+3,
        vsw.pUpTrigger->pos.Top
    };

    for(int i=0; i<vsw.msglistPos; ++i){
        if(mn==NULL) return 0;

        if (tn != NULL) {
            hideTrigger(tn->pObject);
            tn = tn->next;
        }
        mn=mn->next;
    }

    for(int i=0; i<7; ++i){
        if(mn==NULL) return 0;
        char* msg=mn->pObject;

        if(tn!=NULL){
            Trigger* t=tn->pObject;
        
            size_t len=getCStringLen(msg);
            setPos(t, (Rect){
                msgOrigin.x,
                msgOrigin.y+i,
                CONSOLE_WIDTH*2/3-2,
                msgOrigin.y+i+1
            });
            tn=tn->next;
        }
        printMsgToScreen(msg, (Coord){msgOrigin.x, msgOrigin.y+i});

        mn=mn->next;
    }

    while(tn!=NULL){
        hideTrigger(tn->pObject);

        tn=tn->next;
    }

    return 0;
}
int deleteScrollWindow(void){
    eraseNonHeapObjectList(&(vsw.messageList));
    eraseNonHeapObjectList(&(vsw.msgTriggers));

    return 0;
}

size_t getCStringLen(char* str){
    int len=0;
    while(str[len]!='\0') ++len;
    return len;
}
int printMsgToScreen(char* msg, Coord coord){
    int msgLen=(int)getCStringLen(msg);

    int min = ((msgLen < CONSOLE_WIDTH * 2 / 3 - 2 - coord.x) ?
        msgLen :
        CONSOLE_WIDTH * 2 / 3 - 2 - coord.x
    );

    for(int i=0; i<min; ++i){
        screen[coord.y][coord.x + i].Char.AsciiChar=msg[i];
    }

    return 0;
}

void ScrollUpMsgPos(void* obj){
    Trigger* t=obj;

    if(vsw.msglistPos>0) vsw.msglistPos-=1;
}
void ScrollDownMsgPos(void* obj){
    Trigger* t=obj;

    if((size_t)vsw.msglistPos+7 < getListLen(&(vsw.messageList))) vsw.msglistPos+=1;
}
