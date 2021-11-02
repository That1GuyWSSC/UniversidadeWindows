/*****************************************************************//**
 * \file   all.h
 * \brief  
 * 
 * Extern
 * 
 * \author lufer
 * \date   November 2020
 *********************************************************************/

//#pragma once
//Ou
#ifndef GLOBAL
#define GLOBAL

#define MAX 30
#define TRUE 1
#define FALSE 0
extern int dobro(int x);
extern int soma(int x, int y, int z);
extern int validaValor(int v, int x, int y);

extern const int TOT;       //constantes apenas se declaram no .h

//enumerados
enum diaSemana { SEG, TER, QUA, QUI, SEX, SAB, DOM };
typedef enum diaSemana diaSemana;

extern char* diaSemanaExtenso(diaSemana d);

/*
 caso (x)
    0: escrevo "SEgunda"
    SEG: escrevo "Segunda"
*/

typedef enum color
{
    RED,
    GREEN,
    BLUE
}color ;

#endif // !GLOBAL

#ifndef _STDBOOL
#define _STDBOOL
//typedef int boolean;
typedef enum  { False, True } boolean;    //False==0; True==1
#define true True
#define false False

#endif
