/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 11
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int somatorioNum(int num, int *somatorio);

int main(){
    int num;
    int somatorio = 0;

    printf("Escreva o numero: ");
    scanf("%d", &num);

    printf("Somatorio: %d", somatorioNum(num, &somatorio));
}



/**
 * @brief Faz o somatório de 1 + 2 + 3 + ... + num de forma recursiva
 * 
 * @param num 
 * @param somatorio 
 * @return int 
 */
int somatorioNum(int num, int *somatorio){
    if (num == 0){
        return *somatorio;
    }
    *somatorio += num;
    
    return somatorioNum(num-1, somatorio);
}