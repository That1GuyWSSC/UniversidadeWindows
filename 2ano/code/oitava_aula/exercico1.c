#include <stdio.h>
#include <string.h>

void main() {

    int i, quantidade =0;
    float notas[80], soma=0, media;

    for ( i = 0; i < 80; i++)
    {
        printf("Nota do aluno %d", i+1);
        scanf("%f", &notas[i]);
    }

    for ( i = 0; i < 80; i++)
    {
        soma += notas[i];
    }
    media =soma/(float) 80;  

    for ( i = 0; i < 80; i++)
    {
        if (notas[i] > media)
        {
            quantidade++;
        }
        
    }
    printf("Media %.2f Quantidade %d", media, quantidade);
}