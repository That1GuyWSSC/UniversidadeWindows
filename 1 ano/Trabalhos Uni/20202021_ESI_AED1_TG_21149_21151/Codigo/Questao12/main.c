/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief  Código em C relativo à questão 12
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int verificaPalindromo (int num);

int main(){
    int num;

    printf("Escreva o numero: ");
    scanf("%d", &num);
    
    if (verificaPalindromo(num) == 1)
        printf("O numero %d e' palindromo", num);
    else
        printf("O numero %d nao e' palindromo", num);
    
}

/**
 * @brief Funcao que verifica se um numero é palindromo, retorna 1 caso seja palindromo, e retorna 0 caso não seja (substituição de true e false)
 * 
 * @param num Número para verificar
 * @return int: 1 - é palindromo; 2 - não é palindromo
 */
int verificaPalindromo (int num){
    int aux = num;
    int inverso = 0;

    while (aux != 0){
        inverso = inverso * 10 + aux % 10;
        aux = aux / 10;
    }
    if (inverso == num){
        return 1;
    }
    return 0;
}