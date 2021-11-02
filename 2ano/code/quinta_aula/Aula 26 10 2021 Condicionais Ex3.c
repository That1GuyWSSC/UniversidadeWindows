#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{int a,b,c, res;

 printf("Valores?");
 res = scanf("%d %d %d",&a,&b,&c);
 if (res == 3) 
 {if ((a==b)&&(a==c)) printf("iguais");
  else if ((a >= b) && (a >= c)) printf("%d\n", a);
  else if (b >= c) printf("%d\n", b);
  else printf("%d\n", c);
 } else printf("Dados invalidos!");
 return(0);
}




