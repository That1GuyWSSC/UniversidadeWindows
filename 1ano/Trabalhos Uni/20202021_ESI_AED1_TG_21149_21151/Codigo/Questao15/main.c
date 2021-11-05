/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 15
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int contaCaracter(char texto[], char caracter);

int main(){
    char texto[11] = "Algoritmos";
    char letra = 'o';
    printf("%d", contaCaracter(texto, letra));
}

/**
 * @brief Conta caracteres de um array de caracteres
 * 
 * @param texto 
 * @param caracter 
 * @return int 
 */
int contaCaracter(char texto[], char caracter){
    int contador = 0;
    while (*texto != '\0'){
        if(*texto == caracter){
            contador++;
        }
        texto++;
    }
    return contador;
}
