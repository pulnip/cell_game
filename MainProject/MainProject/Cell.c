#include "Cell.h"

List UserCells;
List CPUCells;

int SkillPoint;

pBEHAVIOUR_t BehaviourList[]={
    seeEnemy, seeFriend, seeFood,
    moveCloser, moveFurther,
    getFood, getPoint,
    doCannibal,
    divide
};

// <Sensoring>

void seeEnemy(Cell* pCell){
    Coord const _pos=pCell->pos;

    for(        int _y=_pos.y-MAX_SIGHT; _y<=_pos.y+MAX_SIGHT; ++_y){
        if(         (0<=_y) && (_y<CONSOLE_HEIGHT) ) 
        {
            for(int _x=_pos.x-MAX_SIGHT; _x<=_pos.x+MAX_SIGHT; ++_x){
                if( (0<=_x) && (_x<CONSOLE_WIDTH ) ) 
                {
                    if(pCell->id==CPUCell){
                        if(map[_y][_x].isUserCell){
                            pCell->forward.x=_x;
                            pCell->forward.y=_y;
                            break;
                        }
                    }
                    else if(pCell->id==UserCell){
                        if(map[_y][_x].isCPUCell){
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

void seeFriend(Cell* pCell){
    Coord const _pos=pCell->pos;

    for (         int _y = _pos.y - MAX_SIGHT; _y <= _pos.y + MAX_SIGHT; ++_y) {
        if(         (0 <= _y) && (_y < CONSOLE_HEIGHT))
        {
            for ( int _x = _pos.x - MAX_SIGHT; _x <= _pos.x + MAX_SIGHT; ++_x) {
                if( (0 <= _x) && (_x < CONSOLE_WIDTH))
                {
                    if(pCell->id==CPUCell){
                        if(map[_y][_x].isCPUCell){
                            pCell->forward.x=_x;
                            pCell->forward.y=_y;
                            break;
                        }
                    }
                    else if(pCell->id==UserCell){
                        if(map[_y][_x].isUserCell){
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

void seeFood(Cell* pCell){
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

void moveCloser(Cell* pCell) {
    int dx=0, dy=0;
    if( (pCell->forward.x-pCell->pos.x) > 0) dx=1;
    else if( (pCell->forward.x-pCell->pos.x) < 0) dx=-1;

    if( (pCell->forward.y-pCell->pos.y) > 0) dy=1;
    else if( (pCell->forward.y-pCell->pos.y) < 0) dy=-1;

    if( (0 <= pCell->pos.x+dx) && (pCell->pos.x+dx < MAP_WIDTH ) )pCell->pos.x+=dx;
    if( (0 <= pCell->pos.y+dy) && (pCell->pos.y+dy < MAP_HEIGHT) )pCell->pos.y+=dy;
}
void moveFurther(Cell* const pCell){
    int dx=0, dy=0;
    if( (pCell->forward.x-pCell->pos.x) > 0) dx=-1;
    else if( (pCell->forward.x-pCell->pos.x) < 0) dx=1;

    if( (pCell->forward.y-pCell->pos.y) > 0) dy=-1;
    else if( (pCell->forward.y-pCell->pos.y) < 0) dy=1;

    if( (0 <= pCell->pos.x+dx) && (pCell->pos.x+dx < MAP_WIDTH ) )pCell->pos.x+=dx;
    if( (0 <= pCell->pos.y+dy) && (pCell->pos.y+dy < MAP_HEIGHT) )pCell->pos.y+=dy;
}
// </movement>

void getFood(Cell* pCell){
    Pixel* p=&(map[pCell->pos.y][pCell->pos.x]);
    if(p->Food>0){
        p->Food-=1;

        pCell->stat.healthPoint+=10;
    }
}
void getPoint(Cell* const pCell) {
    Pixel* p=&(map[pCell->pos.y][pCell->pos.x]);

    if(p->Point>0){
        SkillPoint+=p->Point;

        p->Point=0;
    }
}
void doCannibal(Cell* pCell){
    Pixel* p=&(map[pCell->pos.y][pCell->pos.x]);
    isCell id=pCell->id;

    Cell* otherCell=searchCellByPos(pCell->pos, id);
    if(otherCell==NULL) return;

    otherCell->stat.healthPoint-=10;
    pCell->stat.healthPoint+=10;
}

void divide(Cell* const pCell) _VOID_FUNC_NOT_IMPLEMENT

Cell* searchCellByPos(Coord _pos, isCell id){
    Node* n=NULL;
    if(id==UserCell) n=UserCells.head;
    else if(id==CPUCell) n=CPUCells.head;

    while(n!=NULL){
        Cell* cell=n->pObject;

        if( (cell->pos.x==_pos.x) && 
            (cell->pos.y==_pos.y)
        ) return cell;

        n=n->next;
    }

    return NULL;
}
