#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50


void ordernaArrayInteiroAsc(int *numeros, int n);

int pesquisaNumeroArrayInteiros(int numeros[], int n,  int elemento);


int main(){
    int indice, contador = 0, idade;
    int idades[TAMANHO];

    puts("Insira uma idade negativa para sair.");
    printf("Idade :");
    scanf("%d", idade);

    while (idade > 0 && contador < TAMANHO)
    {
        idades[contador] = idade;
        contador++;
    }
    


    indice = pesquisaNumeroArrayInteiros(idades, contador, idade);
    if (indice >= 0)
    {
        printf("Posicao : %d", indice);

    }
    else
    {
        puts("O elemento nao foi encontrado");
    }
    

}


void ordernaArrayInteiroAsc(int *numeros, int n){

    int aux;

    for (int i = 0; i < n -1; i++)
    {
        for (int j = i + 1; j < n; i++)
        {
            if (numeros[i] > numeros[j])
            {
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;

            }
            
        }
        
    }
    

}

int pesquisaNumeroArrayInteiros(int numeros[], int n,  int elemento){
    int i=0;


    while (numeros[i] != elemento && i < n)
    {
        i++;
    }

    if (i >= n)
    {
        i = -1;
    }

    return i;
}