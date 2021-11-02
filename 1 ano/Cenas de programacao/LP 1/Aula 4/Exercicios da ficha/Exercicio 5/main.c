#include <stdio.h>

int main(){

int a = 125, b = 12345;
long ax = 1234567890;
short s = 4043;
float x = 2.13459;
double dx = 1.1415927;
char c = 'W';
unsigned long ux = 2541567890;


printf("%d", a+c);
printf("%d",x+c);
printf("%d",dx+x);
printf("%d",((int)dx)+ax);
printf("%d",a+x);
printf("%d",s+b);
printf("%d",ax+b);
printf("%d",s+c);
printf("%d",ax+c);
printf("%d",ax+ux);

}