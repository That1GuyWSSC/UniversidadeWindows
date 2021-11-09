#include <stdio.h>
#include "funcoes.h"

/**
 * @brief Converter graus Kelvin para graus Celsius
 * 
 * @param kelvin Valor em kelvin
 * @return float Valor em Celsius
 */
float kelvinParaCelsius(float kelvin)
{
    return (kelvin - 273);
}


/**
 * @brief Converter graus Celsius para graus Kelvin
 * 
 * @param celsius 
 * @return float 
 */
float celsiusParaKelvin(float celsius)
{
    return (celsius + 273);
}


/**
 * @brief Obtem a media a partir de um array
 * 
 * @param array Array
 * @param n Numero de elementos do array
 * @return float Media (retorna 0 no caso de n = 0, para prevenir divisão por 0)
 */
float mediaArray(float *array, int n)
{
    //prevenir divisao por 0
    if (n == 0){
        return 0;
    }
    int somatorio = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio += array[i];
    }
    return ((float) somatorio / (n));
}

/**
 * @brief Obtem o maior valor de um array
 * 
 * @param array Array
 * @param n Numero de elementos do array
 * @return float Maior valor
 */
float obterMaior(float *array, int n)
{
    float aux = array[0];
    for (int i = 1; i < n; i++){
        if (array[i] > aux){
            aux = array[i];
        }
    }
    return aux;
}


/**
 * @brief Obtem o menor valor de um array
 * 
 * @param array Array
 * @param n Numero de elementos do array
 * @return float Menor valor
 */
float obterMenor(float *array, int n)
{
    float aux = array[0];
    for (int i = 1; i < n; i++){
        if (array[i] < aux){
            aux = array[i];
        }
    }
    return aux;
}

/**
 * @brief Escreve o quadro final das temperaturas - iniciais e convertidas, maior e menor valores de ambas, média de ambas
 * 
 * @param escalaConv recebe a escala de conversão
 * @param tempsIniciais recebe o array das temperaturas iniciais
 * @param tempsFinais recebe o array das temperaturas finais
 * @param contador recebe o contador (numero de temperaturas)
 */
void escreveQuadro(char escalaConv, float tempsIniciais[], float tempsFinais[], int contador)
{
    if (escalaConv == 'k' || escalaConv == 'K')
    {
        for (int i = 0; i < contador; i++)
        {
            tempsFinais[i] = celsiusParaKelvin(tempsIniciais[i]);
        }
        printf("Celsius\t\tKelvin\n");
        printf("---\t\t---\n");
    }
    else if (escalaConv == 'c' || escalaConv == 'C')
    {
        for (int i = 0; i < contador; i++)
        {
            tempsFinais[i] = kelvinParaCelsius(tempsIniciais[i]);
        }
        printf("Kelvin\t\tCelsius\n");
        printf("---\t\t---\n");
    }

    for (int i = 0; i < contador; i++)
    {
        printf("%.2f\t\t%.2f\n", tempsIniciais[i], tempsFinais[i]);
    }

    printf("\n");

    printf("Media: %.2f\t", mediaArray(tempsIniciais, contador));

    printf("Media: %.2f\n\n", mediaArray(tempsFinais, contador));

    printf("Maior: %.2f\t", obterMaior(tempsIniciais, contador));

    printf("Maior: %.2f\n", obterMaior(tempsFinais, contador));

    printf("Menor: %.2f\t", obterMenor(tempsIniciais, contador));

    printf("Menor: %.2f", obterMenor(tempsFinais, contador));
}