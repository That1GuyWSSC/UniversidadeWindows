#include <stdio.h>
#include <string.h>

typedef struct 
{
    int numero;
    char nome[50];
    char curso[50];
    int ano;
} Aluno ;


void main(){

Aluno a1, a2;

Aluno turma[50];

a1.numero = 1234;
strcpy(a1.nome, "Joao");
strcpy(a1.curso, "ESIPL");
a1.ano= 1;

printf("Numero %d \n", a1.numero);
printf("Nome %s \n", a1.nome);
printf("Numero %s \n", a1.curso);
printf("Numero %d \n", a1.ano);

turma[0].numero= 12345;
strcpy(turma[0].nome, "Maria");
strcpy(turma[0].curso, "ESIPL");
turma[0].ano = 2;


turma[1].numero= 123456;
strcpy(turma[1].nome, "Joao");
strcpy(turma[1].curso, "ESIPL");
turma[1].ano = 3;

printf("Numero %d \n", turma[0].numero);
printf("Nome %s \n", turma[0].nome);
printf("Numero %s \n", turma[0].curso);
printf("Numero %d \n", turma[0].ano);

}