#include <stdlib.h>
#include <stdio.h>

int main(){


   float area, raio, pi;

   pi = 3.14159265358979323846;

   printf("Insira o raio do circulo :");
   scanf("%f", &raio);

   area = (raio * raio) * pi;

   printf("A area do circulo e : %.4f", area);

   getchar();
   getchar();

    return 0;
}