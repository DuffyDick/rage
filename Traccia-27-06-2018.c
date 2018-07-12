//PRIMO ESERCIZIO

struct nodo *elimina(struct nodo *top,int k){
  struct nodo *prev, *curr = top;
  while (curr != NULL && curr -> info > k){
    prev = curr;
    curr = curr -> next;
    free(prev);
  }

  top = curr;
  if (top != NULL){
    prev = curr;
    curr = curr -> next;
    while(curr != NULL){
      if (curr -> info > k){
        prev -> next = curr -> next;
        free(curr);
        curr = prev -> next;
      }else{
        prev = curr;
        curr = curr -> next;
      }
    }
  }
  return top;
}


//SECONDO ESERCIZIO

struct nodo *elimina_maggiore(struct nodo *top){
    struct nodo *prev = NULL, *curr = top,*precedente,*successivo,*massimo;
    int max = 0;
    while (curr != NULL){
      if (curr -> info > max){
        max = curr -> info;
        precedente = prev;
        successivo = curr -> next;
        massimo = curr;
      }
      prev = curr;
      curr = curr -> next;
    }

    free(massimo);
    if (precedente == NULL)
      top = successivo;
    else
      precedente -> next = successivo;

    return top;
}


//TERZO ESERCIZIO

void elimina_stringa(char s[],char c){
  if (*s != '\0')
    elimina_stringa(s+1,c);
  if (*s == c)
    strcpy(s,s+1);
}
