#include <stdio.h>

void incremeta(int a){

    a++;

}

void incrementapontador(int *a){

    (*a)++;

}

int main(){

    int a=10;
    int b=5;
    a += b;

    printf("%d , %d", a,b);
    int x= 10;
    int *y;
    *y = 52;

    printf("%d \n %d\n",x ,*y);
    incremeta(x);
    incrementapontador(y);
    printf("%d \n %d\n",x ,*y);
    printf("y: %d %d %d \n x:%d %d\n", &y, (*y), y, x, &x);
    

}