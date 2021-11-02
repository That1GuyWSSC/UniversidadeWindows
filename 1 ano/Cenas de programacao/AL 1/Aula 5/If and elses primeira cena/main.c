#include <stdio.h>

int main (){

 int numero;

 printf("Numero :");
 scanf("%d", &numero);

 if (numero == 0){
     printf("Neutro");
 }
 else if (numero > 0){

     printf("Positivo");

 }
 else{
     printf("Negativo");
 }

}