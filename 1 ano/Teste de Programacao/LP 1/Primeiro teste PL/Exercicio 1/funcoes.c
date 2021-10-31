#include <stdio.h>

int maiorValorPar(int array[], int n){
    int aux;
    for (int i = 0; i < n; i++)
    {
        array[i]= aux;
        if (aux % 2 == 0)
        {
            return aux;
        }
       else
       {
           return 0;
           break;
       }
       
    }
    

}


int verificaPar(int n){
    if (n % 2 == 0)
    {
        return 1;
    }
    return 0;
}


int valoresSuperiores(int array[], int n){

    for (int i = 0; i < n; i++)
    {
        if (array[n] < 141)
        {
            printf("Nao ha valores a cima.");
        }
        
    }
    

}

int mostrarArrayInvertido(int array[], int n){

    for (int i = n -1 ; i >=0; i--)
    {
        printf("%d\n", array[i]);
    }
    

}