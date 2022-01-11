#include <stdio.h>
#include "funcoes.h"
#include "structs.h"
#include <string.h>

void readfromfileme(ME *array){

    int ordem , nif , tempo , distancia;
    char *codigo;    
    FILE *input_file;
    fopen("utilizacao.txt", "r");

    int c = 0;
    while (!feof(input_file) )
    {
        
        fscanf(input_file,"%d %d %s %d %d", &ordem , &nif , &codigo , &tempo, &distancia);
        printf("%d %d %s %d %d", ordem , nif , codigo , tempo , distancia);
    }



    fclose(input_file);


}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void readfromfile(FILE *t, char *str){

    fgets(str, 10000, t);

} */