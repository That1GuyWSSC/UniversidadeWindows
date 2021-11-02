/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Programação em C relativa ao problema da Questão 18
 * @version 0.1
 * @date 2020-12-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    char escalaConv;

    //TAMANHOARRAY é uma constante definida em funcoes.h, de forma a que se for necessário alterar o tamanho dos arrays, só é alterado num sítio.
    float temps[TAMANHOARRAY];
    float tempsFinais[TAMANHOARRAY];

    float temp;

    int contador = 0;

    //obtenção da escala
    printf("Escreva a escala para a qual pretende converter (k - kelvin, c - celsius): ");
    scanf("%c", &escalaConv);

    //se a escala não estiver dentro dos parametros validos, "insiste" com o utilizador para que introduza uma escala válida
    while (escalaConv != 'c' && escalaConv != 'C' & escalaConv != 'k' & escalaConv != 'K')
    {
        printf("Escreva uma escala valida.\n");
        printf("Escreva a escala para a qual pretende converter (k - kelvin, c - celsius): ");
        scanf(" %c", &escalaConv);
    }

    //pede ao utilizador uma temperatura, caso o utilizador introduza 999, ele termina o programa dado que não foram introduzidos valores
    printf("Escreva uma temperatura (999 para sair): ");
    scanf("%f", &temp);

    if (temp == 999)
    {
        printf("Nao foram introduzidos valores.");
        return(0);
        //termina o programa.
    }

    //enquanto a temperatura não for 999, ele continua a pedir valores, e previne que o utilizador introduza mais valores do que a constante "TAMANHOARRAY"
    while (temp != 999 && contador != TAMANHOARRAY)
    {
        temps[contador] = temp;
        contador++;

        printf("Escreva uma temperatura (999 para sair): ");
        scanf("%f", &temp);
    }

    printf("\n\n\n");
    
    escreveQuadro(escalaConv, temps, tempsFinais, contador);
}
