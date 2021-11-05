/*****************************************************************//**
 * \file   Valida.c
 * \brief  
 * 
 * \author lufer
 * \date   November 2020
 *********************************************************************/

#include "all.h"

/**
 * .
 * 
 * \param Valor a validar
 * \param Limite Inferior
 * \param Limite Superior
 * \return 
 */
int validaValor(int v, int limInf, int limSup) {

    int aux = soma(2, 3, 0);

    //limInf < v < limSup
    //h1 return ((limInf <= v) && (v <= limSup));
    //h2
    if ((limInf <= v) && (v <= limSup)) 
        return 1;
    else
        return 0;
}