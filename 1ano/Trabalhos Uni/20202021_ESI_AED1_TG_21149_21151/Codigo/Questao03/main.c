/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação em C da solução relativa ao problema da média de 4 disciplinas (questão 3)
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main(){

    //declaração e inicialização de variáveis
    float media, somatorio = 0, nota;

    //obtenção dos valores das notas (input) e adição dos mesmos ao somatório
    printf("Escreva a nota de matematica: ");
    scanf("%f", &nota);
    somatorio += nota;

    printf("Escreva a nota de portugues: ");
    scanf("%f", &nota);
    somatorio += nota;

    printf("Escreva a nota de ingles: ");
    scanf("%f", &nota);
    somatorio += nota;

    printf("Escreva a nota de geografia: ");
    scanf("%f", &nota);
    somatorio += nota;

    //calculo da media
    media = somatorio / 4;


    //resultado da média, e consoante a condição imposta pelo enunciado, devolve se o aluno está aprovado ou reprovado
    if (media >= 9.5){
        printf("Aprovado com media de %.2f valores.", media);
    } else {
        printf("Reprovado com media de %.2f valores.", media);
    }

}