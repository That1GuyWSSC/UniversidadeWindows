/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação em C da solução relativa à Questão 5
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main(){

    //declaração e inicialização de variáveis
    int num, somatorio = 0;

    //obter um número natural (input)
    printf("Escreva o numero: ");
    scanf("%d", &num);


    /**
     * @brief Loop for, começa no número 1, incrementa o número 1 (variável i) até ao valor de num, mostra o valor de i e adiciona o valor de i ao somatório
     * 
     */
    printf("(");
    for (int i = 1; i <= num; i++){
        printf("%d", i);
        somatorio+=i;

        if (i != num){
            printf(" + ");
        }
    }        
    printf(") = ");

    //devolve o valor do somatório
    printf("%d", somatorio);

}