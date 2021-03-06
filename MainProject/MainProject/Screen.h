#ifndef __INC_SCREEN
#define __INC_SCREEN

#include "SuperHeader.h"

#include "Map.h"
#include "EventBlock.h"

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

extern CHAR_INFO screen[CONSOLE_HEIGHT][CONSOLE_WIDTH];

StatusFunc initScreen;
StatusFunc updateScreen1;
StatusFunc updateScreen2;

StatusFunc setConsoleDefault;
#define SCREEN_FILE_PATH ".\\screen.txt"
StatusFunc readScreenFromFile;
// copy from screen.txt to background
StatusFunc copyScreenFromBG;
// copy from background to screen

StatusFunc filterPixelToCI;

int drawTrigger(Trigger*);
StatusFunc drawTriggers;

StatusFunc drawScreen;

#endif // __INC_SCREEN
