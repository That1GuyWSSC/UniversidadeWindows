#include <stdio.h>


int main(){

    //variaveis
    int num1;
    int num2;
    int num3;

    //atribuicao de valores as variaveis
    num1=10;
    num2=5;
    num3=num1 + num2;

    //printf("num1 + num2 = %d", num3); //escrever a soma dos dois numeros mas sem aparecer os numeros na soma

    printf("%d + %d = %d", num1, num2, num3); //os numeros aparecem na soma?

    getchar(); //pausa o progama a espera de um input



   return 0;
}