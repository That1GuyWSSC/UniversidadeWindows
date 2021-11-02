/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 17
 * @version 0.1
 * @date 2020-11-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int contaCaracter(char texto[], char caracter);
void removeEspacos(char texto[], char textoFinal[]);

int main(){
    char texto[27] = "Algoritmos e uma disciplina";
    char letra = ' ';
    int tamanhoInicial = sizeof(texto) / sizeof(char);
    int tamanhoFinal = tamanhoInicial - (contaCaracter(texto, letra));
    
    char textoFinal[tamanhoFinal];

    removeEspacos(texto, textoFinal);
    for (int i = 0; i < tamanhoFinal; i++){
        printf("%c", textoFinal[i]);
    }

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

/**
 * @brief Remove os espaços de um array de caracteres
 * 
 * @param texto 
 * @param textoFinal 
 */
void removeEspacos(char texto[], char textoFinal[]){
    int contador = 0;
    while (*texto != '\0'){
        if (*texto != ' '){
            *textoFinal = *texto;
            textoFinal++;
            texto++;
        }
        else{
            texto++;
        }
    }
}