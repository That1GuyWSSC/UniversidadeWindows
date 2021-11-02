#include <stdlib.h>
#include <stdio.h>

int verificaPrimo(int numero);

int main(){

    int numero;

    printf("Insira um numero : ");
    scanf("%d", &numero);


    if (verificaPrimo(numero) == 0){
        printf("Numero %d nao e primo.", numero);
    }
    else {
        printf("Numero %d e primo.", numero);
    }
}
   



int verificaPrimo(int numero){

    if (numero == 0 || numero == 1)
    {
        return 0;
    

    int divisor = numero - 1;
    int resto;
    int numero;

  
    
    
}
/**
 * @file main.c
 * 
 * @author LupiPTTV
 * @brief 
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
 #include <stdio.h>

/**int verificaPrimo (int numero);

int main(){
    int numero;
    printf("Escreva o numero: ");
    scanf("%d", &numero);
    if (verificaPrimo(numero) == 0){
        printf("Numero %d nao e primo.", numero);
    }
    else {
        printf("Numero %d e primo.", numero);
    }
}

int verificaPrimo (int numero){
    // 1 e 0 sao nao primos
    if (numero == 0 || numero == 1){
        return 0;
    }
    // nao é primo se for divisivel por algum numero entre 2 e num-1, e quebra assim que for divisivel por algum numero
    for (int i = 2; i < numero; i++){
        if (numero % i == 0){
            return 0;
        }
    }
    //caso não tenha retornado nada anteriormente, o numero é primo
    return 1;
}

 */