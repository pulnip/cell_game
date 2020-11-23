#ifndef __INC_SCREEN
#define __INC_SCREEN

#include "SuperHeader.h"

#include <Windows.h>
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

int initScreen();
int updateScreen();

#define SCREEN_FILE_PATH ".\\screen.txt"
int readScreenFromFile(void);
// copy from screen.txt to background
int copyScreenFromBG(void);
// copy from background to screen

int drawScreen(void);


#endif // __INC_SCREEN
