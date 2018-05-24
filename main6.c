#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
struct nodo{
    int matricola;
    int voto;
    char nome[max];
    char cognome[max];
    char esame[max];
    struct nodo *next;
};
struct nodo *inserisci_elemento(struct nodo *list,char nome[],char cognome[],int matricola,char esame[],int voto){
    struct nodo *p;
    if (list == NULL){
        list=malloc(sizeof(struct nodo));
        strcpy(list->cognome,cognome);
        strcpy(list->nome,nome);
        list->matricola=matricola;
        strcpy(list->esame,esame);
        list->voto=voto;
        list->next=NULL;
        return;
    }

    p=list;

    while(p->next!=NULL)
        p=p->next;

    p->next=malloc(sizeof(struct nodo));
    p=p->next;
    strcpy(p->cognome,cognome);
    strcpy(p->nome,nome);
    p->matricola=matricola;
    strcpy(p->esame,esame);
    p->voto=voto;
    p->next=NULL;

    return list;
};
struct nodo *Elimina(struct nodo *top)
{
    struct nodo *c=top,*pre;
    while(c!=NULL && c->voto<18)
    {
        pre=c;
        c=c->next;
        free(pre);
    }
    top=c;
    if(top!=NULL)
    {
        pre=c;
        c=c->next;
        while(c!=NULL)
        {
            if(c->voto<18)
            {
                pre->next=c->next;
                free(c);
                c=pre->next;
            }else
            {
                pre=c;
                c=c->next;
            }
        }
    }
    return top;
};
void stampa_lista(struct nodo *lista){
  struct nodo *p;
  p=lista;
  printf("START->\n ");
  while (p!=NULL){
    printf("%s\t%s\t%d\t%s\t%d\n ",p->cognome,p->nome,p->matricola,p->esame,p->voto);
    p=p->next;
  }
  printf("NULL");
}
int main()
{
    struct nodo *top=NULL,*c;
    int voto,matricola;
    char nome[max],cognome[max],esame[max];
    FILE *fp;
    fp=fopen("file.txt","r");
    fscanf(fp,"%s %s %d %s %d\n",nome,cognome,&matricola,esame,&voto);
    while(!feof(fp)){
        top=inserisci_elemento(top,nome,cognome,matricola,esame,voto);
        fscanf(fp,"%s %s %d %s %d\n",nome,cognome,&matricola,esame,&voto);
    }
    top=inserisci_elemento(top,nome,cognome,matricola,esame,voto);
    c=top;
    fclose(fp);
    stampa_lista(top);
      c=Elimina(c);
    printf("\n\n\nLista nuova\n");
    stampa_lista(c);
    fp=fopen("file.txt","w");
    while(c!=NULL)
    {
        fprintf(fp,"%s\t%s\t%d\t%s\t%d\n",c->cognome,c->nome,c->matricola,c->esame,c->voto);
        c=c->next;
    }
    fclose(fp);


    return 0;
}
