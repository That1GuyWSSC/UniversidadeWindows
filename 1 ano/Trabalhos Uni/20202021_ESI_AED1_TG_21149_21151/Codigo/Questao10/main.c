/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 10
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int somatorioNum(int num);

int main(){
    int num;

    printf("Escreva o numero: ");
    scanf("%d", &num);

    printf("Somatorio: %d", somatorioNum(num));
}

/**
 * @brief Faz o somatório de 1 + 2 + 3 + ... + num
 * 
 * @param num Representa o valor de n (1 + 2 + ... + n)
 * @return int Retorna o valor do somatório
 */
int somatorioNum(int num){
    int somatorio = 0;
    for (int i = 1; i <= num; i++){
        somatorio+=i;
    }
    return somatorio;
}