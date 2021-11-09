#include <stdio.h>
#include "Funcoes.h"
 

int main(){

    float base, expoente;
    scanf("%f", &base);
    
    scanf("%f", &expoente);

   

    printf("%f",  potenciaRecursvia(base, expoente));

    return 0;
    
}
