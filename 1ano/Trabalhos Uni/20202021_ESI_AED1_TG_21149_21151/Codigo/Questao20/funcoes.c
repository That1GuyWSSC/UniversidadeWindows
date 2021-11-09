#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

/**
 * @brief Define dados para uma clinica, recebe-os do utilizador
 * 
 * @param clinica 
 * @return Clinica Devolve a clinica à qual os dados foram atribuidos ao main
 */
Clinica criarClinica(Clinica clinica)
{
    int numFuncionarios;
    printf("Numero de funcionarios clinica %d: ", clinica.numClinica);
    scanf("%d", &numFuncionarios);
    limparBuffer();
    clinica.numFuncionarios = numFuncionarios;
    clinica.funcionarios = malloc(sizeof(Funcionario) * clinica.numFuncionarios);

    for (int i = 0; i < clinica.numFuncionarios; i++)
    {

        clinica.funcionarios[i].numFuncionario = i + 1;
        printf("Criacao do funcionario %d:\n", clinica.funcionarios[i].numFuncionario);
        printf("Nome: ");
        fgets(clinica.funcionarios[i].nome, sizeof(clinica.funcionarios[i].nome), stdin);

        int len = strlen(clinica.funcionarios[i].nome);
        if (clinica.funcionarios[i].nome[len - 1] == '\n')
        {
            clinica.funcionarios[i].nome[len - 1] = '\0';
        }

        printf("Equipa (M - medica; E - enfermagem; A - auxiliar): ");
        scanf(" %c", &clinica.funcionarios[i].equipa);
        limparBuffer();
        while (clinica.funcionarios[i].equipa != 'm' && clinica.funcionarios[i].equipa != 'M' && clinica.funcionarios[i].equipa != 'e' && clinica.funcionarios[i].equipa != 'E' && clinica.funcionarios[i].equipa != 'a' && clinica.funcionarios[i].equipa != 'A')
        {
            printf("Introduza uma equipa valida!\n");
            printf("Equipa (M - medica; E - enfermagem; A - auxiliar): ");
            scanf(" %c", &clinica.funcionarios[i].equipa);
            limparBuffer();
        }

        printf("Genero (M/F): ");
        scanf(" %c", &clinica.funcionarios[i].genero);
        limparBuffer();
        while (clinica.funcionarios[i].genero != 'm' && clinica.funcionarios[i].genero != 'M' && clinica.funcionarios[i].genero != 'f' && clinica.funcionarios[i].genero != 'F')
        {
            printf("Introduza um genero valido!\n");
            printf("Genero (M/F): ");
            scanf(" %c", &clinica.funcionarios[i].genero);
            limparBuffer();
        }

        printf("Data nascimento (dia-mes-ano): ");
        scanf("%d-%d-%d", &clinica.funcionarios[i].dataNascimento.dia, &clinica.funcionarios[i].dataNascimento.mes, &clinica.funcionarios[i].dataNascimento.ano);
        limparBuffer();

        printf("Vencimento: ");
        scanf("%f", &clinica.funcionarios[i].vencimento);
        limparBuffer();

        clinica.funcionarios[i].ativo = true;
    }
    return clinica;
}

/**
 * @brief Lista um funcionário
 * 
 * @param funcionario Recebe o funcionário que vai listar
 */
void listarFuncionario(Funcionario funcionario)
{
    printf("Funcionario %d:\n", funcionario.numFuncionario);
    printf("Nome: %s\n", funcionario.nome);
    printf("Equipa: %c\n", funcionario.equipa);
    printf("Genero: %c\n", funcionario.genero);
    printf("Data nascimento: %d-%d-%d\n", funcionario.dataNascimento.dia, funcionario.dataNascimento.mes, funcionario.dataNascimento.ano);
    printf("Vencimento: %.2f\n", funcionario.vencimento);
    printf("Ativo: %d\n", funcionario.ativo);
}

/**
 * @brief Lista todos os funcionários de uma clínica
 * 
 * @param clinica 
 */
