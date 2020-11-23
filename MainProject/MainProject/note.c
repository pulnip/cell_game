#include <stdio.h>
#include <Windows.h>

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

#define MAP_FILE_PATH ".\\map.txt"

#define _CRT_SECURE_NO_WARNINGS

enum Color{
    FG_BLACK  =0x00,
    FG_BLUE   =0x01,
    FG_GREEN  =0x02,
    FG_CYAN   =0x03,
    FG_RED    =0x04,
    FG_MAGENTA=0x05,
    FG_YELLOW =0x06,
    FG_WHITE  =0x07,

    FG_INTENSE=0x08,

    BG_BLACK  =0x00,
    BG_BLUE   =0x10,
    BG_GREEN  =0x20,
    BG_CYAN   =0x30,
    BG_RED    =0x40,
    BG_MAGENTA=0x50,
    BG_YELLOW =0x60,
    BG_WHITE  =0x70,

    BG_INTENSE=0x80
};

CHAR_INFO background[CONSOLE_HEIGHT][CONSOLE_WIDTH];
CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
HANDLE hStdOut;

int setConsoleDefault(){
    hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut==NULL) return 1;
    
    SMALL_RECT rectWindowSize;
    rectWindowSize.Left=rectWindowSize.Top=0;
    rectWindowSize.Right=CONSOLE_WIDTH-1;
    rectWindowSize.Bottom=CONSOLE_HEIGHT-1;

    COORD coord;
    coord.X=CONSOLE_WIDTH;
    coord.Y=CONSOLE_HEIGHT;

    if( (!(SetConsoleScreenBufferSize(hStdOut, coord))) ||
        (!(SetConsoleWindowInfo(hStdOut, TRUE, &rectWindowSize)))
    ) return 1;

    //system(f"mode con cols=${CONSOLE_WIDTH} lines=${CONSOLE_HEIGHT}")

    return 0;
}

int readScreenFromFile(){

#ifdef _MSC_VER
    FILE* map_in = NULL;
    FILE* log = NULL;
    fopen_s(&map_in, MAP_FILE_PATH, "rt");
    fopen_s(&log, ".\\log.txt", "wt");
#else
    FILE* map_in=fopen(MAP_FILE_PATH, "rt");
    FILE* log=fopen(".\\log.txt", "wt");
#endif
    if((map_in==NULL)||(log==NULL)){
        puts("Couldn\'t open file.");
        return 1;
    }

    char buffer[CONSOLE_WIDTH];

    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        size_t bytes=fread(buffer, sizeof(char), sizeof(buffer)/sizeof(char), map_in);
        while(fgetc(map_in) != '\n');

        fprintf(log, "[%d Bytes]: %s\n", bytes, buffer);

        for(int j=0; j<CONSOLE_WIDTH; ++j){
            background[i][j].Char.AsciiChar=buffer[j];
            background[i][j].Attributes=BG_BLACK|FG_WHITE;
        }
    }

    fclose(map_in);
    fclose(log);

    return 0;
}







typedef unsigned char Bool;

typedef struct _Rect{
    int Left;
    int Top;
    int Right;
    int Bottom;
} Rect;


typedef void* pObject;
typedef struct _Node{
    struct _Node* next;
    pObject pObject;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;
int appendNode(const pObject const _pObj, List* list){
    if((_pObj==NULL)||(list==NULL)) return 1;

    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return 1;
    }
    newNode->pObject=_pObj;
    newNode->next=NULL;

    if(list->tail==NULL){
        list->head=newNode;
        list->tail=newNode;
    }
    else{
        list->tail->next=newNode;
        list->tail=newNode;
    }
    return 0;
}

// naming rule
// remove = entity still alive
// delete = entity is killed

pObject removeNode(const pObject const _pObj, List* list){
    if((_pObj==NULL)||(list==NULL)) return NULL;

    Node* aheadNode=NULL;
    Node* rmNode=list->head;
    pObject res=NULL;

    while(rmNode!=NULL){
        if(rmNode->pObject==_pObj) break;

        aheadNode=rmNode;
        rmNode=rmNode->next;
    }

    res=rmNode->pObject;
    if     (rmNode==list->head) list->head=rmNode->next;
    else if(rmNode==list->tail) list->tail=aheadNode;
    else                        aheadNode->next=rmNode->next;
    free(rmNode);

    return res;
}
int deleteNode(const pObject const _pObj, List* list){
    pObject lastRef=removeNode(_pObj, list);
    if(lastRef==NULL) return 1;

    free(lastRef);
    return 0;
}

