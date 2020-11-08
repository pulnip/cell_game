#ifndef __INC_GAME
#define __INC_GAME

#define FoodGenerateProbability 30 // unit: [%]
#define PointGenerateProbability 5 // unit: [%]

#define MaxFoodRegen CONSOLE_HEIGHT*CONSOLE_WIDTH
#define MaxPointRegen CONSOLE_HEIGHT*CONSOLE_WIDTH/10


int initMap(void);
int updateMap(void);
int spreadFoodOnMap(void);
int spreadPointOnMap(void);

#endif // __INC_GAME