#include <stdio.h>

int A(void){
    printf("A ");
    return 0;
}
int B(void){
    printf("B ");
    return 0;
}
int C(void){
    printf("C ");
    return 1; // Abnormal Terminate
}
int D(void){
    printf("D ");
    return 0;
}

int main(void){
    if( !(
        A() ||
        B() ||
        C() ||
        D()
    )){
        printf("BREAK 1\n");
    }
    printf("END 1\n");

    if(
        A() &&
        B() &&
        C() &&
        D()
    ){
        printf("BREAK 2\n");
    }
    printf("END 2\n");
}