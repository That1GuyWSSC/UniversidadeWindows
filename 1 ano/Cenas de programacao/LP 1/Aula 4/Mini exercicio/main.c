#include <stdio.h>


int main(){

  int soma, sub, div, multi, numUm, numDo;

  printf("Insira o primeiro valor:");
  scanf("%d", &numUm);

  printf("Insira o segundo valor:");
  scanf("%d", &numDo);

  soma = numUm + numDo;
  sub = numUm - numDo;
  div = numUm / numDo;
  multi = numUm / numDo;

  printf("A soma dos dois valores e : %d \n", soma);
  printf("A subtracao dos dois valores e : %d \n", sub);
  printf("A divisao dos dois numeros da : %d \n", div);
  printf("A multiplicao entre os dois valores e : %d \n", multi);


  getchar();


    return 0;
}