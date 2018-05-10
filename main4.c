#include <stdio.h>
#include <stdlib.h>
int calcola_conigli(int n,int totali,int nati){
  totali=nati+totali;
  if (n==0)
    return totali;
  else
    return calcola_conigli(n-1,totali,totali-nati);
}

int main(){
    int x=0;
    printf("Inserire il numero di mesi: ");
    scanf("%d",&x);
    x=calcola_conigli(x,0,2);
    printf("Conigli totali:%d\n",x);;
    return 0;
}
