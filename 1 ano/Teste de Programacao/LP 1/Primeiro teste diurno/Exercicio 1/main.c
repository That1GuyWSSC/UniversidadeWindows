#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    float n= -2, p = 4, c = 1;

    float media = mediaTresValores(n, p, c);


    printf("Media entre %.2f, %.2f , %.2f = %.2f", n , p, c, media);
}