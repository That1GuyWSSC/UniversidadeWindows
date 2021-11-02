/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 16
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int contaPalavras(char texto[], char caracter);

int main(){
    char texto[28] = "Algoritmos e uma disciplina";
    char letra = ' ';
    printf("%d", contaPalavras(texto, letra));
}

/**
 * @brief Função que conta o numero de palavras existentes num array de caracteres
 * 
 * @param texto - Array de caracteres
 * @param caracter Caracter que vai ser contado (reaproveitamos a função do exercício anterior), neste caso o espaço
 * @return int Retorna o numero de palavras
 */
int contaPalavras(char texto[], char caracter){
    int contador = 0;
    while (*texto != '\0'){
        if(*texto == caracter){
            contador++;
        }
        texto++;
    }
    return contador + 1; // +1, pois é o numero de espaços + 1
}
