#include "Cell.h"

pBEHAVIOUR_t const BehaviourList[]={
    seeEnemy, seeFriend, seeFood,
    moveCloser, moveFurther,
    getFood, getPoint,
    doCannibal,
    divide
};

// <Sensoring>

void seeEnemy(Cell* const pCell){
    Coord const _pos=pCell->pos;
    isCell const EnemyId=3-pCell->id;

    for(    int _y=_pos.y-MAX_SIGHT; _y<=_pos.y+MAX_SIGHT; ++_y){
        if(     (0<=_y) && (_y<CONSOLE_HEIGHT) ) 
        {
            for(int _x=_pos.x-MAX_SIGHT; _x<=_pos.x+MAX_SIGHT; ++_x){
                if( (0<=_x) && (_x<CONSOLE_WIDTH ) ) 
                {
                    if(map[_y][_x].Cell==EnemyId){
                        pCell->forward.x=_x;
                        pCell->forward.y=_y;
                        break;
                    }
                }
            }
        }
    }
}

void seeFriend(Cell* const pCell){
    Coord const _pos=pCell->pos;
    isCell const FriendId=pCell->id;

    for (int _y = _pos.y - MAX_SIGHT; _y <= _pos.y + MAX_SIGHT; ++_y) {
        if ((0 <= _y) && (_y < CONSOLE_HEIGHT))
        {
            for (int _x = _pos.x - MAX_SIGHT; _x <= _pos.x + MAX_SIGHT; ++_x) {
                if ((0 <= _x) && (_x < CONSOLE_WIDTH))
                {
                    if (map[_y][_x].Cell == FriendId) {
                        pCell->forward.x = _x;
                        pCell->forward.y = _y;
                        break;
                    }
                }
            }
        }
    }
}

void seeFood(Cell* const pCell){
    Coord const _pos=pCell->pos;

    Coord FoodPos=_pos;
    SmallSize_t MaxFood=map[_pos.y][_pos.x].Food;

    for(int _y=_pos.y-MAX_SIGHT, _x=0; _y<=_pos.y-MAX_SIGHT; ++_y){
        if( (0<=_y) && (_y<CONSOLE_HEIGHT) )
        {
            for(_x=_pos.x-MAX_SIGHT      ; _x<=_pos.x-MAX_SIGHT; ++_x){
                if( (0<=_x) && (_x<CONSOLE_WIDTH) )
                {
                    if(map[_y][_x].Food>MaxFood){
                        MaxFood=map[_y][_x].Food;
                        FoodPos.x=_x;
                        FoodPos.y=_y;
                    }
                }
            }
        }
    }

    pCell->forward.x=FoodPos.x;
    pCell->forward.y=FoodPos.y;
}

// </Sensoring>


// <movement>
// it is about the Sight.

void moveCloser(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT
void moveFurther(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT
// </movement>

void getFood(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT
void getPoint(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT
void doCannibal(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT

void divide(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT