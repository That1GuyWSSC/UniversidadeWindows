#include <stdio.h>
#include <stdlib.h>  //rand
#include <time.h>    //seed
#include <assert.h>

#define N 10

typedef struct _cell{
    //dados
    int value;
    //Next
    struct _cell* next;

}Cell;

Cell* new_cell(int v){
    Cell* cell =(Cell*) malloc(sizeof(Cell));
    assert(cell);
    cell->value =v;
    cell->next = NULL;
    return cell;

}

Cell* head_insert(Cell* list, Cell* new){

    new->next = list;
    return new;

}

Cell* tail_insert(Cell* list, Cell*new){

    if (list)
    {
        Cell *ptr = list;
        while (ptr->next){ptr->next=new;}

        ptr=ptr->next;
        
    }
    else
    {
         list = new;
    }
    
    return list;

}

void show_list(Cell* list){

   for (Cell *ptr = list; ptr != NULL; ptr=ptr->next)
   {
        printf("%d\n", ptr->value);
        ptr= ptr->next;
    }
}

int main(){

    Cell *list = NULL;

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        int v = rand() % 1000;
        list = head_insert(list,new_cell(v));
        printf("%d\n", v);
    }

    show_list(list);

    return 0;
}