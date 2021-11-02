/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação em C da solução relativa ao problema do ano bissexto (questão 2)
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main()
{

    //declaração e inicialização de variáveis
    int ano;
    char bissexto = 0;

    //obtenção do ano (input)
    printf("Escreva o ano: ");
    scanf("%d", &ano);

    //verificação das condições para ser bissexto
    if (ano % 4 == 0){
        if (ano % 100 != 0){
            bissexto = 1;
        }
    } 
    if (ano % 400 == 0){
        bissexto = 1;
    }

    //devolver ao utilizador se o ano é ou não bissexto
    if (bissexto == 1){
        printf("O ano %d e' bissexto.", ano);
    } else {
        printf("O ano %d nao e' bissexto.", ano);
    }


    return 0;
}
