
struct maquina{
    int numero;
    int tempo;
    struct maquina* next;
};

struct operacoes{
    int ops;
    struct operacoes *next;
    struct maquina cena;
};

struct Job{
    int data;
    struct Job *next;
};

struct process {
    int pr;
    struct operacoes numero;
    struct Job* next;
};
