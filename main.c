
#include <stdio.h>
#include <stdlib.h>
#define max 100

int riempi_array (int array[]){
  int dim=0;
  printf("Quanti elementi vuoi inserire? ");
  scanf("%d",&dim);
  for (int i=0;i<dim;i++){
    printf("Inserire %d elemento: ",i+1 );
    scanf("%d",&array[i]);
  }
  return dim;
}

void stampa_array (int array[],int dim){
  for (int i=0;i<dim;i++){
    printf("Elemento %d: %d\n",i+1,array[i]);
  }
}

int calcola_minimo (int array[],int dim){
  int min;
  dim--;
  if (dim==0){
    return array[0];
  }
  else{
    min=calcola_minimo(array,dim);
  }
  if (array[dim]<min){
    return array[dim];
  }
  else{
    return min;
  }
}


int main(){
  int array[max];
  int dim=0,min=0;
  dim=riempi_array(array);
  stampa_array(array,dim);
  min=calcola_minimo(array,dim);
  printf("Il minimo e':%d\n",min);

  return 0;
}
