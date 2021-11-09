#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int numero, limiteInferior = 0, limiteSuperior = 100;


      srand(time(NULL));
      for (int i = 0; i < 10; i++)
    {
        numero = rand() % (limiteSuperior - limiteInferior) + limiteInferior;

    printf("%d\n", numero);

    }
    
    return 0;

}