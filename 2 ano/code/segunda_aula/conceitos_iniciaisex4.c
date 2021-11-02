#include <stdio.h>

int main(int argc, char const *argv[])
{
	int nota1teste, nota2teste;
	int nota1trabalho,nota2trabalho,nota3trabalho,nota4trabalho;
	int notafinal;
	printf("Introduza a nota do primerio teste\n");
	scanf("%d", &nota1teste);
	printf("Introduza a nota do segundo teste\n");
	scanf("%d", &nota2teste);
	printf("A nota componente escrita e : %d\n", (nota1teste+nota2teste)/2);
	printf("Introduza a nota do primerio trabalho\n");
	scanf("%d", &nota1trabalho);
	printf("Introduza a nota do segundo trabalho\n");
	scanf("%d", &nota2trabalho);
	printf("Introduza a nota do terceiro trabalho\n");
	scanf("%d", &nota3trabalho);
	printf("Introduza a nota do quarto trabalho\n");
	scanf("%d", &nota4trabalho);
	printf("A nota da componente pratica e de : %d \n", (nota1trabalho+nota2trabalho+nota3trabalho+nota4trabalho)/4);
	printf("------------\n");
	notafinal = (((nota1teste+nota2teste)/2)*0.7)+(((nota1trabalho+nota2trabalho+nota3trabalho+nota4trabalho)/4)*0.3);
	printf("A nota final do aluno e de : %d \n", notafinal);
	return 0;

}