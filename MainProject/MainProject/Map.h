#ifndef __INC_MAP
#define __INC_MAP

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

#define CONSOLE_WIDTH CONSOLE_BOTTOM-CONSOLE_TOP
#define CONSOLE_HEIGHT CONSOLE_RIGHT-CONSOLE_LEFT

#endif // CONSOLE_SIZE


#ifndef MAP_SIZE
#define MAP_SIZE

#define MAP_TOP CONSOLE_TOP+1 
#define MAP_BOTTOM CONSOLE_BOTTOM*3/4
#define MAP_LEFT CONSOLE_LEFT+1
#define MAP_RIGHT CONSOLE_RIGHT-1

#define MAP_WIDTH MAP_BOTTOM-MAP_TOP
#define MAP_HEIGHT MAP_RIGHT-MAP_LEFT

#endif // MAP_SIZE


#define MAP_FILE_PATH ".\\map.txt"
int readScreenFromFile(void);

#endif // __INC_MAP