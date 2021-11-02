#include <stdio.h>

void main(){

    int a,b,c,res;
    printf("Insira os valores : \n");
    res=scanf("%d %d %d", &a,&b,&c);
    if (res=3)
    {
        if ((a > b) && (a >c)) printf("%d", a);
        else if (b >c )
        {
            printf("%d", b);
        }
        else
        {
            printf("%d",c);
        }
        
        
        
    }
    else printf("Valores invalidos");
    

}