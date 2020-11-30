#ifndef __INC_USER_CELL
#define __INC_USER_CELL

#include "SuperHeader.h"
#include "LinkedList.h"

#include "Cell.h"
#include "Map.h"

#include "Infra.h"

#include <time.h>

#define PROTO_USER_CELL_NUMBER 20

StatusFunc initUserCell;
int updateUserCell(time_t ElapsedTime);
StatusFunc deleteUserCell;


#endif // __INC_USER_CELL
