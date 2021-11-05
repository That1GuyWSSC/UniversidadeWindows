/**
 * @file ola.c
 * @author Duarte Melo
 * @brief
 * @version 0.1
 * @date 16/10/2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */


#include <stdio.h>

int getValue(){
    int value;
    printf("Escreva o valor: ");
    scanf("%i", &value);
    return value;
}


int soma (int x, int y){
    return x+y;
}

int main(int argc, char const *argv[])
{
    int x, y;
    x = getValue();
    y = getValue();
    int resultado = soma(x, y);
    printf ("%i", resultado);
    return 0;
}


