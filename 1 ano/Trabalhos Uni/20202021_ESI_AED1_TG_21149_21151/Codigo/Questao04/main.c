/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação em C da solução relativa à Questão 4
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    //declaração de variáveis
    float comprimento;
    char genero;
    int desconto;

    //obtenção dos valores do comprimento e genero (input)
    printf("Escreva o comprimento: ");
    scanf("%f", &comprimento);


    printf("Escreva o genero (m/f): ");
    scanf(" %c", &genero);

    //verificação, consoante os intervalos impostos pelo enunciado e género, qual o desconto que irá ser devolvido
    if (comprimento >= 6 && comprimento < 10){
        if (genero == 'F' || genero == 'f'){
            desconto = 10;
        }
    }

    if (comprimento >= 10 && comprimento < 15){
        if (genero == 'M' || genero == 'm'){
            desconto = 9;
        }
    }

    if (comprimento >= 15 && comprimento < 18){
        if (genero == 'F' || genero == 'f'){
            desconto = 8;
        }
    }

    if (comprimento >= 18 && comprimento < 25){
        
        desconto = 7;
        
    }

    else  {
        desconto = 5;
    }

    //devolver o desconto    
    printf("O valor do desconto e %i%%;", desconto);

    getchar();
    getchar();
    

    return 0;
}