void listarFuncionariosClinica(Clinica clinica)
{
    printf("Funcionarios clinica %d\n", clinica.numClinica);
    for (int i = 0; i < clinica.numFuncionarios; i++)
    {
        listarFuncionario(clinica.funcionarios[i]);
    }
}

float somatorioVencimentosClinica(Clinica clinica)
{
    int somatorio = 0;
    for (int i = 0; i < clinica.numFuncionarios; i++)
    {
        somatorio += clinica.funcionarios[i].vencimento;
    }
    return somatorio;
}

/**
 * @brief Lista apenas os funcionários ativos de uma clínica
 * 
 * @param clinica 
 */
void listarFuncionariosAtivosClinica(Clinica clinica)
{
    printf("Funcionarios clinica %d\n", clinica.numClinica);
    for (int i = 0; i < clinica.numFuncionarios; i++)
    {
        if (clinica.funcionarios[i].ativo == true)
        {
            listarFuncionario(clinica.funcionarios[i]);
        }
    }
}

/**
 * @brief Limpar o buffer do teclado (para evitar problemas nos scanf's)
 * 
 */
void limparBuffer()
{
    while (getchar() != '\n')
    {
    }
}

/**
 * @brief Free na memória dos arrays de funcionários dentro das structs Clinica dentro do array de clínicas
 * 
 * @param clinicas 
 * @param numClinicas 
 */
void freeClinicasFuncionarios(Clinica *clinicas, int numClinicas)
{
    for (int i = 0; i < numClinicas; i++)
    {
        free(clinicas[i].funcionarios);
    }
}

/**
 * @brief Devolve o indice (no array de clinicas) de uma clinica a partir do numClinica
 * 
 * @param clinicas 
 * @param numClinicas 
 * @param numClinica 
 * @return int 
 */
