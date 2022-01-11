#include <stdio.h>
#include "funcoes.h"

void readfromfile(FILE *t, char *str){

    fgets(str, 10000, t);

}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void readfromfile(FILE *t, char *str){

    fgets(str, 10000, t);

} */