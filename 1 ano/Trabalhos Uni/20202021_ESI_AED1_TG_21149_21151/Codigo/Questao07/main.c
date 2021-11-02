/**
 * @file main.c
 * @author Duarte Melo e João Diogo 
 * @brief Implementação em C da solução relativa à Questão 7
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main()
{
    char genero, gostaCurso;
    int idade, contadorEntrevistados = 0, contadorM = 0, contadorF = 0, contadorMascMenos20NGosta = 0;

    printf("Escreva o genero (0 para sair): ");
    scanf("%c", &genero);
    while (genero != '0')
    {
        contadorEntrevistados++;
        if (genero == 'M' || genero == 'm')
        {
            contadorM++;
        }
        else if (genero == 'F' || genero == 'f')
        {
            contadorF++;
        }
        printf("Escreva a sua idade: ");
        scanf("%d", &idade);

        printf("Gosta do curso que frequenta? (S/N): ");
        scanf(" %c", &gostaCurso);

        if ((genero == 'M' || genero == 'm') && idade < 20 && (gostaCurso == 'N' || gostaCurso == 'n'))
        {
            contadorMascMenos20NGosta++;
        }
        printf("Escreva o genero (0 para sair): ");
        scanf(" %c", &genero);
    }

    printf("Pessoas entrevistadas: %d\n", contadorEntrevistados);
    if (contadorEntrevistados != 0)
    {
        printf("Percentagem de pessoas do genero masculino: %.1f%%\n", (((float)contadorM / contadorEntrevistados) * 100));
        printf("Percentagem de pessoas do genero feminino: %.1f%%\n", (((float)contadorF / contadorEntrevistados) * 100));
    }

    printf("Pessoas do genero masculino com menos de 20 anos que nao gostam do curso que estao a frequentar: %d\n", contadorMascMenos20NGosta);
}
