#include <stdio.h>

void main(){

    int idade;
    printf("Insira a sua idade\n");
    scanf("%d", &idade);
    if (idade >= 18)
    {
        printf("Pode tirar a carta");
    }
    else
        {
            printf("Nao pode tirar tem que esperar %d anos.", 18 - idade);
        }

}

