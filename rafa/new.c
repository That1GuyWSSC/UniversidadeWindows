#include <stdio.h>
#include <stdlib.h>

/* Link list node */
typedef struct LInt
{
    int numero;
    struct LInt* proximo;
};

int search(struct LInt* head, int x)
{
    struct LInt* current = head;  // Initialize current
    struct LInt* anterior = NULL;
    while (current != NULL)
    {
        if (current->numero == x)
         {
             printlist(current);
             printlist(head);
            anterior->proximo = NULL;
            current->proximo = head;
            printlist(current);
            head = current;
            printlist(head);

            return 1;
         }   
        anterior = current;  
        current = current->proximo;
    }
    return 0;
}

void printlist(struct LInt* head){
    int x;
struct LInt* current = head;
while(current){
    x=current->numero;
printf("%d - >",x);
current = current->proximo;
}
printf("\n");
}



int main(){

    struct LInt *nome = malloc(sizeof(struct LInt));
    struct LInt *nome2 = malloc(sizeof(struct LInt));
    struct LInt *nome3 = malloc(sizeof(struct LInt));

    nome->numero = 1;
    nome2->numero = 2;
    nome3->numero = 3;
    nome->proximo= nome2;
    nome2->proximo= nome3;
    nome3->proximo= NULL;

    int x = search(nome, 3);

    printf("%d\n",x);
    printlist(nome);
    

    

}