#include <stdio.h>

int main()
{
int valor;
char sequencia[10]; // array de caracteres

printf("Valor?");
scanf("%d", &valor);

printf("String?");
scanf("%s", sequencia);

printf("%d\n", valor);
printf("%s\n", sequencia);


return(0);
}
