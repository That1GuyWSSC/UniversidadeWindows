#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PILA 10000

typedef struct dados{
    int numero;
    int NIF;
    char *codigo;
    int tempo;
    int distancia;
}*DA;

void colocaarray(char *info, DA array[], int i){
    char* x;
    int numero1 , NIF1, tempo1, distancia1;
    char *codigo1;
    x = strsep(&info, " ");
    numero1 = atoi(strdup(x));
    x = strsep(&info, " ");
    NIF1 = atoi(strdup(x));
    x = strsep(&info, " ");
    codigo1 = strdup(x);
    x = strsep(&info, " ");
    tempo1 =atoi(strdup(x));
    x = strsep(&info, " ");
    distancia1 = atoi(strdup(x));

    array[i]->codigo=codigo1;
    array[i]->distancia=distancia1;
    array[i]->NIF =NIF1;
    array[i]->numero=numero1;
    array[i]->tempo=tempo1;
}

int morre(DA arr[]){
    char *x;
    printf("a\n");
    int i = 0;
    FILE *info = fopen("entrada/ficheiro.txt","r");
    printf("a\n");
    char buffer[PILA];
    printf("a\n");
    while(fgets(buffer, PILA, info)){
        x = strdup(buffer);
        printf("b\n");
        colocaarray(x, arr, i);
        i++;
    }
    printf("a\n");
    fclose(info);
    return i;
}


void printarray(DA a[], int i){
    printf("Numero: %d, NIF: %d, CÃ³digo: %s, tempo(min): %d, distancia: %d\n", a[i]->numero, a[i]->NIF, a[i]->codigo, a[i]->tempo, a[i]->distancia);
}

int main(){
    
    DA array[PILA];
    printf("1\n");
    for (int p= 0; p < PILA; p++)
    {
        array[p]=malloc(4*(sizeof (int)+1000));
        array[p]->codigo=NULL;
        array[p]->distancia=-1;
        array[p]->NIF =-1;
        array[p]->numero=-1;
        array[p]->tempo=-1;
    }

    printf("2\n");
    int i = morre(array);
    printf("3\n");
    for(int j=0;j<i;j++){
       printarray(array, j);
    }

}