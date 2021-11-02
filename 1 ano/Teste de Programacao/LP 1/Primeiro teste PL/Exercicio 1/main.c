#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define x 10

int main(){

    int numeros[x];
    int aux;
    int aux2;

    
    for (int i = 0; i < x; i++)
    {
        numeros[i] = 100 + 10 * i;

    }
    
    
    aux = mostrarArrayInvertido(numeros, x);
    aux2 = maiorValorPar(numeros, x);

    printf("O maior valor par e : %d",  maiorValorPar(numeros, x));
    printf("\n a:", valoresSuperiores(numeros, 100));
    printf("\nO array invertido : %d", aux);
}