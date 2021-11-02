typedef enum
{
    false,
    true
} bool;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int horas;
    int minutos;
} Hora;

typedef struct
{
    int numFuncionario;
    char nome[30];
    char equipa;
    char genero;
    Data dataNascimento;
    float vencimento;
    bool ativo;
} Funcionario;

typedef struct
{
    int numUtente;
    char nome[30];
    int numeroSNS;
    bool ativo;
} Utente;

typedef struct
{
    int numClinica;
    Funcionario *funcionarios;
    int numFuncionarios;
} Clinica;

typedef struct
{
    int numConsulta;
    Data data;
    Hora hora;
    int numUtente;
    int numClinica;
    int numMedico;
    char descricao[200];
    bool ativo;
} Consulta;