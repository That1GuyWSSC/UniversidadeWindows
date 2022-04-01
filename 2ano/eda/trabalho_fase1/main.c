#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "structs.h"




int main(){

    struct maquina* head;
    struct maquina *first = NULL;
    struct maquina* second = NULL;
    struct maquina* third = NULL;

    head = (struct maquina*)malloc(sizeof(struct maquina));
    first = (struct maquina*)malloc(sizeof(struct maquina));
    second =(struct maquina*) malloc(sizeof(struct maquina));
    third =(struct maquina*) malloc(sizeof(struct maquina));

    head = first;
    first->tempo = 1;
    first->next = second;

    second->tempo = 2;
    second->next =third;

    third->tempo=3;
    third->next = NULL;

    struct operacoes* headop;
    struct operacoes* firstop = NULL;
    struct operacoes* secondop= NULL;
    headop = firstop;
    firstop->ops = 1;
    firstop->next = secondop;
    secondop->ops = 4;
    secondop->next= NULL;
    
    printlistamaq(head);
    printlistaop(head);
    insertop(headop, 5);
    printlistaop(head);


    return 0;
}