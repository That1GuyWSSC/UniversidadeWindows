#include "Funcoes.h"

void troca(int x, int y){

    int t;
    t = x;
    x = y;
    y = t;
}


void trocaII(int *x, int *y){

    int t;
    t = *x;
    *x = *y;
    *y = t;
}

boolean calculaArea(int raio, float *area){
    if(raio < 0){

        *area=-1;
        return false;

    }
    else
    {
        *area = 3.14 * raio * raio;
        return true;
    }
    

}

void inc(int *x){

    (*x)++;
}