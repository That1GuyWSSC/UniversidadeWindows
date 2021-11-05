#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

int main(){

    int x = 1;
    inc(&x);
    int y = 3;

    printf("antes : x=%d - Y=%d\n", x, y);
    troca(x,y);
    
    printf("Depois : x=%d - Y=%d\n", x, y);
       trocaII(&x,&y);
    
    printf("Depois &: x=%d - Y=%d\n", x, y);


    

    
 

}