int obterIndiceClinicaPorNumero(Clinica *clinicas, int numClinicas, int numClinica)
{
    for (int i = 0; i < numClinicas; i++)
    {
        if (clinicas[i].numClinica == numClinica)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Inativa um funcionário a partir do número do mesmo
 * 
 * @param clinica 
 * @param numFuncionario 
 * @return Clinica 
 */
Clinica inativarFuncionarioPorNumero(Clinica clinica, int numFuncionario)
{
    for (int i = 0; i < clinica.numFuncionarios; i++)
    {
        if (clinica.funcionarios[i].numFuncionario == numFuncionario)
        {
            clinica.funcionarios[i].ativo = false;
            return clinica;
        }
    }
}

/**
 * @brief Devolve o indice da clinica a partir do numero da mesma
 * 
 * @param clinicas 
 * @param numClinicas 
 * @param numClinica 
 * @return int 
 */
int indiceClinicaPorNumero(Clinica *clinicas, int numClinicas, int numClinica)
{
    for (int i = 0; i < numClinicas; i++)
    {
        if (clinicas[i].numClinica == numClinica)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Cria um utente, verifica se o numero SNS é  unico
 * 
 * @param utentes 
 * @param numUtentes 
 * @param indiceNovoUtente 
 */
void criarUtente(Utente *utentes, int numUtentes, int indiceNovoUtente)
{
    utentes[indiceNovoUtente].numUtente = indiceNovoUtente + 1;
    printf("Nome: ");
    fgets(utentes[indiceNovoUtente].nome, sizeof(utentes[indiceNovoUtente].nome), stdin);

    int len = strlen(utentes[indiceNovoUtente].nome);
    if (utentes[indiceNovoUtente].nome[len - 1] == '\n')
    {
        utentes[indiceNovoUtente].nome[len - 1] = '\0';
    }

    printf("Numero SNS: ");
    scanf("%d", &utentes[indiceNovoUtente].numeroSNS);
    limparBuffer();

    int contador = 0;

    while (contador != 1)
    {
        contador = 0;
        for (int i = 0; i < numUtentes; i++)
        {
            if (utentes[indiceNovoUtente].numeroSNS == utentes[i].numeroSNS)
            {
                contador++;
            }
        }
        if (contador != 1)
        {
            printf("Numero SNS ja existe.\n");
            printf("Numero SNS: ");
            scanf("%d", &utentes[indiceNovoUtente].numeroSNS);
            limparBuffer();
        }
    }

    utentes[indiceNovoUtente].ativo = true;
}

/**
 * @brief Inativa um utente a partir do seu número de SNS
 * 
 * @param utentes 
 * @param numUtentes 
 * @param numSNS 
 */
void inativarUtentePeloNumeroSNS(Utente *utentes, int numUtentes, int numSNS)
{
    for (int i = 0; i < numUtentes; i++)
    {
        if (utentes[i].numeroSNS == numSNS)
        {
            utentes[i].ativo = false;
            printf("Utente desativado com sucesso.\n");
            return;
        }
    }
    printf("Utente nao encontrado.\n");
}

/**
 * @brief Listar um utente
 * 
 * @param utente 
 */
void listarUtente(Utente utente)
{
    printf("Numero: %d\n", utente.numUtente);
    printf("Nome: %s\n", utente.nome);
    printf("Numero SNS: %d\n", utente.numeroSNS);
    printf("Ativo: %d\n", utente.ativo);
}

/**
 * @brief Listar todos os utentes
 * 
 * @param utentes 
 * @param numUtentes 
 */
void listarUtentes(Utente *utentes, int numUtentes)
{
    for (int i = 0; i < numUtentes; i++)
    {
        listarUtente(utentes[i]);
        puts("######################");
    }
}

/**
 * @brief Listar apenas utentes ativos
 * 
 * @param utentes 
 * @param numUtentes 
 */
void listarUtentesAtivos(Utente *utentes, int numUtentes)
{
    for (int i = 0; i < numUtentes; i++)
    {
        if (utentes[i].ativo == true)
        {
            listarUtente(utentes[i]);
            puts("######################");
        }
    }
}

/**
 * @brief Devolve o nímero do utente a partir do número do SNS
 * 
 * @param utentes 
 * @param numUtentes 
 * @param numSNS 
 * @return int Número do utente
 */
int numUtentePeloNumeroSNS(Utente *utentes, int numUtentes, int numSNS)
{
    for (int i = 0; i < numUtentes; i++)
    {
        if (utentes[i].numeroSNS == numSNS)
        {
            return utentes[i].numUtente;
        }
    }
    return -1;
}

/**
 * @brief Lista uma consulta
 * 
 * @param consulta 
 * @param utente 
 * @param funcionario 
 */
void listarConsulta(Consulta consulta, Utente utente, Funcionario funcionario)
{
    printf("Num consulta: %d\n", consulta.numConsulta);
    printf("Data: %d-%d-%d\n", consulta.data.dia, consulta.data.mes, consulta.data.ano);
    printf("Hora: %d:%d\n", consulta.hora.horas, consulta.hora.minutos);
    printf("Utente: \n");

    listarUtente(utente);

    printf("Num clinica: %d\n", consulta.numClinica);
    printf("Funcionario: \n");

    listarFuncionario(funcionario);

    printf("Descricao: %s\n", consulta.descricao);
    printf("Ativa: %d\n", consulta.ativo);
}

/**
 * @brief Lista todas as consultas
 * 
 * @param consultas 
 * @param numConsultas 
 * @param utentes 
 * @param clinicas 
 */
void listarConsultas(Consulta *consultas, int numConsultas, Utente *utentes, Clinica *clinicas)
{
    for (int i = 0; i < numConsultas; i++)
    {
        listarConsulta(consultas[i], utentes[consultas[i].numUtente - 1], clinicas[consultas[i].numClinica - 1].funcionarios[consultas[i].numMedico - 1]);
    }
}

/**
 * @brief Lista as consultas ativas, apenas
 * 
 * @param consultas 
 * @param numConsultas 
 * @param utentes 
 * @param clinicas 
 */
void listarConsultasAtivas(Consulta *consultas, int numConsultas, Utente *utentes, Clinica *clinicas)
{
    for (int i = 0; i < numConsultas; i++)
    {
        if (consultas[i].ativo == true)
        {
            listarConsulta(consultas[i], utentes[consultas[i].numUtente - 1], clinicas[consultas[i].numClinica - 1].funcionarios[consultas[i].numMedico - 1]);
        }
    }
}

/**
 * @brief Cria uma consulta
 * 
 * @param consultas 
 * @param indiceConsulta 
 * @param utentes 
 * @param numUtentes 
 * @param clinicas 
 * @param numClinicas 
 */
void criarConsulta(Consulta *consultas, int indiceConsulta, Utente *utentes, int numUtentes, Clinica *clinicas, int numClinicas)
{
    consultas[indiceConsulta].numConsulta = indiceConsulta + 1;
    printf("Escreva a data da consulta (dd-mm-aaaa): ");
    scanf("%d-%d-%d", &consultas[indiceConsulta].data.dia, &consultas[indiceConsulta].data.mes, &consultas[indiceConsulta].data.ano);
    limparBuffer();
    printf("Escreva a hora da consulta (hh:mm): ");
    scanf("%d:%d", &consultas[indiceConsulta].hora.horas, &consultas[indiceConsulta].hora.minutos);
    limparBuffer();

    int numeroSNS;
    int numUtente;

    printf("Numero SNS utente: ");
    scanf("%d", &numeroSNS);
    limparBuffer();
    numUtente = numUtentePeloNumeroSNS(utentes, numUtentes, numeroSNS);

    //se SNS for inválido
    while (numUtente == -1)
    {
        printf("SNS nao existe.\n");
        printf("Numero SNS utente: ");
        scanf("%d", &numeroSNS);
        limparBuffer();
        numUtente = numUtentePeloNumeroSNS(utentes, numUtentes, numeroSNS);
    }
    consultas[indiceConsulta].numUtente = numUtente;

    int numClinica;
    printf("Insira o num clinica: ");
    scanf("%d", &numClinica);
    limparBuffer();

    while (numClinica <= 0 || numClinica > numClinicas)
    {
        printf("Clinica nao existe! Insira uma existente: ");
        scanf("%d", &numClinica);
        limparBuffer();
    }
    consultas[indiceConsulta].numClinica = numClinica;

    int numMedico;
    printf("Insira o num medico: ");
    scanf("%d", &numMedico);
    limparBuffer();

    while (numMedico <= 0 || numMedico > clinicas[numClinica - 1].numFuncionarios)
    {
        printf("Funcionario nao existe! Insira um existente: ");
        scanf("%d", &numMedico);
        limparBuffer();
    }
    consultas[indiceConsulta].numMedico = numMedico;

    printf("Descricao consulta: ");
    fgets(consultas[indiceConsulta].descricao, sizeof(consultas[indiceConsulta].descricao), stdin);
    int len = strlen(consultas[indiceConsulta].descricao);
    if (consultas[indiceConsulta].descricao[len - 1] == '\n')
    {
        consultas[indiceConsulta].descricao[len - 1] = '\0';
    }

    consultas[indiceConsulta].ativo = true;
}

/**
 * @brief Inativa uma consulta
 * 
 * @param consulta Recebe uma consulta para inativar
 * @return Consulta Devolve consulta inativada
 */
Consulta inativarConsulta(Consulta consulta)
{
    consulta.ativo = false;
    return consulta;
}


/**
 * @brief Retorna a idade de um funcionário
 * 
 * @param funcionario Funcionário para o qual vai retornar a idade
 * @param diaHoje Dia de hoje
 * @param mesHoje Mês de hoje 
 * @param anoHoje Ano de hoje
 * @return int Retorna a idade
 */
int idadeFuncionario(Funcionario funcionario, int diaHoje, int mesHoje, int anoHoje)
{
    int idade = anoHoje - funcionario.dataNascimento.ano;
    if (funcionario.dataNascimento.dia > diaHoje && funcionario.dataNascimento.mes > mesHoje)
    {
        idade--;
    }
    return idade;
}

/**
 * @brief Mostra a media de idades por clinica, por equipa
 * 
 * @param clinicas 
 * @param numClinicas 
 */
void mostrarMediaIdadesPorClinica(Clinica *clinicas, int numClinicas)
{
    int diaHoje, mesHoje, anoHoje;
    printf("Escreva a data de hoje (dd-mm-aaaa): ");
    scanf("%d-%d-%d", &diaHoje, &mesHoje, &anoHoje);

    int somatorioM, contadorM, somatorioE, contadorE, somatorioA, contadorA;
    for (int i = 0; i < numClinicas; i++)
    {
        somatorioM = 0;
        contadorM = 0;
        somatorioE = 0;
        contadorE = 0;
        somatorioA = 0;
        contadorA = 0;
        for (int j = 0; j < clinicas[i].numFuncionarios; j++)
        {
            if (clinicas[i].funcionarios[j].equipa == 'm' || clinicas[i].funcionarios[j].equipa == 'M')
            {
                somatorioM += idadeFuncionario(clinicas[i].funcionarios[j], diaHoje, mesHoje, anoHoje);
                contadorM++;
            }
            if (clinicas[i].funcionarios[j].equipa == 'e' || clinicas[i].funcionarios[j].equipa == 'E')
            {
                somatorioE += idadeFuncionario(clinicas[i].funcionarios[j], diaHoje, mesHoje, anoHoje);
                contadorE++;
            }
            if (clinicas[i].funcionarios[j].equipa == 'a' || clinicas[i].funcionarios[j].equipa == 'A')
            {
                somatorioA += idadeFuncionario(clinicas[i].funcionarios[j], diaHoje, mesHoje, anoHoje);
                contadorA++;
            }
        }
        printf("CLINICA %d\n", clinicas[i].numClinica);
        printf("Medicos clinica %d: %d\n", clinicas[i].numClinica, contadorM);
        if (contadorM > 0)
        {
            printf("Media idades: %.2f\n", (float)somatorioM / contadorM);
        }
        printf("Enfermeiros clinica %d: %d\n", clinicas[i].numClinica, contadorE);
        if (contadorE > 0)
        {
            printf("Media idades: %.2f\n", (float)somatorioE / contadorE);
        }
        printf("Auxiliares clinica %d: %d\n", clinicas[i].numClinica, contadorA);
        if (contadorA > 0)
        {
            printf("Media idades: %.2f\n", (float)somatorioA / contadorA);
        }
    }
}

/**
 * @brief Mostra os vencimentos por género e por equipa de uma clínica
 * 
 * @param clinicas 
 * @param numClinicas 
 */
void mostrarSomaVencimentosPorGenero(Clinica *clinicas, int numClinicas)
{
    float somatorioMM, somatorioMF, somatorioEM, somatorioEF, somatorioAM, somatorioAF;
    for (int i = 0; i < numClinicas; i++)
    {
        somatorioMM = 0, somatorioMF = 0, somatorioEM = 0, somatorioEF = 0, somatorioAM = 0, somatorioAF = 0;
        for (int j = 0; j < clinicas[i].numFuncionarios; j++)
        {
            if (clinicas[i].funcionarios[j].equipa == 'm' || clinicas[i].funcionarios[j].equipa == 'M')
            {
                if (clinicas[i].funcionarios[j].genero == 'm' || clinicas[i].funcionarios[j].genero == 'M')
                {
                    somatorioMM += clinicas[i].funcionarios[j].vencimento;
                }
                if (clinicas[i].funcionarios[j].genero == 'f' || clinicas[i].funcionarios[j].genero == 'F')
                {
                    somatorioMF += clinicas[i].funcionarios[j].vencimento;
                }
            }
            if (clinicas[i].funcionarios[j].equipa == 'e' || clinicas[i].funcionarios[j].equipa == 'E')
            {
                if (clinicas[i].funcionarios[j].genero == 'm' || clinicas[i].funcionarios[j].genero == 'M')
                {
                    somatorioEM += clinicas[i].funcionarios[j].vencimento;
                }
                if (clinicas[i].funcionarios[j].genero == 'f' || clinicas[i].funcionarios[j].genero == 'F')
                {
                    somatorioEF += clinicas[i].funcionarios[j].vencimento;
                }
            }
            if (clinicas[i].funcionarios[j].equipa == 'a' || clinicas[i].funcionarios[j].equipa == 'A')
            {
                if (clinicas[i].funcionarios[j].genero == 'm' || clinicas[i].funcionarios[j].genero == 'M')
                {
                    somatorioAM += clinicas[i].funcionarios[j].vencimento;
                }
                if (clinicas[i].funcionarios[j].genero == 'f' || clinicas[i].funcionarios[j].genero == 'F')
                {
                    somatorioAF += clinicas[i].funcionarios[j].vencimento;
                }
            }
        }
        printf("Total vencimentos medicos masculinos: %.2f\n", somatorioMM);
        printf("Total vencimentos medicos femininos: %.2f\n", somatorioMF);
        printf("Total vencimentos enfermeiros masculinos: %.2f\n", somatorioEM);
        printf("Total vencimentos enfermeiros femininos: %.2f\n", somatorioEF);
        printf("Total vencimentos auxiliares masculinos: %.2f\n", somatorioAM);
        printf("Total vencimentos auxiliares femininos: %.2f\n", somatorioAF);
        printf("Total vencimentos: %.2f\n", somatorioMM + somatorioMF + somatorioEM + somatorioEF+ somatorioAM + somatorioAF);
    }
}

/**
 * @brief Mostra as consultas de um funcionário
 * 
 * @param consultas 
 * @param numConsultas 
 * @param numClinica 
 * @param numFuncionario 
 * @param utentes 
 * @param funcionarios 
 */
void mostrarConsultasFuncionario(Consulta *consultas, int numConsultas, int numClinica, int numFuncionario, Utente *utentes, Funcionario *funcionarios){
    for(int i = 0; i<numConsultas; i++){
        if(consultas[i].numClinica == numClinica && consultas[i].numMedico == numFuncionario){
            listarConsulta(consultas[i], utentes[consultas[i].numUtente-1], funcionarios[consultas[i].numMedico-1]);
        }
    }
}

/**
 * @brief Texto do menu (para não o escrever várias vezes)
 * 
 */
void textoMenu()
{
    printf("O que pretende fazer?\n");
    printf("Listar funcionarios de uma clinica (ativos e inativos) (1): \n");
    printf("Listar funcionarios de uma clinica (apenas ativos) (2): \n");
    printf("Tornar funcionario inativo (3): \n");
    printf("Criar novo utente (4):\n");
    printf("Inativar utente (5): \n");
    printf("Listar utentes (ativos e inativos) (6): \n");
    printf("Listar utentes (apenas ativos) (7): \n");
    printf("Criar consulta (8): \n");
    printf("Listar consultas (ativas e inativas) (9): \n");
    printf("Listar consultas (apenas ativas) (10): \n");
    printf("Inativar consulta (11): \n");
    printf("EXERCICIOS: \n");
    printf("Mostrar a quantidade e media de idades de medicos, enfermeiros e auxiliares por clinica e soma de todos os vencimentos (12): \n");
    printf("Listar funcionarios de uma clinica (ativos e inativos) e somatorio de vencimentos (13): \n");
    printf("Mostrar consultas de um funcionario (14): \n");
    printf("Sair (-1): \n");
}

/**
 * @brief Menu de opções
 * 
 * @param clinicas 
 * @param numClinicas 
 * @param utentes 
 * @param numUtentes 
 * @param consultas 
 * @param numConsultas 
 */
void menu(Clinica *clinicas, int numClinicas, Utente *utentes, int *numUtentes, Consulta *consultas, int *numConsultas)
{
    int opcao;
    textoMenu();
    scanf("%d", &opcao);
    limparBuffer();

    while (opcao != -1)
    {
        int numClinica, numFuncionario, indiceClinica, numSNS, numConsulta;
        float somatorioVencimentos;

        switch (opcao)
        {
        case 1:
            printf("Que clinica pretende listar? Numeros disponiveis - ");
            for (int i = 0; i < numClinicas; i++)
            {
                printf("%d ", clinicas[i].numClinica);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numClinica);
            limparBuffer();
            listarFuncionariosClinica(clinicas[obterIndiceClinicaPorNumero(clinicas, numClinicas, numClinica)]);
            break;
        case 2:
            printf("Que clinica pretende listar? Numeros disponiveis - ");
            for (int i = 0; i < numClinicas; i++)
            {
                printf("%d ", clinicas[i].numClinica);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numClinica);
            limparBuffer();
            listarFuncionariosAtivosClinica(clinicas[obterIndiceClinicaPorNumero(clinicas, numClinicas, numClinica)]);
            break;
        case 3:
            printf("De que clinica quer inativar o funcionario? Numeros disponiveis - ");
            for (int i = 0; i < numClinicas; i++)
            {
                printf("%d ", clinicas[i].numClinica);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numClinica);
            limparBuffer();
            listarFuncionariosClinica(clinicas[obterIndiceClinicaPorNumero(clinicas, numClinicas, numClinica)]);
            printf("Que funcionario pretende inativar? (numero do funcionario): \n");
            scanf("%d", &numFuncionario);
            limparBuffer();
            indiceClinica = indiceClinicaPorNumero(clinicas, numClinicas, numClinica);
            clinicas[indiceClinica] = inativarFuncionarioPorNumero(clinicas[indiceClinica], numFuncionario);
            break;
        case 4:
            (*numUtentes)++;
            //utentes = (Utente *)realloc(utentes, *numUtentes);
            criarUtente(utentes, *numUtentes, *numUtentes - 1);
            break;
        case 5:
            printf("Escreva o numero do SNS do utente que pretende desativar: ");
            scanf("%d", &numSNS);
            inativarUtentePeloNumeroSNS(utentes, *numUtentes, numSNS);
            break;
        case 6:
            listarUtentes(utentes, *numUtentes);
            break;
        case 7:
            listarUtentesAtivos(utentes, *numUtentes);
            break;
        case 8:
            (*numConsultas)++;
            //consultas = (Consulta *)realloc(consultas, *numConsultas);
            criarConsulta(consultas, *numConsultas - 1, utentes, *numUtentes, clinicas, numClinicas);
            break;
        case 9:
            listarConsultas(consultas, *numConsultas, utentes, clinicas);
            break;
        case 10:
            listarConsultasAtivas(consultas, *numConsultas, utentes, clinicas);
            break;
        case 11:
            printf("Que consulta pretende inativar?: \n");
            listarConsultas(consultas, *numConsultas, utentes, clinicas);
            scanf("%d", &numConsulta);
            consultas[numConsulta - 1] = inativarConsulta(consultas[numConsulta - 1]);
            break;
        case 12:
            mostrarMediaIdadesPorClinica(clinicas, numClinicas);
            mostrarSomaVencimentosPorGenero(clinicas, numClinicas);
            break;
        case 13:
            printf("Que clinica pretende listar? Numeros disponiveis - ");
            for (int i = 0; i < numClinicas; i++)
            {
                printf("%d ", clinicas[i].numClinica);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numClinica);
            limparBuffer();
            listarFuncionariosClinica(clinicas[obterIndiceClinicaPorNumero(clinicas, numClinicas, numClinica)]);
            somatorioVencimentos = somatorioVencimentosClinica(clinicas[obterIndiceClinicaPorNumero(clinicas, numClinicas, numClinica)]);
            printf("Somatorio vencimentos: %.2f\n", somatorioVencimentos);
            break;
        case 14:
            printf("Que clinica ? Numeros disponiveis - ");
            for (int i = 0; i < numClinicas; i++)
            {
                printf("%d ", clinicas[i].numClinica);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numClinica);
            printf("Que funcionario ? Numeros disponiveis - ");
            for (int i = 0; i<clinicas[numClinica-1].numFuncionarios; i++){
                printf("%d ", clinicas[numClinica].funcionarios[i].numFuncionario);
            }
            printf("- introduza um numero: ");
            scanf("%d", &numFuncionario);
            mostrarConsultasFuncionario(consultas, *numConsultas, numClinica, numFuncionario, utentes, clinicas[numClinica-1].funcionarios);
        default:
            break;
        }

        textoMenu();
        scanf("%d", &opcao);
        limparBuffer();
    }
}