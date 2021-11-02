#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 10

typedef struct{
    char nome[50];
    char morada[100];
    char localidade[20];
    int idade;
    float notaPT, notaMat, notaIng;
}Aluno;

void mostrarFichaAluno (Aluno aluno);
void listaAlunos(Aluno aluno[], int n);

int main (int argc, char const *argv)
{
    Aluno aluno;
    Aluno alunos[TAM];
    int i= 0;
    int indice;

    printf("Insira SAIR para terminar");
    printf("Nome: " );
    fgets(aluno.nome, 50, stdin );
    aluno.nome[strlen(aluno.nome) - 1] = '\0';

    while (strcasecmp(aluno.nome, "sair")!=0  && i < TAM ) // strcasecmp para comparar a string assumindo maiusculas e minusculas
    {
        printf("Morada: " );
        fgets(aluno.morada, 100 ,stdin );
        aluno.morada[strlen(aluno.morada) - 1] = '\0'; // como usamos o fgets para recolher a string toda devemos eliminar o ultimo carater

        printf("Localidade: " );
        fgets(aluno.localidade, 20 ,stdin );
        aluno.localidade[strlen(aluno.localidade) - 1] = '\0';
    
        printf("Idade: " );
        scanf("%d", &aluno.idade);

        printf("Nota PT: " );
        scanf("%f", &aluno.notaPT);
    
        printf("Nota Mat: " );
        scanf("%f", &aluno.notaMat);
    
        printf("Nota Ing: " );
        scanf("%f", &aluno.notaIng);

        alunos[i] = aluno;

        i++;
                
        printf("Insira SAIR para terminar");
        printf("Nome: " );
        fgets(aluno.nome, 50, stdin );
        aluno.nome[strlen(aluno.nome) - 1] = '\0';
    }
    
    indice= alunoMaisVelho(alunos[indice], i);
    mostrarFichaAluno(alunos[indice]);

    listaAlunos(alunos, 1);
    
    return 0;
}

int alunoMaisVelho(Aluno alunos[], int n){
    int indice = 0;

    for (int i = 1; i < n; i++)
    {
        if (alunos[indice].idade < alunos[i].idade)
        {
            indice = i;
        }
        
    }

    return indice;
}


void listaAlunos(Aluno alunos[], int n){
    for (int i = 0; i < n; i++)
    {
        mostrarFichaAluno(alunos[i]);
    }
}



void mostrarFichaAluno (Aluno aluno){
    printf("NOME: %s\n", aluno.nome);
    printf("MORADA: %s\n", aluno.morada);
    printf("LOCALIDADE: %s\n", aluno.localidade);
    printf("IDADE: %d\n", aluno.idade);
    printf("NOTA PT: %f\n", aluno.notaPT);
    printf("NOTA MAT: %f\n", aluno.notaMat);
    printf("NOTA ING: %f\n", aluno.notaIng);
    printf("Media: %f\n", (aluno.notaPT + aluno.notaMat + aluno.notaIng)/3);
}
