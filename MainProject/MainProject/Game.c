#include "base.h"
#include "Game.h"

#include <stdlib.h>
#include <time.h>

int initGame(void){
    srand(time(NULL));
    initMap();
    spreadFoodOnMap();
}

int updateGame(void){
    if(getFoodAmount() < MaxFoodRegen){
        spreadFoodOnMap();
    }
}

int initMap(){
    memset(map, 0, sizeof(Pixel)*CONSOLE_HEIGHT*CONSOLE_WIDTH);
}

int updateMap(){
    if(getFoodAmount() < MaxFoodRegen){
        spreadFoodOnMap();
    }

    if(getPointAmount() < MaxPointRegen){
        spreadPointOnMap();
    }
}

int spreadFood(void){
    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++j){
            if(map[i][j].Food + 1 != 0){
                int p=GetRandom(0, 100);
                map[i][j].Food+=(
                    p < FoodGenerateProbability ?
                    1 : 0
                );
            }
        }
    }
}

int getFoodAmount(void){
    int res=0;
    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++j){
            res += map[i][j].Food;
        }
    }

    return res;
}

int spreadPoint(void){
    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++j){
            if(map[i][j].Point + 1 != 0){
                int p=GetRandom(0, 100);
                map[i][j].Point+=(
                    p < PointGenerateProbability ?
                    1 : 0
                );
            }
        }
    }
}

int getPointAmount(void){
    int res=0;
    for(int i=0; i<CONSOLE_HEIGHT; ++i){
        for(int j=0; j<CONSOLE_WIDTH; ++j){
            res += map[i][j].Point;
        }
    }

    return res;
}
