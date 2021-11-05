/**
 * @file funcoes.h
 * @author Duarte Melo e João Diogo
 * @brief Assinaturas de funções definidas no "funcoes.c" e definição de constantes
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define TAMANHOARRAY 50

extern float kelvinParaCelsius(float kelvin);
extern float celsiusParaKelvin(float celsius);

extern float mediaArray(float *array, int n);

extern float obterMaior(float *array, int n);
extern float obterMenor(float *array, int n);

extern void escreveQuadro(char escalaConv, float tempsIniciais[], float tempsFinais[], int contador);