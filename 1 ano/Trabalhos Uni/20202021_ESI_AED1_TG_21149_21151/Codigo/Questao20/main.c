#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    Clinica *clinicas;
    Utente *utentes;
    Consulta *consultas;
    int numClinicas, numUtentes = 0, numConsultas = 0;

    printf("Escreva o numero de clinicas: ");
    scanf("%d", &numClinicas);
    limparBuffer();
    clinicas = malloc(numClinicas * sizeof(Clinica));
    utentes = malloc(50 * sizeof(Utente));
    consultas = malloc(50 * sizeof(Consulta));

    for (int i = 0; i < numClinicas; i++)
    {

        clinicas[i].numClinica = i + 1;
        printf("Criacao clinica %d\n", clinicas[i].numClinica);

        clinicas[i] = criarClinica(clinicas[i]);
        puts("######################");

    }

    menu(clinicas, numClinicas, utentes, &numUtentes, consultas, &numConsultas);
    
    free(clinicas);
    free(utentes);
    free(consultas);
    freeClinicasFuncionarios(clinicas, numClinicas);
    return 0;
}
