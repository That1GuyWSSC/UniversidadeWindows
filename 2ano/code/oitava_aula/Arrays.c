#include <stdio.h>

void main(){
    //Vetores / Arrays
    int A[10];
    
    for (int i = 0; i < 10; i++)
    {
        A[i]= i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        A[i]= i +10 ;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    

}