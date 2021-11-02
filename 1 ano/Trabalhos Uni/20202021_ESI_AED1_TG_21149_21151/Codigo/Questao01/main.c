/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação em C da solução relativa à Questão 01
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main(){

    //declaração e inicialização de variáveis
    int somatorioMaiorQue4 = 0, somatorioMedia = 0, quantidade;
    float media;

    //obtenção dos valores (input)

    //paquete 1

    printf("Escreva a quantidade de refeicoes entregues pelo paquete 1: ");
    scanf("%d", &quantidade);

    if (quantidade > 4){
        somatorioMaiorQue4 += quantidade;
    }
    somatorioMedia += quantidade;

    //paquete 2

    printf("Escreva a quantidade de refeicoes entregues pelo paquete 2: ");
    scanf("%d", &quantidade);

    if (quantidade > 4){
        somatorioMaiorQue4 += quantidade;
    }
    somatorioMedia += quantidade;

    //paquete 3

    printf("Escreva a quantidade de refeicoes entregues pelo paquete 3: ");
    scanf("%d", &quantidade);

    if (quantidade > 4){
        somatorioMaiorQue4 += quantidade;
    }
    somatorioMedia += quantidade;

    //paquete 4

    printf("Escreva a quantidade de refeicoes entregues pelo paquete 4: ");
    scanf("%d", &quantidade);

    if (quantidade > 4){
        somatorioMaiorQue4 += quantidade;
    }
    somatorioMedia += quantidade;

    //paquete 5

    printf("Escreva a quantidade de refeicoes entregues pelo paquete 5: ");
    scanf("%d", &quantidade);

    if (quantidade > 4){
        somatorioMaiorQue4 += quantidade;
    }
    somatorioMedia += quantidade;

    //calculos finais

    media = somatorioMedia / 5.0;

    //amostragem dos valores (output)

    printf("A media de entregas dos paquetes todos e: %.2f\n", media);

    printf("O somatorio dos paquetes que fizeram mais de 4 entregas e: %d", somatorioMaiorQue4);

    getchar();
    getchar();
    
    
 
}