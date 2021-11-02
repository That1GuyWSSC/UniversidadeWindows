#include <stdio.h>

void main(){

    int idade, anos, filhos, bonusIdade, bonusAnos, bonusFilhos;
    scanf("%d %d %d", &idade, &anos, &filhos);
    if (idade > 45)
    {
        bonusIdade = (idade -45) *5;
    } 
    else bonusIdade = 0;

    if(anos <= 10)
    {
        bonusAnos = anos *10;
    }
    else bonusAnos = (anos - 10) * 20 +100;

    if (filhos >=4)
    {
        bonusFilhos = 75;
    }
    else bonusFilhos = filhos * 25;

    printf("Vai receber um bonus de %d" , bonusAnos+bonusFilhos+ bonusIdade);

}