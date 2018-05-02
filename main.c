#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int info;
  struct nodo *next;
};

struct nodo *crea_lista(){
  return NULL;
};

int leggi_info(struct nodo *lista){
  int info=0;
  printf("Inserire valore: ");
  scanf("%d",&info);
  return info;
  };

struct nodo *ordina_lista(struct nodo *lista,int info){
  struct nodo *prev,*curr,*newnode;
  prev=NULL;
  curr=lista;
  while(curr != NULL && info > curr->info){
    prev=curr;
    curr=curr->next;
  }
  newnode=(struct nodo *)malloc(sizeof(struct nodo));
  newnode->info=info;

  if (prev==NULL){
    newnode->next=lista;
    lista=newnode;
    return lista;
  }else{
    prev->next=newnode;
    newnode->next=curr;
    return lista;
  }
}

void stampa_lista(struct nodo *lista){
  struct nodo *p;
  p=lista;
  printf("START-> ");
  while (p!=NULL){
    printf("%d-> ",p->info);
    p=p->next;
  }
  printf("NULL");
}

int main(){
    struct nodo *lista;
    int dim=0,i=0;
    int info=0;
    lista=crea_lista();
    printf("Quanti elementi vuoi inserire? ");
    scanf("%d",&dim);
    for (i=0;i<dim;i++){
      info=leggi_info(lista);
      lista=ordina_lista(lista,info);
    }
    printf("\n");
    stampa_lista(lista);
    printf("\n");
    return 0;
}