int eraseStaticDataList(List* const list) {
    if(list==NULL) return 1;

    Node* n=list->head;
    list->head=NULL;

    while(n!=NULL){
        Node* temp=n->next;
        free(n);

        n=temp;
    }

    list->tail=NULL;

    return 0;
}
int eraseDynamicDataList(List* const list) {
    if(list==NULL) return 1;

    Node* n=list->head;
    list->head=NULL;

    while(n!=NULL){
        Node* temp=n->next;
        free(n->pObject);
        free(n);

        n=temp;
    }

    list->tail=NULL;

    return 0;
}

List Triggers;

int initEventTriggerList(void){
    Triggers.head=NULL;
    Triggers.tail=NULL;
}

#define CONSOLE_LEFT 0
#define CONSOLE_RIGHT CONSOLE_WIDTH
#define CONSOLE_TOP 0
#define CONSOLE_BOTTOM CONSOLE_HEIGHT

int checkTriggerArg(Rect rect, int _vkey){
    if( (CONSOLE_LEFT  > rect.Left  ) ||
        (CONSOLE_RIGHT <=rect.Right ) ||
        (CONSOLE_TOP   > rect.Top   ) ||
        (CONSOLE_BOTTOM<=rect.Bottom) ||
        (rect.Right -rect.Left< 1   ) ||
        (rect.Bottom-rect.Top < 1   )
    ) return 1;

    if( (0    > _vkey) ||
        (0xff < _vkey)
    ) return 1;

    return 0;
}

#define True 1
#define False 0

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

Trigger* createTrigger(Rect rect, int _vkey){
    if (checkTriggerArg(rect, _vkey)){
        return NULL;
    }

    Trigger* t=(Trigger*)malloc(sizeof(Trigger));
    if(t==NULL) return NULL;

    t->isHidden=True;

    t->pos.Left  =rect.Left;
    t->pos.Top   =rect.Top;
    t->pos.Right =rect.Right;
    t->pos.Bottom=rect.Bottom;

    t->key=_vkey;

    t->OnKeyDownEvent.head=t->OnKeyDownEvent.tail=NULL;
    t->  KeyDownEvent.head=t->  KeyDownEvent.tail=NULL;
    t->OnKeyUpEvent.head  =t->OnKeyUpEvent.tail  =NULL;
    t->  KeyUpEvent.head  =t->  KeyUpEvent.tail  =NULL;

    t->log=0;

    appendNode(t, &Triggers);

    return t;
}

int showTrigger(Trigger* t){
    if(t==NULL) return 1;

    t->isHidden=False;
    return 0;
}

int hideTrigger(Trigger* t){
    if(t==NULL) return 1;

    t->isHidden=True;
    return 0;
}

int getIsHidden(Trigger* t){
    if(t==NULL) return -1;

    return t->isHidden;
}

int setPos(Trigger* t, Rect pos){
    if(t==NULL) return 1;

    t->pos.Left  =pos.Left;
    t->pos.Top   =pos.Top;
    t->pos.Right =pos.Right;
    t->pos.Bottom=pos.Bottom;

    return 0;
}

Rect getPos(Trigger* t){
    if(t==NULL) return (Rect){0, 0, 0, 0}; // return null Rect

    return t->pos;
}

int setKey(Trigger* t, int _vkey){
    if(t==NULL) return 1;

    t->key=_vkey;
    return 0;
}

int getKey(Trigger* t){
    if(t==NULL) return 0;

    return t->key;
}

typedef void (*TriggerEvent)(Trigger*);

int appendOnKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnKeyDownEvent));
}
int appendKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->KeyDownEvent));
}
int appendOnKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnKeyUpEvent));
}
int appendKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->KeyUpEvent));
}

// <remove event func>
int removeOnKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->OnKeyDownEvent)) ) return 1;
    return 0;
}
int removeKeyDownEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->KeyDownEvent)) ) return 1;
    return 0;
}
int removeOnKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->OnKeyUpEvent)) ) return 1;
    return 0;
}
int removeKeyUpEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;
    
    if( !removeNode(func, &(t->KeyUpEvent)) ) return 1;
    return 0;
}
// </remove Event func>

