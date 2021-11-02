#include <stdio.h>
#define N 10

int main(){

    int idade, soma = 0;
    float media; 

    for (int i = 0; i < N; i++);
    {
        printf("Idade");
        scanf("%d", &idade);

        soma += idade;


    }
    

    media = (float) soma / N;

    printf("Soma : %d", soma);
    printf("Media : %.2f", media);



    return 0;
}