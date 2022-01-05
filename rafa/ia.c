#include <stdio.h>

void insere (int s[], int N, int x){                                                        
       int i = 0;
       int j;
      for (;i < N; i++)
    {
        if (s[i] > x)
        {
            for ( j = N; j > i; j--)
            {
               s[j] = s[j-1]; 
            }
            break;
        }
        
       
    }
        
   }

   void insere (int s[], int N, int x) {
    int i, j;
    
    for (i=0; i<N; i++) {
        if (s[i]>x) {
            for (j=N; j>i; j--) s[j] = s[j-1];
            s[j]=x;
            break;
        }
    }
}
void printarray(int a[], int N){
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", a[i]);
    }
}    

int main(){

    int arr[4];
    arr[0]=4;
    arr[1]=6;
    arr[2]=7;
    int x = 5;

    insere(arr, 4, 10);
    printarray(arr , 4);
    
}