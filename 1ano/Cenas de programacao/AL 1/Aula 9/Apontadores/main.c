#include <stdio.h>

int main(){

    int i =3, j =5 , soma =0;
    int *p=&i, *q= &j;
    p = &i;
    q = &j;
    i += *q;
    (*q)++;
    soma = *p +*q;
    p = &soma;

    printf("i : %d", i);
    printf("j : %d", j);
    printf("soma : %d", soma);
    printf("*p : %d", *p);
    printf("*q : %d", *q);
}

void teste(){

    

}