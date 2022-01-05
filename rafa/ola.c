#include <stdio.h>

int main(){

    int array[100000];
    int contador = 0;
    int aux= 0, media = 0;
    int i;

    for ( i = 0; i < 10000; i++)
    {
        scanf("%d", &(array[i])); // 5 - 0; 5 -1; 5-2; 0-3;
        if (array[i] == 0)
        {
            break;
        }
          
    }
    
    for (i = 0; i < 10000; i++)
    {
        if (array[i] == 0)
        {
            break;
        }
        
        contador++; //1;2
        aux = aux + array[i]; //5;
    }
    
    
    media = aux / contador;
    printf("%d", media);
}