#ifndef __SUPER_HEADER
#define __SUPER_HEADER

#ifndef True
#define True 1
#define False 0
#endif

typedef unsigned char Bool;
typedef unsigned char SmallSize_t;

typedef struct _Coord{
    int x;
    int y;
} Coord;

typedef struct _Rect{
    int Left;
    int Top;
    int Right;
    int Bottom;
} Rect;

#define CONSOLE_TOP 0
#define CONSOLE_BOTTOM 40
#define CONSOLE_LEFT 0
#define CONSOLE_RIGHT 120

#define CONSOLE_WIDTH CONSOLE_RIGHT-CONSOLE_LEFT
#define CONSOLE_HEIGHT CONSOLE_BOTTOM-CONSOLE_TOP

#define GetRandom(min, max) ( \
    (rand() % (int)((max)-(min))) + (min) \
)
// GetRandom(-5, 10) = -5 ~ 9 integer

#endif // __SUPER_HEADER
