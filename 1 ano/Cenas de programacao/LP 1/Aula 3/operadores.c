/**
 * @file operadores.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>

int main(){
     int x;
     int y;

     x=7;
     y=x*2;

     x=y++; //x =14; Y=15
     x=++y;  // x=16; y=16

     x+=1; //x=17
     x-=y; //x = x -y -> x=1

     printf("%d\n", x>y); //Falso ou zero

     printf("x = %d, y=%d \n", x++, --x); //

}