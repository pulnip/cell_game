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
    pObject pData;
} Node;

typedef struct _List{
    Node* head;
    Node* tail;
} List;
int appendNode(const pObject const _pObject, List* list){
    if(_pObject==NULL) return 1;

    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        return 1;
    }
    newNode->pData=_pObject;
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

int deleteNode(const pObject const _pObject, List* list){
    Node* aheadNode=NULL;
    Node* rmNode=list->head;

    if(list->head!=NULL){
        while(_pObject!=rmNode->pData){
            aheadNode=rmNode;
            rmNode=rmNode->next;
            if(rmNode==NULL) break;
        }

        if(rmNode!=NULL){
            aheadNode->next=rmNode->next;

            return 0;
        }
        else return 1;
    }
    else return 1;
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
    ) {
        return 1;
    }

    if( (0    > _vkey) ||
        (0xff < _vkey)
    ) {
        return 1;
    }

    return 0;
}

#define True 1
#define False 0

typedef struct _Trigger{
    Bool isHidden;
    Rect pos;
    int key;
    List OnClickEvent;
    Bool isToggled;
} Trigger;

Trigger* createTrigger(Rect rect, int _vkey){
    if (checkTriggerArg(rect, _vkey)){
        return NULL;
    }

    Trigger* t=(Trigger*)malloc(sizeof(Trigger));
    if(t==NULL) return NULL;

    t->isHidden=True;

    t->pos.Left=rect.Left;
    t->pos.Top=rect.Top;
    t->pos.Right=rect.Right;
    t->pos.Bottom=rect.Bottom;

    t->key=_vkey;

    t->OnClickEvent.head=NULL;
    t->OnClickEvent.tail=NULL;

    t->isToggled=False;

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

int appendEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return appendNode(func, &(t->OnClickEvent));
}

int deleteEvent(Trigger* t, TriggerEvent func){
    if(t==NULL) return 1;

    return deleteNode(func, &(t->OnClickEvent));
}

int drawTriggers(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        Trigger* t=n->pData;

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

        n=n->next;
    }

    return 0;
}

int runTriggerEvent(Trigger* t){
    Node* en=t->OnClickEvent.head; // TriggerEvent Node

    while(en!=NULL){
        TriggerEvent tbe=en->pData;
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

int checkTriggered(void){
    Node* n=Triggers.head;
    if(n==NULL) return 1;

    // Don\'t Copy
    KeyState lastState={0, 0, 0, 0};
    //

    while(n!=NULL){
        Trigger* t=n->pData;
        
        short tmpKey=GetKeyState(t->key);
        Bool Pressed=0;
        if(tmpKey&0x8000){
            Pressed=1;
        }
        Bool Toggled=tmpKey&0x1;

        Bool isChanged=
            ((lastState.bPressed)^Pressed);
        
        lastState.bPressed=Pressed;
        lastState.bToggled=Toggled;

        if(isChanged){
            runTriggerEvent(t);
        }

        n=n->next;
    }

    return 0;
}

int deleteTrigger(Trigger* t){
    Node* en=t->OnClickEvent.head;

    while(en!=NULL){
        en=en->next;
        free(en);
    }

    free(t);
}

int deleteTriggers(void){
    Node* n=Triggers.head;

    while(n!=NULL){
        deleteTrigger(n->pData);

        n=n->next;
        free(n);
    }

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

void lambda1(Trigger* t){
    static int log=0;
    if(log==0){
        showTrigger(t);
        log=1;
    }
    else {
        hideTrigger(t);
        log=0;
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

    Rect rect;
    rect.Left=4;
    rect.Right=12;
    rect.Top=3;
    rect.Bottom=6;

    Trigger* t=createTrigger(rect, VK_SPACE);

    // Appensasdsdaaaaaaa
    appendEvent(t, lambda1);

    while(True){
        int ks=GetKeyState(VK_ESCAPE);
        ks&=0x8000;

        if(ks) break;
        copyScreenFromBG();

        checkTriggered();
        drawTriggers();
        drawScreen();
    }

    deleteTriggers();

    return 0;
}
