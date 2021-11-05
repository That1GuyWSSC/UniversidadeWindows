#include <stdio.h>

int main(){

    float IVA = 0.23;
    float kW;
    int tipoClienteNum;
    char tipoCliente;
    printf("Qual e a media de kw que gasta por mes:");
    scanf("%f", &kW);

    printf("Estes sao os tipos de cliente :\nParticulares (continente) - 1\nParticulares (ilhas) - 2\nPequenas empresas -3 \nMedias e grandes empresas - 4\nEstado e organismos publicos -5\n");
    printf("Que tipo de cliente e (insira o numero correspondente):");
    scanf("%f", tipoClienteNum);

    switch (tipoClienteNum)
    {
    case(1):
        break;
    
    default:
        break;
    }

}