#ifndef __INC_SCREEN
#define __INC_SCREEN

#ifndef __INC_BASE
#include "base.h"
#endif

/* Preview

CONSOLE_WIDTH
0#########1#########2#########3#########4#########5#########6#########7#########8#########9#########A#########B#########C
#+--------------------------------------------------------------------------------------------------------------------+#
#|MAP_WIDTH                                                                                                           |#
#|                                                                                                                    |#
#|   MAP                                                                                                              |#
#|                                                                                                                    |#
#|MAP_HEIGHT                                                                                                          |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
1|                                                                                                                    |1
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
2|                                                                                                                    |2
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
#|                                                                                                                    |#
3+--------------------------------------------------------------------------------------------------------------------+3
#                                                                                                                      #
# GAME_INFORMATION AND STAT                                                                                            #
#                                                                                                                      #
#                                                                                                                      #
#                                                                                                                      #
#                                                                                                                      #
#                                                                                                                      #
#                                                                                                                      #
0#########1#########2#########3#########4#########5#########6#########7#########8#########9#########A#########B#########C
4                                                                                                                      4
*/

// range expression standard: [a, b)

#ifndef CONSOLE_SIZE
#define CONSOLE_SIZE

#define CONSOLE_TOP 0
#define CONSOLE_BOTTOM 40
#define CONSOLE_LEFT 0
#define CONSOLE_RIGHT 120

#define CONSOLE_WIDTH CONSOLE_RIGHT-CONSOLE_LEFT
#define CONSOLE_HEIGHT CONSOLE_BOTTOM-CONSOLE_TOP

#endif // CONSOLE_SIZE


#ifndef MAP_SIZE
#define MAP_SIZE

#define MAP_TOP CONSOLE_TOP+1 
#define MAP_BOTTOM CONSOLE_BOTTOM*3/4
#define MAP_LEFT CONSOLE_LEFT+1
#define MAP_RIGHT CONSOLE_RIGHT-1

#define MAP_WIDTH MAP_RIGHT-MAP_LEFT
#define MAP_HEIGHT MAP_BOTTOM-MAP_TOP

#endif // MAP_SIZE

extern CHAR_INFO background[CONSOLE_HEIGHT][CONSOLE_WIDTH];
extern CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

#define SCREEN_FILE_PATH ".\\screen.txt"
int readScreenFromFile(void);
// copy from screen.txt to background
int copyScreenFromBG(void);
// copy from background to screen

int drawScreen(void);


#endif // __INC_SCREEN
