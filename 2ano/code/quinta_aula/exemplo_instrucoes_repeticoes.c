#include <stdio.h>

void main(){

    int soma = 0;
    int minimo , maximo;
    printf("Introduza o minimo e o maximo respetivamente : \n");
    scanf("%d %d", &minimo, &maximo);
    
    //Somatario de valores de 0 a 100
    while (minimo<=maximo)
    {
        soma = soma + minimo;
        minimo = minimo + 1;
    }
    printf("soma : %d \n", soma);
  

}