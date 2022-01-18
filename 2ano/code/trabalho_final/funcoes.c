#include <stdio.h>
#include "structs.h"
#include <string.h>
#include "funcoes.h"

void readfromfileme(ME *array){

    int ordem , nif , tempo , distancia;
    char *codigo;    
    FILE *input_file;
    fopen("utilizacao.txt", "r");

    int c = 0;
    while (!feof(input_file) )
    {
        
        fscanf(input_file,"%d %d %s %d %d", &ordem , &nif , codigo , &tempo, &distancia);
        printf("%d %d %s %d %d", ordem , nif , codigo , tempo , distancia);
    }



    fclose(input_file);


}

int existeme(ME array[], int index, int ordem){
    for (int i = 0; i < index; i++)
    {
         if (array[index].ordem== ordem) return 1;
         else return 0;
    
    }
    

}

int insertme(ME array[],int index, int ordem, int nif, char *codigo, int tempo, int distancia){

    if(existeme(array, index, ordem) ==1) printf("Ja existe;"); ;
    array[index].ordem = ordem;
    array[index].nif = nif;
    array[index].tempo= tempo;
    array[index].distancia= distancia;
    strcpy(array[index].codigo, codigo);

    return 1;

}



/*

int lerAtletas(Atleta c[])
{FILE* fp;
 int cod, resultado, qt;
 float alt, pes;
 char nm[50];
 fp = fopen("atletas.txt","rt");
 
 qt = 0;
 while(!feof(fp))  // feof ->> end of file
 {fscanf(fp,"%d;%f;%f;%s\n",&cod,&alt,&pes,nm);
  resultado = inserirAtleta(c,qt,cod,nm,alt,pes);
  if (resultado==1) qt++;
 }
 fclose(fp);
 return(qt);
}

*/