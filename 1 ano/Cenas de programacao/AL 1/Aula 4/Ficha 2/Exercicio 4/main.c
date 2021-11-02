#include <stdio.h>

int main(){
 
  float numU, numD, resultado; // variaveis declardas todas em numero real

  printf("Insira o primeiro numero:");
  scanf("%f", &numU);   // pedi o numero 1

  printf("Insira o segundo numero:");
  scanf("%f", &numD);  // pedi o numero 2
 

 if (numD == 0){

    printf("Nao se pode fazer a divisao");
    return 0;    // se o numero for 0 escrever isto
 }
  
  resultado = (numU / numD); // operacao finfal 

  printf("o resultado e :%.2f", resultado); 
    


    return 0;
}