#include <stdio.h>
#include <Windows.h>

typedef unsigned char Bool
#ifndef True
#define True 1
#define False 0
#endif

int OnStart();
int OnUpdate();
int OnDestroy();
