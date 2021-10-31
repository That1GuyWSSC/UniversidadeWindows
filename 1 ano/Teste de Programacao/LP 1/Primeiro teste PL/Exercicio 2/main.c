#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


int main(){

    int numeros[50];
    int par[40];

    for (int i = 0; i < 50; i++)
    {
        numeros[i]= 10* i;
        printf("%d\n", numeros[i]);
    }
    
   for (int i = 0; i < 40; i++)
   {
       par[i]= maiorValorPar(numeros, 50);
       printf("%d\n", par[i]);
   }

   for (int i = 0; i < 50; i++)
   {
       numeros[i]= mostrarArrayInvertido(numeros, 50);
       printf("%d\n", numeros[i]);
   }
   

}