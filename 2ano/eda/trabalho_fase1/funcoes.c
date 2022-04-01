#include <stdio.h>
#include <stdlib.h>
#include "structs.h"



void printlistamaq(struct maquina* insert){

    while (insert != NULL) {
        printf("%d \n", insert->tempo);
        insert = insert->next;
    }

}


void insertop(struct operacoes** head, int numero){

    struct operacoes* nova = (struct operacoes*)malloc(sizeof(struct operacoes));

    nova->ops = numero;
    nova->next = *((head));
    (*head) = nova;

}

void printlistaop(struct operacoes* head){

    while (head != NULL) {
        printf("%d \n  ", head->ops);
        head = head->next;
    }

}