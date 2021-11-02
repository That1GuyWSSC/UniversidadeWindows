#include  <stdio.h>

int main(){

    float peso, media, somatorioPeso = 0;
    int contador = 0;

    while (peso != 0)
    {
         printf("Insira o peso (0 para terminar de inserir):");  
        scanf("%f", &peso);
        if (peso >= 50 && peso <= 80)
        {
            contador++;

            somatorioPeso = somatorioPeso + peso;
        }
    }

        if (peso == 0)
        {  

         media = somatorioPeso / contador;
         printf("A media dos pesos das pessoas entre a 50 a 80kg e : %f", media);
        }
        

    

    

}