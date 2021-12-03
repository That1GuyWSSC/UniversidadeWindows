#include <stdio.h>

void main(){

    float total, compra, compras=0;
    int quantidade= 0;

    do
    {
        printf("Montante? : \n");
        scanf("%f", &total);
    } while (total <=0);

    do
    {   printf("Valor da compra %d : ", quantidade);
        scanf("%f", &compra);
        if (total >=compra)
        {
            total= total - compra;
            quantidade++;
            compras= compras= compra;
            printf("Compra registrada! '");
        }
        
    } while (total >=compra);
    
    printf("Saldo disponivel : %.2f euros \n", total);
    printf("Quantidade : %d", quantidade);
    

}