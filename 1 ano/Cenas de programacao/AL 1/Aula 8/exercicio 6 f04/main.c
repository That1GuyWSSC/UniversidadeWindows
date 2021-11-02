#include <stdio.h>
#include <stdlib.h>

int verificaPar(int numero);

int main(){

    int numero;

    printf("Insira um numero: ");
    scanf("%d", &numero);

  verificaPar(numero);

  if (verificaPar(numero))
  {
      printf("o numero e par");
  }
  else
  {
       printf("o numero e impar");
  }
  

  

}

int verificaPar(int numero){

    if (numero % 2 == 0){
    
        return 1;
    }

     else 
        {
            return 0;
            
        }
    

}