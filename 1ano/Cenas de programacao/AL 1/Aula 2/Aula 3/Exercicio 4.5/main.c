#include <stdio.h>
#include <stdlib.h>

int main(){

    float medBase, medAltura, area;
    const int divisor = 2;

    printf("Insira a medida da base do triangulo:");
    scanf("%f", &medBase);

    getchar();

    printf("Insira a medida da altura do triangulo:");
    scanf("%f", &medAltura);

    getchar();

    area = (medBase * medAltura) / divisor;

    printf("A area do triangulo e : %.2f", area);

    getchar();
    return 0;

}