typedef struct ME
{
    int ordem;
    int nif;
    char *codigo;
    int tempo;
    int distancia;
}*ME;

typedef struct MU
{
    char *codigo;
    char *tipo;
    float custo;
    int autonomia;
}*MU;
