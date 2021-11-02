#include <stdio.h>

int main(){

    int idade; 

    printf("Escreva a sua idade :");
    scanf("%d", &idade);

    if (idade > 30){

        idade = idade + 10;
    }
    

    printf("idade final: %d", idade);

    return 0;
}