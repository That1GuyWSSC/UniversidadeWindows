#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMTRATAMENTOS 30
#define TAMCLIENTES 30

typedef enum{
    false,
    true
}bool;

typedef struct 
{
    int dia;
    int mes;
    int ano;
}Data;


typedef struct 
{
    char descricao[100];
    float preco;
    Data dataTratamento;
    bool ativo; 
}Tratamento;


typedef struct
{
    char nome[50];
    char genero;
    char email[50];
    Data dataNascimento;
    Tratamento tratamentos[TAMTRATAMENTOS];
    int nTratamentos;
    bool ativo;
    int id;
    

}Cliente;


int main(){

    Cliente clientes[TAMCLIENTES];
    Tratamento tratamentos[TAMTRATAMENTOS];
    int nClientes = 0 ,id , indice, nTratamentos = 0;

    carregaDadosTesteTratamento(tratamentos, &nTratamentos);

    printf("Insira o id do cliente :");
    scanf("%d", &id);

    indice = pesquisaClienteId(clientes, nClientes, id);

    if (indice == -1)
    {
        printf("O id nao existe.");
    }
    else
    {
        fichaCliente(clientes[indice]);
    }
    
    

    return 0;
}

void criarCliente(Cliente *Cliente, int *n){

    printf("Insira o seu nome:");
    fgets((Cliente)->nome, 50, stdin);
    Cliente->nome[strlen(Cliente->nome) -1] = '\0';


    printf("Insira o seu genero: ");
    scanf("%c", &Cliente->genero);

    printf("Insira o seu email: ");
    fgets(Cliente->email, 50, stdin);
    Cliente->email[strlen(Cliente->email) -1] = '\0';
    
    printf("Data de nascimento (d/m/y): ");
    scanf("%d/%d/%d", &Cliente->dataNascimento.dia, &Cliente->dataNascimento.dia, &Cliente->dataNascimento.dia);

   Cliente->nTratamentos = 0;
   Cliente->ativo = true;
   Cliente->id = n +1;
}


bool insereCliente(Cliente *Clientes, Cliente cliente, int *n){

    if ( *n >= TAMCLIENTES)
    {
        return false;
    }

    Clientes[*n] = cliente;
    (*n)++;

}

void listarClientesGenero(Cliente *clientes, int n, char genero){

    for (int i = 0; i < n; i++)
    {
        if (clientes[i].genero = genero)
        {
            printf("Nome : %s\n", clientes[i].nome);
            printf("Genero : %s\n", clientes[i].genero);
            printf("Email : %s\n", clientes[i].email);
            printf("Data de nascimento : %d/ %d/ %d\n", clientes[i].dataNascimento.dia,
                                                         clientes[i].dataNascimento.mes,
                                                         clientes[i].dataNascimento.ano);
        }
        
    }
    

}

void listarClientesAtivos(Cliente *clientes, int n){

    for (int i = 0; i < n; i++)
    {
        if (clientes[i].ativo)
        {
             printf("Nome : %s\n", clientes[i].nome);
            printf("Genero : %s\n", clientes[i].genero);
            printf("Email : %s\n", clientes[i].email);
            printf("Data de nascimento : %d/ %d/ %d\n", clientes[i].dataNascimento.dia,
                                                         clientes[i].dataNascimento.mes,
                                                         clientes[i].dataNascimento.ano);
        }
    }
    
}

void fichaCliente(Cliente cliente){

        printf("Nome : %s\n", cliente.nome);
            printf("Genero : %s\n", cliente.genero);
            printf("Email : %s\n", cliente.email);
            printf("Data de nascimento : %d/ %d/ %d\n", cliente.dataNascimento.dia,
                                                         cliente.dataNascimento.mes,
                                                         cliente.dataNascimento.ano);

}

int pesquisaClienteId(Cliente *clientes, int n, int id ){

    int i=0;
    while (i < n && clientes[i].id != id)
    {
        i++;
    }
    
    if (i >= n)
    {
        return -1;
    }
    
    return i;

}

void ordenaClientesNomeAsc(Cliente *clientes, int n){
    Cliente aux;

    for (int i = 0; i < n -1; i++)
    {
        for (int j = i +1 ; j < n; i++)
        {
            if (strcasecmp(clientes[i].nome, clientes[j].nome) > 0)
            {
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }  
        }        
    }
}

void copyArrayClientes(Cliente *original, Cliente *copia, int n ){

    for (int i = 0; i < n; i++)
    {
        copia[i]=original[i];
    }
    

}

void listarTratamentoCliente(Cliente cliente){

    for (int i = 0; i < cliente.nTratamentos; i++)
    {
        printf(" Descricao: %s ",cliente.tratamentos[i].descricao);
        printf(" Preco: %.2f ",cliente.tratamentos[i].preco); 
        printf(" Data: %d/ %d /%d ", cliente.tratamentos[i].dataTratamento.dia,
                                       cliente.tratamentos[i].dataTratamento.mes,
                                       cliente.tratamentos[i].dataTratamento.ano);
    }
    

}

void listarTratamentosAtivos(Tratamento tratamentos[], int n){
    Cliente aux;

    for (int i = 0; i < n, i++;)
    {
        aux;
    }
    

}

int pesquisaTratamentoId(Tratamento *Tratamentos, int n, int id){

    int i =0;

    while (i < n && Tratamentos[i].id != id)
    {
        i++;
    }
    
    if (i >= n)
    {
        return -1;
    }
    
    return i;

}

bool insereTratamentoCliente(Tratamento *tratamentos, int n, Cliente cliente ){
    int indice, id;
    Tratamento tratamento;

    listarTratamentosAtivos(tratamentos, n);

    printf("Escolha o id tratamento : ");
    scanf("%d, &id");

    indice = pesquisaTratamentoId(tratamentos, n, id);

    if (indice == -1)
    {
        return false;
    }
    


    tratamento = tratamentos[indice];
    
    printf("Data (d/m/a) : ");
    scanf("%d/%d/%d", &tratamento.dataTratamento.dia
                      &tratamento.dataTratamento.mes
                      &tratamento.dataTratamento.ano);

    if (cliente.nTratamentos >= TAMTRATAMENTOS)
    {
        return false;
    }
    

    cliente.tratamentos[cliente.nTratamentos]= tratamento;
    cliente.nTratamentos++;
    
}

void apagarTratamento(Tratamento *tratamentos){

    tratamentos.ativo = false;

}


void carregaDadosTesteTratamento(Tratamento *tratamentos,  int *n){
    tratamentos[0].id = 1;
    strncpy(tratamentos[0].descricao= "depilacao", 100);
    tratamentos[0].preco = 15.0F;
    tratamentos[0].ativo =true;

     tratamentos[1].id = 2;
    strncpy(tratamentos[1].descricao= "depilacao laser", 100);
    tratamentos[1].preco = 60.0F;
    tratamentos[1].ativo =true;



}