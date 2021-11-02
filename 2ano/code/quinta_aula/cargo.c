#include <stdio.h>

void main (){

    int cargo;
    float salario, novoSalario;
    
    printf("Introduza o seu cargo : ");
    scanf("%d", &cargo);
    printf("Introduza o seu salario : ");
    scanf("%f", &salario);

    switch (cargo)
    {
    case 1:
        novoSalario = salario + salario * 0.1;
        break;
    case 2 :
        novoSalario = salario +salario * 0.2;
        break;
    case 3 :
        novoSalario = salario + salario * 0.3;
        break;
    
    default: novoSalario = salario + salario*0.4;
        break;
    }
    
    printf("O seu novo salario sera : %.2f \n", novoSalario);

}