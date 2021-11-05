#include <stdio.h>


int fatorialIterativa(int numero){
    int resultado = 1;

    for (int  i = 2; i <= numero; i++)
    {
        resultado = resultado * i;
    }
    

    return resultado;
}

int fatorialRecursiva(int numero){

    if (numero == 0)
    {
        return 1;
    }

    return numero * fatorialRecursiva(numero -1);

   
    
}


float potenciaRecursvia(float base, float expoente){

    if(expoente == 0){

        return 1;
    }

    return base * potenciaRecursvia( base, expoente -1);

}