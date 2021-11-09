#include <stdio.h>

int main(){


    char genero, opcao, opcao2;
    int idade, contador = 0, contadorM = 0, contadorF = 0, contadorDinheiro = 0;
    float dinheiro, somatorioDinheiro = 0, media;

    printf("Prentende comecar (Y/N):");
    scanf("%c", &opcao);

while (opcao == 'Y' || opcao == 'y')
{
    printf("Qual e o seu genero (M/F):");
    scanf("%c", &genero);

    getchar();

    printf("Qual e a sua idade :");
    scanf("%d", &idade);

    printf("Quanto dinheiro prentende gastar estas compras de Natal :");
    scanf("%f", &dinheiro);

       somatorioDinheiro+=dinheiro;
    getchar();

    printf("Prentende repetir o processo (Y/N):");
    scanf("%c", &opcao);
    
}

    if (genero == 'M')
    {
        contadorM++;
    }
    
    if (genero == 'F')
    {
        contadorF++;
    }
    
    if (genero == 'F' &&   (idade > 40) && (dinheiro > 200))
    {
         contadorDinheiro++;
    }

   
    if (contador != 0){
        media = somatorioDinheiro / contador;
        printf("Media de valor em compras: %.2f", media);

         printf("%d pessoas do genero masculino.\n", contadorM);
    printf("%d pessoas do genero feminino.\n", contadorF);
 
    printf("%d pessoas do genero feminino com mais de 40 anos que pretendem gastar mais de 200 euros.\n", contadorDinheiro);
 
    }
    

    

}