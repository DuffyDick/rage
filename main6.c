#include <stdio.h>
#include <stdlib.h>
#define max 100

void merge_sort(int a[],int inizio,int fine){
  int medio;
  if (inizio < fine){
    medio = (inizio+fine)/2;
    merge_sort(a,inizio,medio);
    merge_sort(a,medio+1,fine);

    merge(a,inizio,medio,fine);
  }
  return;
}

void merge(int a[],int inizio,int medio,int fine){
  int i = inizio,j=medio+1,k=0 ,b[max];
  while (i <= medio && j <= fine){
    if (a[i]<a[j]){
      b[k]=a[i];
      i++;
    }else{
      b[k]=a[j];
      j++;
    }
    k++;
  }

  while (i <= medio){
    b[k]=a[i];
    i++;
    k++;
  }
  while(j <= fine){
    b[k]=a[j];
    j++;
    k++;

  }

  for(k=inizio;k <= fine;k++)
    a[k]=b[k-inizio];

  return;
}

int main(){
  int a[max];
  for (int i=0;i<8;i++){
    printf("Inserire %d numero: ",i+1);
    scanf("%d",&a[i]);
  }
  merge_sort(a,0,7);
  for (int i=0;i<8;i++){
    printf("%d ",a[i]);
  }
  return 0;
}
