#include<stdio.h>
#include<stdlib.h>
typedef struct reg {
   int         chave;
   int         conteudo;
   struct reg *esq, *dir; 
} noh; // nó

busca (noh* r, int k) {
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
       return busca (r->esq, k);
    else
       return busca (r->dir, k);
}
int main(){
noh *r;
int K=5;
    noh *novo;
    novo = malloc (sizeof (noh));
    novo->chave = K;
    novo->esq = novo->dir = NULL;
    busca(r,15);
while (r != NULL && r->chave != K) {
       if (r->chave > K) 
          r = r->esq;
       else
          r = r->dir;
    }
    return r;
}


