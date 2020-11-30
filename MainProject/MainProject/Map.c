#include "Map.h"

#include <string.h>

Pixel map[MAP_HEIGHT][MAP_WIDTH];

int initMap(){
    memset(map, 0, sizeof(Pixel)*MAP_HEIGHT*MAP_WIDTH);

    return 0;
}

void updateMap(){
    if(getFoodAmount() < MaxFoodRegen){
        spreadFood();
    }

    if(getPointAmount() < MaxPointRegen){
        spreadPoint();
    }
}

void spreadFood(void){
    for(     int i=0; i<MAP_HEIGHT; ++i){
        for( int j=0; j<MAP_WIDTH ; ++j){
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
    for(    int i=0; i<MAP_HEIGHT; ++i){
        for(int j=0; j<MAP_WIDTH ; ++j){
            res += map[i][j].Food;
        }
    }

    return res;
}

void spreadPoint(void){
    for(    int i=0; i<MAP_HEIGHT; ++i){
        for(int j=0; j<MAP_WIDTH ; ++j){
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
    for(    int i=0; i<MAP_HEIGHT; ++i){
        for(int j=0; j<MAP_WIDTH ; ++j){
            res += map[i][j].Point;
        }
    }

    return res;
}
