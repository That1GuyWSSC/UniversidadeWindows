#include <stdio.h>

int main(){

    int numero, contador = 0;

    printf("Insira um numero = 0 ou menor que 0 para sair");
    puts("Numero:");
    scanf("%d", &numero);

    while (numero >0)
    {
        contador++;
        
        printf("Insira um numero = 0 ou menor que 0 para sair");
        puts("Numero:");
        scanf("%d", &numero);

    }

    printf("QUANTIDADESDE DE NUMEROS: %d", contador);
    

    return 0;
}