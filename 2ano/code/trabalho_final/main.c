#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main(){

    char str[10000];
    FILE *fp;
    char *x;

    fp = fopen("utilizacao.txt", "r");
    
    if (fp = NULL)
    {
        printf("Nao abriu o ficheiro");
    }
    
    readfromfile(fp, str);

    printf("%s", *x);
    
    fclose(fp);
}

/*int main(){
char str[100000];
FILE *fp;
char *x;
fp=fopen("utilizador", "r");
  while(fgets(str, 100000, fp)){
       x=strdup(str);
        printf("%d\n", x);
  }
fclose(fp);
}*/

/*
#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>

int main(){

    char str[10000];
    FILE *fp;

    fp = fopen("utilizacao", "r");
    
    if (fp = NULL)
    {
        printf("Nao abriu o ficheiro");
    }

    x = readfromfile(fp, str);

    for (int i = 0; i < 10000; i++)
    {
        printf("%d", *x);
    }
    
    fclose(fp);
}
*/