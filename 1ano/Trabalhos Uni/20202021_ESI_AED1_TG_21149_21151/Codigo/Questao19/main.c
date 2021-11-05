/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief 
 * @version 0.1
 * @date 2020-12-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "funcoes.h"

int main()
{
    int numeros[MAX];
    int numerosOrdenadosDesc[MAX];

    int opcao;

    srand(time(NULL));

    int quantidade = gerarNumero(MIN, MAX);

    for (int i = 0; i < quantidade; i++)
    {
        numeros[i] = gerarNumero(0, INT_MAX);
        numerosOrdenadosDesc[i] = numeros[i];
    }

    escreveMenu();

    scanf("%d", &opcao);

    while (opcao != 5)
    {
        if (opcao == 1)
        {
            printf("O maior elemento do conjunto: %d\n", obterMaior(numeros, quantidade));
            printf("O menor elemento do conjunto: %d\n", obterMenor(numeros, quantidade));
        }

        if (opcao == 2)
        {
            printf("Amplitude do conjunto: %d\n", amplitudeArray(obterMenor(numeros, quantidade), obterMaior(numeros, quantidade)));
        }

        if (opcao == 3)
        {
            ordenaArrayInteiroDesc(numerosOrdenadosDesc, quantidade);
            mostraImpares(numerosOrdenadosDesc, quantidade);
        }

        if (opcao == 4)
        {
            mostraArray(numeros, quantidade);
        }

        escreveMenu();

        scanf("%d", &opcao);
    }
}
