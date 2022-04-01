#include <stdio.h>

#define N 1024

int main(){

 int i=1,j;
 float x=0;
 while (i<N)
 {
     for (j=0; j < N;j+=2)
     {
         x+=2;

     }
    i*=2;
     
 }

printf("%f\n", x/N);
printf("%f", N);
}