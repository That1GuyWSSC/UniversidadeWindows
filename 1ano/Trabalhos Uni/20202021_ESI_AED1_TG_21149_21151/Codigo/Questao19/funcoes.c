#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Obtem o maior valor de um array
 * 
 * @param array Array
 * @param n Numero de elementos do array
 * @return float Maior valor
 */
int obterMaior(int *array, int n)
{
    int aux = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > aux)
        {
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
int obterMenor(int *array, int n)
{
    int aux = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] < aux)
        {
            aux = array[i];
        }
    }
    return aux;
}

/**
 * @brief Retorna a amplitude de um array
 * 
 * @param menor Menor valor do array
 * @param maior Maior valor de um array
 * @return float 
 */
int amplitudeArray(int menor, int maior)
{
    return (maior - menor);
}

/**
 * @brief Gera um número aleatório entre um limite superior e um limite inferior
 * 
 * @param limiteInf limite superior
 * @param limiteSup limite inferior
 * @return int Número aleatório
 */
int gerarNumero(int limiteInf, int limiteSup)
{
    int numero = (rand() % (limiteSup - limiteInf + 1)) + limiteInf;

    return numero;
}

/**
 * @brief Mostra um array
 * 
 * @param array Array
 * @param n Quantidade de elementos do array
 */
void mostraArray(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}

/**
 * @brief Ordena um array decrescentemente
 * 
 * @param array Array
 * @param n Quantidade de elementos do array
 */
void ordenaArrayInteiroDesc(int *array, int n)
{
    int aux;

    //ordena o array (decrescente)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

/**
 * @brief Mostra os valores impares de um array
 * 
 * @param array Array
 * @param n Quantidade de elementos do array
 */
void mostraImpares(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((array[i] % 2) != 0)
        {
            printf("%d\n", array[i]);
        }
    }
}

/**
 * @brief Procedimento de escrever o menu, criado para que o menu apenas seja alterado num sítio, caso seja necessário.
 * 
 */
void escreveMenu()
{
    printf("Escreva o que pretende:\n");
    printf("1 - Saber o maior e menor elemento do conjunto\n");
    printf("2 - Saber a amplitude do conjunto\n");
    printf("3 - Obter uma listagem dos numeros impares com ordenacao decrescente\n");
    printf("4 - Visualizar o conjunto (no estado em que foi gerado inicialmente)\n");
    printf("5 - Sair\n");
}