#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int numIns, numMais, numMenos;

    printf("Escreva um numero inteiro para ver o seu sucessor e antecessor:");
    scanf("%u", &numIns);

    numMais = numIns + 1;
    numMenos = numIns -1;

    printf("O antecessor do numero e : %u\nO sucessor do numero e : %u", numMenos, numMais);

    getchar();
    getchar();
    return 0;
}