/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * 
 * \author lufer
 * \date   November 2020
 *********************************************************************/

#include "all.h"

/**
 * .
 * 
 * \param x
 * \return 
 */
int dobro(int x) {
	return (2 * x);
}

/**
 * .
 * 
 * \param x
 * \param y
 * \param z
 * \return 
 */
int soma(int x, int y, int z) {
    return (x + y + z);
}

char* diaSemanaExtenso(diaSemana d) {

    switch (d) {
    case SEG: return ("Segunda");
    case TER: return ("Terça");
    default: return("Dia Inválido");
    }

}