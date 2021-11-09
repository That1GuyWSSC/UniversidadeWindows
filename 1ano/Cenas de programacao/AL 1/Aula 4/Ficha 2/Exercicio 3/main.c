#include <stdio.h>

int main(){


   float notaAl;

   printf("Insira a sua nota:");
   scanf("%f", &notaAl);

   if(notaAl > 9.5){

       printf("aluno aprovado");
   }

    getchar();
    return 0;
}