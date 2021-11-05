#include <stdio.h>

int main(){

    int idade;

    printf("Insira a idade para a inscricao:");
    scanf("%d", &idade);

    switch (idade)
    {
    case(11):
    case(12):
        printf("A sua inscricao foi gratis, devido a idade\n");
        break;
    case(13):
    case(14):
    case(15):
        printf("Juvenil");
        break;
    case(16):
    case(17):
    case(18):
    case(19):
    case(20):
        printf("Junior");
        break;
    case(21):
    case(22):
    case(23):
    case(24):
    case(25):
        printf("Profissional");
        break;
    
    default:
        printf("Idade Invalida");
        break;
    }
    


}