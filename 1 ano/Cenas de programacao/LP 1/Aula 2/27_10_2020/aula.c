/**
 * @file aula.c
 * @author Duarte Melo
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

/**
 * @brief Função que calcula a soma entre dois valores
 * 
 * @param x Valor de entrada
 * @param y Valor de entrada
 * @return (int) Soma entre os dois valores
 */
int soma(int x, int y)
{
    return (x + y);
}

/**
 * @brief Programa que chama a função soma
 * 
 * @return int 
 */
int main()
{
    int num1, num2;
    printf("Escreva o primeiro valor: ");
    scanf("%d", &num1);

    printf("Escreva o segundo valor: ");
    scanf("%d", &num2);

    printf("O valor da soma e': %d", soma(num1, num2));
}
