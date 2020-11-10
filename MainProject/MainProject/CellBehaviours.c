#include "CellBehaviours.h"

// <Sensoring>

void seeEnemy(Cell* const pCell){
    Coord const _pos=pCell->pos;
    isCell const EnemyId=3-pCell->id;

    for(int _y=_pos.y-MAX_SIGHT, _x=0; _y<=_pos.y-MAX_SIGHT; ++_y){
        if( (0<=_y) && (_y<CONSOLE_HEIGHT) )
        {
            for(_x=_pos.x-MAX_SIGHT      ; _x<=_pos.x-MAX_SIGHT; ++_x){
                if( (_x<0)||(_x>=CONSOLE_WIDTH) )
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

    for(int _y=_pos.y-MAX_SIGHT, _x=0; _y<=_pos.y-MAX_SIGHT; ++_y){
        if( (0<=_y) && (_y<CONSOLE_HEIGHT) )
        {
            for(_x=_pos.x-MAX_SIGHT      ; _x<=_pos.x-MAX_SIGHT; ++_x){
                if( (_x<0)||(_x>=CONSOLE_WIDTH) )
                {
                    if( (_y!=_pos.y) && (_x!=_pos.x) ){
                        if(map[_y][_x].Cell==FriendId){
                            pCell->forward.x=_x;
                            pCell->forward.y=_y;
                            break;
                        }
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
                if( (_x<0)||(_x>=CONSOLE_WIDTH) )
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



BEHAVIOUR_t moveCloser;
BEHAVIOUR_t moveFurther;
// it is about the Sight.

BEHAVIOUR_t getFoodFromMap;
BEHAVIOUR_t getPointFromMap;
BEHAVIOUR_t doCannibal;

BEHAVIOUR_t divide;