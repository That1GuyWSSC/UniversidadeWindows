#include <stdlib.h>
#include <stdio.h>


float kelvinToCelcius(float x);
float celsiusToKelvin(float x);


int main(){

    float temperatura;
    char conversor;


    printf("Insira uma temperatura:");
    scanf("%f", &temperatura);


    printf("Quer converter a sua temperatura para (c para celsius e k para kelvin):");
    scanf(" %c", &conversor);

    getchar();


    if (conversor == 'c' || conversor == 'C')
    {
        printf("%2.f", kelvinToCelcius(temperatura));
    }
    

    if (conversor == 'k' || conversor == 'K'){

       printf("%2.f", celsiusToKelvin(temperatura));
    }



}

float kelvinToCelcius(float temperatura){

    return(temperatura - 273);
    
}


float celsiusToKelvin(float temperatura){


     return (temperatura + 273);

}