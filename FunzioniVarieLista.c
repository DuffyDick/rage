#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int info;
  struct nodo *next;
};

struct nodo *inserisci_elemento(struct nodo *lista,int info){
  struct nodo *prev,*curr,*new;
  prev=NULL;
  curr=lista;
  while (curr != NULL){
    prev = curr;
    curr = curr -> next;
  }
  new = malloc(sizeof(struct nodo));
  new->info=info;

  if (prev == NULL){
    new -> next = lista;
    lista = new;
    return lista;
  }else {
    prev -> next = new;
    new -> next = curr;
    return lista;
  }
}


struct nodo *cancella_elemento(struct nodo *top){
  struct nodo *prev,*c=top;
  while (c != NULL && c -> info == 3){
    prev = c;
    c = c -> next;
    free (c);
  }
  top = c;
  if (top != NULL){
    prev = c;
    c = c -> next;
    while (c != NULL){
      if (c -> info == 3){
        prev -> next = c -> next;
        free (c);
        c = prev -> next;
      }else{
        prev = c;
        c = c -> next;
      }
    }
  }
  return top;
};


void Sorting(struct nodo *top)
{
    int flag,tmp;
    struct nodo *curr;
    if (top == NULL)
        return;
    do
    {
        flag = 0;
        curr = top;

        while (curr->next != NULL)
        {
            if (curr->info > curr->next->info)
            {
                tmp = curr -> info;
                curr -> info = curr -> next -> info;
                curr -> next -> info = tmp;
                flag = 1;
            }
            curr = curr->next;
        }
    }
    while (flag);
}


void visualizza_lista(struct nodo *lista){
  struct nodo *p;
  p = lista;
  printf("START -> ");
  while (p != NULL){
    printf("%d -> ",p->info);
    p = p->next;
  }
  printf("END;");
  printf("\n");
}

void elimina_duplicati(struct nodo *top){
  struct nodo *p,*p2,*dup;
  p = top;

  while(p != NULL && p -> next != NULL){

    p2 = p;
    while (p2 -> next != NULL){
      if (p -> x == p2 -> next -> x){
        dup = p2 -> next;
        p2 -> next = p2 -> next -> next;
        free(dup);
      }else
        p2 = p2 -> next;
    }
    p = p -> next;
  }
}

int main(){
  struct nodo *top;
  int info,dim;
  printf("Quanti elementi vuoi inserire? ");
  scanf("%d",&dim);
  for (int i=0;i<dim;i++){
    printf("Inserire informazione: ");
    scanf("%d",&info);
    top=inserisci_elemento(top,info);
  }
  printf("\nlista normale:\n");
  visualizza_lista(top);
  printf("\nlista ordinata:\n");
  Sorting(top);
  visualizza_lista(top);
  printf("\nlista con elemento eliminato:\n");
  cancella_elemento(top);
  visualizza_lista(top);
}
