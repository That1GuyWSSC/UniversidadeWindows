#include <stdio.h>
#include <stdlib.h>

int main(){
 
   int horas, minutos, segundos, total;

   printf("Escreve as horas :");
   scanf("%u", &horas);

   printf("Escreva os minutos:");
   scanf("%u", &minutos);

   printf("Escreva os segundos:");
   scanf("%u", &segundos);

   total = horas * 3600 + minutos * 60 + segundos;

   printf("O tempo em segundos e: %u", total);

   

   getchar();
    return 0;
}