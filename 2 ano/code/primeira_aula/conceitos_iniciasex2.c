#include <stdio.h>

int main(int argc, char const *argv[])
{
	float lar, comp, area;
	printf("Insira a largura do retangulo\n");
	scanf("%f", &lar);
	printf("Insira o comprimento do retangulo\n");
	scanf("%f", &comp);
	area = lar * comp;

	printf("%f * %f = %f", lar,comp,area);

	return 0;
}