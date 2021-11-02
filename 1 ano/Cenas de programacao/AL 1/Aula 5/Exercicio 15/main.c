#include <stdio.h>

int main(){

char ins;

printf("Instrucao:");
scanf("%c", &ins);

switch (ins){

    case 'L':
    case 'l':
        printf("Ligar");
        break;
    case 'D' :
    case 'd' :
        printf("Desligar");
        break;
    case 'F':
    case 'f':
        printf("Furar");
        break;
    default:
        printf("Opercao invalida");
        break;

        
}

getchar();
}
