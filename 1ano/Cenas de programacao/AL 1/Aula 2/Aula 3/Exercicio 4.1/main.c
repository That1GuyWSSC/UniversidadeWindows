#include <stdlib.h>
#include <stdio.h>

int main(){

    float notaPt, notaEn, notaMa, media;

    
    printf("Insira a nota de portugues :");
    scanf("%f", &notaPt);

    

    printf("Insira a nota de ingles:");
    scanf("%f", &notaEn);

   

    printf("Insira a nota de matematica:");
    scanf("%f", &notaMa);

    media = (notaPt + notaEn + notaMa) / 3;

    printf("A media final : %.2f", media);

    getchar();
    getchar();


    return 0;
}