/**
 * @file main.c
 * @author Duarte Melo e João Diogo
 * @brief Implementação C relativa à questão 9
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int obterInverso(int num);

int main(){
    int original, inverso, maiorPalindromo = 0;
    for (int a = 999; a >= 100; a--){
        for (int b = 999; b >= 100; b--){
            original = a*b;
            inverso = obterInverso(a*b);
            if (inverso == original){
                if (inverso > maiorPalindromo){
                    maiorPalindromo = inverso;
                }
            }
        }
    }
    printf("O maior palindromo e: %d", maiorPalindromo);
}

int obterInverso(int num){
    int aux = num;
    int inverso = 0;

    while (aux != 0){
        inverso = inverso * 10 + aux % 10;
        aux = aux / 10;
    }

    return inverso;
    
}