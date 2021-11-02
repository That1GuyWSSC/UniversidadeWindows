
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
}string;

int main (int argc, char const * argv[]){

    float notas [10][2], somas[2];
    string nomes [10], disciplinas[2];

    somas[0] = 0.0f;
    somas[1] = 0.0f;

    strcpy(disciplinas[0].nome, "Portugues");
    strcpy(disciplinas[1].nome, "Matematica");

    for (int i = 0; i < 10; i++)
    {
        printf("Insira nome: ");
        scanf("%s", nomes[i].nome);

        for (int j = 0; j < 2; j++)
        {
            printf("%s ",disciplinas[j]);
            scanf("%d", notas[i][j]); 
            somas[j] = somas[j] + notas[i][j];   
        }    
    }

    printf("%50s | %20s | %20s\n", "NOME", disciplinas[0], disciplinas[1]);
    for (int i = 0; i < 10; i++)
    {
        printf("%50s ", nomes[i].nome);
        for (int j = 0; j < 10; j++)
        {
            printf("%18.2f ", notas[i][j]);
        }
        puts("");
    }
    

    printf("Media de %s: %.2f", disciplinas[0], somas[0] / 10 );
    printf("Media de %s: %.2f", disciplinas[1], somas[1] / 10 );
    

    return 0;
}
