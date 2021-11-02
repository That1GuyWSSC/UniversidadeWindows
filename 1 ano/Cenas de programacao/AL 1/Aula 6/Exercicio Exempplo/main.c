#include <stdio.h>

int main(){
    
    //declarar as variaveis
    int numero, contador = 0, contadorPares = 0;

    do 
    {
        printf("Numero:");
        scanf("%d", &numero);

        if (numero %2 == 0)
        {
            contadorPares++;

        }

        contador++;
        
    } while (contador < 10);
    
    printf("Numeros Pares : %d", contadorPares);

    return 0;

}