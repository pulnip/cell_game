#include <stdio.h>

typedef void (BEHA)(void);


BEHA f;
void f(void){
    printf("Hi");
}

int main(void){
    f();
}