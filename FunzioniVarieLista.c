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


struct nodo *elimina_duplicati(struct nodo *top){
  struct nodo *curr = top, *now = top, *tmp;
  while (now != NULL){
    while( curr -> next != NULL){
      if (now -> info == curr -> next -> info){
        tmp = curr -> next;
        curr -> next = curr -> next -> next;
        free(tmp);
      }else{
        curr = curr -> next;
      }
    }
    now = now -> next;
    curr = now;
  }
  return top;
}

struct nodo *alterna_elementi_due_liste_r(struct nodo *l1,struct nodo *l2){
  struct nodo *l3,*tmp;
  tmp = malloc(sizeof(struct nodo));
  l3 = malloc(sizeof(struct nodo));

  if (l1 != NULL && l2 != NULL){
    l3 -> next = tmp;
    l3 -> info = l1 -> info;
    tmp -> info = l2 -> info;
    tmp -> next = fondi(l1-> next , l2 -> next);
  }else if (l1 != NULL){
    l3 -> next = fondi(l1 -> next, l2);
    l3 -> info =  l1 -> info;
  }else if (l2 != NULL){
    l3 -> next = fondi(l1, l2 -> next);
    l3 -> info = l2 -> info;
  }else
    return NULL;


  return l3;
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
