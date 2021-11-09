/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Código em C relativo à questão 14
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int verificaPrimo(int numero);
int verificaPrimoLimites(int limiteInferior, int limiteSuperior);

int main(){
    int limiteInferior, limiteSuperior;

    printf("Escreva o limite inferior: ");
    scanf("%d", &limiteInferior);

    printf("Escreva o limite superior: ");
    scanf("%d", &limiteSuperior);

    printf("%d", verificaPrimoLimites(limiteInferior, limiteSuperior));

}


/**
 * @brief Verifica quantos numeros primos existem num determinado intervalo
 * 
 * @param limiteInferior Limite inferior do intervalo
 * @param limiteSuperior Limite superior do intervalo
 * @return int - Retorna o contador de numeros primos
 */
int verificaPrimoLimites(int limiteInferior, int limiteSuperior){
    int contador = 0;
    for (int i = limiteInferior; i <= limiteSuperior; i++){
        if(verificaPrimo(i) == 1){ 
            contador++;
        } 
    }
    return contador;
}

/**
 * @brief Verifica se um determinado número é primo
 * 
 * @param numero Recebe o número para o qual a verificação será feita
 * @return int Retorna 1 se for primo, 0 se não for primo
 */
int verificaPrimo(int numero){
    // 1 e 0 sao nao primos
    if (numero == 0 || numero == 1)
    {
        return 0;
    }
    // nao é primo se for divisivel por algum numero entre 2 e num-1, e quebra assim que for divisivel por algum numero
    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }
    //caso não tenha retornado nada anteriormente, o numero é primo
    return 1;
}