int drawTrigger(Trigger* t){
    if(t==NULL) return 1;

    if( !(t->isHidden) ){
        Rect rect=t->pos;

        for(    int i=rect.Top ; i<rect.Bottom; ++i){
            for(int j=rect.Left; j<rect.Right ; ++j){
                CHAR_INFO* pci=&screen[i][j];
                pci->Char.AsciiChar=' ';
                pci->Attributes=FG_WHITE|BG_WHITE;   
            }
        }
    }

    return 0;
}
int drawTriggers(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        drawTrigger(n->pObject);

        n=n->next;
    }

    return 0;
}

int runOnKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyDownEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyDownEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyDownEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runOnKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->OnKeyUpEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}
int runKeyUpEvent(Trigger* t){
    if(t==NULL) return 1;
    Node* en=t->KeyUpEvent.head;

    while(en!=NULL){
        TriggerEvent tbe=en->pObject;
        tbe(t);

        en=en->next;
    }

    return 0;
}

typedef struct _KeyState{
    Bool bKeyDown;
    Bool bKeyUp;

    Bool bPressed;
    Bool bToggled;
} KeyState;

KeyState keys[0x100];

void getKBInput(){
    for(int i=0; i<0x100; ++i){
        KeyState lastState=keys[i];
        
        short tmpKey=GetKeyState(i);
        keys[i].bPressed = (tmpKey&0x8000)>>(8*sizeof(short)-1)&0x1;
        keys[i].bToggled = tmpKey&0x1;

        Bool isChanged=(lastState.bPressed)^(keys[i].bPressed);
        
        keys[i].bKeyDown =  keys[i].bPressed & isChanged;
        keys[i].bKeyUp   = !keys[i].bPressed & isChanged;
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

int deleteTrigger(Trigger* t){
    if(t==NULL) return 1;

    eraseStaticDataList(&(t->OnKeyDownEvent));
    eraseStaticDataList(&(t->  KeyDownEvent));
    eraseStaticDataList(&(t->OnKeyUpEvent  ));
    eraseStaticDataList(&(t->  KeyUpEvent  ));

    return deleteNode(t, &Triggers);
}

int deleteTriggers(void){
    Node* n=Triggers.head;

    while(n!=NULL){
        Node* temp=n->next;
        deleteTrigger(n->pObject);
        
        n=temp;
    }
    //implicit All Node deleted.
    
    return 0;
}










int copyScreenFromBG(void){
    for(    int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH;  ++j){
            screen[i][j]=background[i][j];
        }
    }

    return 0;
}

int drawScreen(void){
    COORD screenSize={CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD coord={0, 0};
    SMALL_RECT WriteRegion={ //Left, Top. Right, Bottom
        0, 0,
        CONSOLE_WIDTH-1,
        CONSOLE_HEIGHT-1
    };

    WriteConsoleOutputA(
        hStdOut,
        (CHAR_INFO*)screen, screenSize, coord,
        &WriteRegion
    );

    return 0;
}










void ButtonShowAnimation(Trigger* t){
    showTrigger(t);
}
void ButtonHideAnimation(Trigger* t){
    hideTrigger(t);
}
void ToggleButtonAnimation(Trigger* t){
    if((t->log)&0x1){
        hideTrigger(t);
        t->log=((t->log)&(-1U-0x1));
    }
    else{
        showTrigger(t);
        t->log=(t->log)|0x1;
    }
}

int main(void){
    // <write screen>
    if (setConsoleDefault() ||
        readScreenFromFile()
    ) {   
        return 1;
    }
    drawScreen();

    initEventTriggerList();

    Rect rectq={3, 34, 19, 35};
    Rect rectw={22, 34, 31, 35};


    Trigger* tq=createTrigger(rectq, 'Q');
    Trigger* tw=createTrigger(rectw, 'W');

    appendOnKeyDownEvent(tq, ToggleButtonAnimation);
    appendOnKeyDownEvent(tw, ButtonShowAnimation);
    appendOnKeyUpEvent(tw, ButtonHideAnimation);
        
    while(True){
        if(GetKeyState(VK_ESCAPE)&0x8000) break;
        copyScreenFromBG();

        getKBInput();
        checkTriggered();
        drawTriggers();

        drawScreen();
    }

    deleteTriggers();

    return 0;
}
