#include <stdlib.h>
#include <stdio.h>

int pari (int n);
int dispari (int n);

int main(){
  int n;
  printf("inserire un numero: ");
  while (scanf("%d",&n)) {
    pari(n);
    printf("inserire un numero: ");
  }
}

int pari (int n){
  if (n==0)
    printf("Il numero e' pari\n");
  else
     n=dispari(n-1);

}

int dispari (int n){
  if (n==0)
    printf("Il numero e' dispari\n");
    else
      n=pari (n-1);
}
