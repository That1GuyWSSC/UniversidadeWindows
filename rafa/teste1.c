#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CONTA
{
    int codigo;
    char* tipo;
    int saldo;
}CONTA;

typedef struct 
{
    int codigo_numerico;
    char* nome;
    char* localidade;
    int saldo_global;  
}NOME;


int search(NOME array[], char *localidade){
        printf("a\n");
        for ( int i = 0; i < 100; i++)
        {
            if(strcmp(localidade, array[i].localidade) == 0)
            {
                 printf("%d %s\n", array[i].codigo_numerico, array[i].nome);
            }
        }

    }
   
int main(){

    NOME teste[1000];
    //teste[0] = malloc(sizeof(teste));
    int x=15;

    strcpy(teste[0].localidade, "Braga");

    search(teste, "Braga");



}