#include <stdio.h>
#include <stdlib.h>

int main(){

  float  precoInicial;
  float  precoFinal;
  const float taxaSaldo = 0.3F;


  printf("Insira o preco:");
  scanf("%f", &precoInicial);
  fflush(stdin);

 precoFinal = precoInicial - precoInicial * taxaSaldo;

 printf("Preco final : %.2f", precoFinal);

 getchar();
 return 0;
}