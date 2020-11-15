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
            screen[i][j].Char.AsciiChar=buffer[j];
            screen[i][j].Attributes=BG_BLACK|FG_WHITE;
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


List ToggleButtons;

int initEventTriggerList(void){
    ToggleButtons.head=NULL;
    ToggleButtons.tail=NULL;
}

#define CONSOLE_LEFT 0
#define CONSOLE_RIGHT CONSOLE_WIDTH
#define CONSOLE_TOP 0
#define CONSOLE_BOTTOM CONSOLE_HEIGHT

int checkToggleButtonArg(Rect rect, int _vkey){
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

typedef struct _ToggleButton{
    int id;
    Bool isHidden;
    Rect pos;
    int key;
    List OnClickEvent;
    Bool isToggled;
} ToggleButton;

int createToggleButton(Rect rect, int _vkey){
    if (checkToggleButtonArg(rect, _vkey)){
        return 0;
    }

    ToggleButton* tb=(ToggleButton*)malloc(sizeof(ToggleButton));
    if(tb==NULL) return 0;

    if(ToggleButtons.tail==NULL){
        tb->id=1;
    } else{
        tb->id=((ToggleButton*)(ToggleButtons.tail->pData))->id+1;
    }

    tb->isHidden=True;

    tb->pos.Left=rect.Left;
    tb->pos.Top=rect.Top;
    tb->pos.Right=rect.Right;
    tb->pos.Bottom=rect.Bottom;

    tb->key=_vkey;

    tb->OnClickEvent.head=NULL;
    tb->OnClickEvent.tail=NULL;

    tb->isToggled=False;

    appendNode(tb, &ToggleButtons);

    return tb->id;
}
ToggleButton* searchTrigger(int _id){
    if(ToggleButtons.head==NULL){
        return NULL;
    }
    
    Node* pNode=ToggleButtons.head;

    while(pNode!=NULL){
        if(((ToggleButton*)(pNode->pData))->id == _id){
            return (ToggleButton*)(pNode->pData);
        }

        pNode=pNode->next;
    }

    return NULL;
}

int showTrigger(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->isHidden=False;
    return 0;
}

int hideTrigger(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->isHidden=True;
    return 0;
}

int getIsHidden(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return -1;

    return tb->isHidden;
}

int setPos(int _id, Rect pos){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->pos.Left  =pos.Left;
    tb->pos.Top   =pos.Top;
    tb->pos.Right =pos.Right;
    tb->pos.Bottom=pos.Bottom;

    return 0;
}

Rect getPos(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return (Rect){0, 0, 0, 0}; // return null Rect

    return tb->pos;
}

int setKey(int _id, int _vkey){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    tb->key=_vkey;
    return 0;
}

int getKey(int _id){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 0;

    return tb->key;
}

typedef void (*ToggleButtonEvent)(ToggleButton*);

int appendEvent(int _id, ToggleButtonEvent func){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    return appendNode(func, &(tb->OnClickEvent));
}

int deleteEvent(int _id, ToggleButtonEvent func){
    ToggleButton* tb=searchTrigger(_id);
    if(tb==NULL) return 1;

    return deleteNode(func, &(tb->OnClickEvent));
}

int drawToggleButtons(void){
    Node* n=ToggleButtons.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        ToggleButton* tb=n->pData;

        SMALL_RECT rect;
        rect.Left  =tb->pos.Left;
        rect.Top   =tb->pos.Top;
        rect.Right =tb->pos.Right;
        rect.Bottom=tb->pos.Bottom;

        COORD ciSize;
        ciSize.X=rect.Right-rect.Left;
        ciSize.Y=rect.Bottom-rect.Top;
        CHAR_INFO ciToggleButton[ciSize.Y][ciSize.X];

        COORD bufferCoord={0, 0};

        for(int i=0, j=0; i<ciSize.Y; ++i){
            for(j=0; j<ciSize.X; ++j){
                ciToggleButton[i][j].Char.AsciiChar=' ';
                ciToggleButton[i][j].Attributes
                =(tb->isHidden ? 
                    FG_BLACK|BG_BLACK :
                    FG_WHITE|BG_WHITE
                );
            }
        }
        WriteConsoleOutputA(
            hStdOut,
            (CHAR_INFO*)ciToggleButton, ciSize, bufferCoord,
            &rect
        );

        n=n->next;
    }

    return 0;
}

int runToggleButtonEvent(ToggleButton* tb){
    Node* en=tb->OnClickEvent.head; // ToggleButtonEvent Node

    while(en!=NULL){
        ToggleButtonEvent tbe=en->pData;
        tbe(tb);

        en=en->next;
    }

    return 0;
}

int checkTriggered(void){
    Node* n=ToggleButtons.head;
    if(n==NULL) return 1;

    while(n!=NULL){
        ToggleButton* tb=n->pData;

        int ks=GetKeyState(tb->key);
        ks&=0x8000;
        if(ks){
            runToggleButtonEvent(tb);
        }

        n=n->next;
    }

    return 0;
}














void lambda1(ToggleButton* tb){
    if(GetKeyState('M')&0x8000){
        hideTrigger(tb->id);
    }
    else {
        showTrigger(tb->id);
    }
}

int main(void){
    // <write screen>
    if (setConsoleDefault() ||
        readScreenFromFile()
        ) {
        
        fgetc(stdin);
        return 1;
    }

    COORD mapSize={CONSOLE_WIDTH, CONSOLE_HEIGHT};
    COORD coord={0, 0};
    SMALL_RECT WriteRegion={ //Left, Top. Right, Bottom
        0, 0,
        CONSOLE_WIDTH-1,
        CONSOLE_HEIGHT-1
    };

    WriteConsoleOutputA(
        hStdOut,
        (CHAR_INFO*)screen, mapSize, coord,
        &WriteRegion
    );
    // </write screen>

    initEventTriggerList();

    Rect rect;
    rect.Left=5;
    rect.Right=10;
    rect.Top=3;
    rect.Bottom=6;

    int id=createToggleButton(rect, VK_SPACE);

    // Appensasdsdaaaaaaa
    appendEvent(id, lambda1);

    while(True){
        int ks=GetKeyState(VK_ESCAPE);
        ks&=0x8000;

        if(ks) break;
        checkTriggered();
        drawToggleButtons();
    }

    return 0;
}
