#include <stdlib.h>
#include <stdio.h>


int inverteNumero(int numero);

int main () {

    int numero, numeroInvertido = 0 , digito, limInf = 0 , limSup =100;


    scanf("%d", &numero);
    
    printf("Numero INVERTIDO : %d", inverteNumero(numero));


    numeroInvertido= inverteNumero(numero);

    return 0;

}

int inverteNumero (int numero){


    int numeroInvertido = 0, digito;
    while (numero > 0)
    {
        digito =  numero % 10;
        numeroInvertido = numeroInvertido *10 +digito;
        numero = numero /10;
    }

    return numeroInvertido; 
    
}


    
  

