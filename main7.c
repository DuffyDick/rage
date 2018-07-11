#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

void elimina(char a[],char k){
    if (*a != '\0')
      elimina(a+1,k);
    if (*a == k)
      strcpy(a,a+1);
}


int main(){
  char a[max],k = 'a';
  scanf("%s",a);
  elimina(a,k);
  printf("%s\n",a);
  return 0;
}
