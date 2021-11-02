#include <stdio.h>


int soma(int numeros[], int n);
float media (int numeros[], int n, int *out);
int maiorNumeroInteiro(int *numeros, int n);
int menorNumeroInteiro(int *numeros, int n);


int main(){

    int idades[50], idade, i = 0, somaIdades, out= 0;
    float mediaIdades;

    puts("Insira uma idade negativa para sair");
    printf("idade :");
    scanf("%d", &idade);

    while (idade >= 0)
    {

        idades[i]= idade;
        i++;

        printf("idade :");
        scanf("%d", &idade);
    }

    somaIdades = soma(idades, i);

    printf("Soma : %d\n", somaIdades);


    mediaIdades = media(idades, i, &out);

    if (out)
    {
        printf("%f", mediaIdades);
    }

    else
    {
        puts("Ocorreu um erro");
    }
    
    


}

float media (int numeros[], int n, int *out){
    float res;
    out = 1;

    if (n == 0)
    {
        out = 0;
        return 0.0F;
    }
    
    res = (float)soma(numeros, n) / n;

    return res;

}


int soma(int numeros[], int n){
    int resultado = 0;

    for (int i = 0; i < n; i++)
    {
        resultado += numeros[i];
    }

    return resultado;


}
/**
 * @brief 
 * 
 * @param numeros 
 * @param n 
 * @return int 
 */

// nao trata n=0;
int maiorNumeroInteiro(int *numeros, int n){

    int maior;

    maior = numeros[0];

    for (int i = 1; i < n; i++)
    {
        if (maior < numeros[1])
        {
            maior = numeros[i];
        }
        
    }
    

    

    return maior;


}

int menorNumeroInteiro(int *numeros, int n){

    int menor;

    menor = numeros[0];

    for (int i = 1; i < n; i++)
    {
        if (menor > numeros[1])
        {
            menor = numeros[i];
        }
        
    }
        

    return menor;


}
