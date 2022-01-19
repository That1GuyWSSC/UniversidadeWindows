#include <stdio.h>
#include "structs.h"
#include <string.h>
#include "funcoes.h"
#include <stdlib.h>


int insertme(ME array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia){

    if(existeme(array, index, ordem) == 1) 
    {
        printf("Ja existe;");
        return 0;
    }

    array[index].ordem = ordem;
    array[index].nif = nif;
    array[index].tempo= tempo;
    array[index].distancia= distancia;
    strcpy(array[index].codigo, codigo);

    return 1;

}    

void readfromfileinsertme(ME array[]){

    FILE *input_file;
    int ordem , nif , tempo , distancia;
    int c = 0;
    char *codigo;
    input_file = fopen("utilizacao.txt", "r");

    if (input_file == NULL)
    {
        printf("Ocorreu um erro no a abrir o ficheiro");
    }
    else{
        while (!feof(input_file) )
        {
            printf("%s", *input_file);
            fscanf(input_file,"%d %d %s %d %d", &ordem , &nif , codigo , &tempo, &distancia);
            printf("%s", *input_file);
            printf("%d %d %s %d %d", ordem , nif , codigo , tempo , distancia);
                    printf("a\n");

            insertme(array, c ,ordem, nif, codigo, tempo, distancia);
        printf("a\n");
            printarray(array, c);
            c++;
        }
    
    }
    fclose(input_file);
    
}

int existeme(ME array[], int index, int ordem){
    for (int i = 0; i < index; i++)
    {
         if (array[index].ordem == ordem) return 1;
         else return 0;
    
    }
    
}


void printarray(ME array[], int i)
{
    printf("%d %d %d %d %s \n", array[i].ordem, array[i].nif, array[i].tempo, array[i].distancia, array[i].codigo);
}