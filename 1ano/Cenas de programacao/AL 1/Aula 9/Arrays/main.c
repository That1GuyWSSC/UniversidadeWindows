#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
void somaUm(int numeros[], int n);

int main(){

    int numeros[N];

    for (int i = 0; i < 3; i++)
    {
        numeros[i] = 100 + 10 * i;

    }

    somaUm(numeros, 3);


    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", numeros[i]);
    }
    
    
    
}

void somaUm(int numeros[], int n){

    for (int i = 0; i < n; i++)
    {
        numeros[i]++;
    }
    

}