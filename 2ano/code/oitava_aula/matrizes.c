#include <stdio.h>

void main (){
    //Matrizes / Arrays bidimensionais
    int a[3][4];

    a[1][2] = 10; // 2 linha e 3 coluna

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            a[linha][coluna] =linha * coluna;
        }
    }

    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 4; coluna++)
        {
            printf("%d\t", a[linha][coluna]);
        }
      printf("\n");  
    }
    


}