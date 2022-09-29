#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM1 50
#define TAM2 100


typedef struct 
{
    char id[TAM1];
    float distancia;
}objeto;


int main(int argc, char const *argv[])
{   /*
    int a=10;
    int *b = &a;
    printf("a=%d\n", a);  // valor de a
    printf("&a=%p\n", &a); // endereco de memoria da variavel a
    printf("b=%d\n", b);
    printf("*b=%d\n", *b); // *b -> valor apontado por b
    *b = 11;
    printf("a=%d\n", a);  // valor de a
    */


    objeto obj1;

    strcpy(obj1.id, "Info");
    obj1.distancia=10.5;
    
    objeto *obj3; // obj3 contem um endereco de memoria para um registo do tipo objeto
    objeto *obj4;
    obj3 = &obj1; // atribuir a variavel obj3 o endereco de memoria do regissto obj1

    printf("%s\n", obj3->id);
    printf("%f\n", obj3->distancia);
    
    obj1.distancia = 20;
    obj3->distancia = 30;
    printf("%f\n", obj1.distancia);

    obj4 = malloc(sizeof(objeto));
    if (obj4 != NULL)
    {
        obj4->distancia = 50;
        strcpy(obj4->id, "teste");
        free(obj4);
    }
    else printf("impossivel");

    printf("Insira o numero de objetos pretendidos\n");
    int qt;
    scanf("%d", &qt);
    obj4 = malloc(sizeof(objeto)*qt);
    strcpy(obj4[0].id,"teste2");
    obj4[0].distancia = 100;
    strcpy(obj4[1].id,"teste2");
    obj4[1].distancia = 100;


/*
    Segunda aula .h e .c nada de importante

    
*/
    free(obj4);
    return 0;
}
