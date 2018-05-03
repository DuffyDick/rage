#include <stdio.h>
#include <stdlib.h>

int calcolo_mcd(int x,int y){
  int mcd;
  int resto;
  if (x%y==0){
    return y;
  }
  else if (y%x==0)
    return x;

  if(y!=0){
    resto=x%y;
    x=y;
    y=resto;
  }
      mcd=calcolo_mcd(x,y);
  return mcd;
}
int main(){
  int x,y,mcd;
  while(1){
    printf("Inserire x ed y: ");
    scanf("%d %d",&x,&y);
    mcd=calcolo_mcd(x,y);
    printf("l'mcd e':%d\n",mcd);
  }
  return 0;
}
