#include <stdlib.h>
#include <stdio.h>
#include "AB.h"

//---------------------------------------------------------------------------------
// Cria um nó da árvore com o valor especificado. Esq e Dir ficam NULOS.
//---------------------------------------------------------------------------------
Arvore *cria(int valor) {
    Arvore *no = (Arvore *) malloc(sizeof(Arvore));

    no->valor = valor;
    no->esq = no->dir = NULL;

    return no;
}

//---------------------------------------------------------------------------------
// Localiza o nó da árvore com o valor especificado. Se não achar retorna NULO.
//---------------------------------------------------------------------------------
Arvore *localiza(Arvore *r, int valor) {
    Arvore *aux;

    // Se árvore está vazia então não encontrou
    if (r == NULL)
        return NULL;

    // Se achou um nó com o valor procurado então retorna o nó
    if (r->valor == valor)
        return r;

    // Localiza na subárvore à esquerda
    aux = localiza(r->esq, valor);

    if (aux != NULL)
        return aux;
    else
        // Se não encontrou na esquerda, localiza na subárvore à direita
        return localiza(r->dir, valor);
}

//---------------------------------------------------------------------------------
// Adiciona um novo nó com o valor especificado à direita do nó pai.
// Retorna true ou false, se a operação foi bem sucedida ou não.
//---------------------------------------------------------------------------------
bool adicionaDir (Arvore *r, int valorPai, int valor) {
    // Localiza o nó pai
    Arvore *aux = localiza(r, valorPai);

    // Se ele não existe ou a posição à direita já esta ocupada então não adiciona
    if (aux == NULL || aux->dir != NULL)
        return false;

    // Adiciona novo nó à direita
    aux->dir = cria(valor);

    return true;
}

//---------------------------------------------------------------------------------
// Adiciona um novo nó com o valor especificado à esquerda do nó pai.
// Retorna true ou false, se a operação foi bem sucedida ou não.
//---------------------------------------------------------------------------------
bool adicionaEsq (Arvore *r, int valorPai, int valor) {
    // Localiza o nó pai
    Arvore *aux = localiza(r, valorPai);

    // Se ele não existe ou a posição à esquerda já esta ocupada então não adiciona
    if (aux == NULL || aux->esq != NULL)
        return false;

        // Adiciona novo nó à esquerda
    aux->esq = cria(valor);

    return true;
}

//---------------------------------------------------------------------------------
// Percorre a arvore e imprime seus nós usando o percurso em ordem
//---------------------------------------------------------------------------------
void  emOrdem(Arvore *r)
{
   if (r != NULL)
   {
      emOrdem(r->esq);
      printf("%d ", r->valor);
      emOrdem(r->dir);
   }
}

//---------------------------------------------------------------------------------
// Percorre a arvore e imprime seus nós usando o percurso pré-ordem
//---------------------------------------------------------------------------------
void  preOrdem(Arvore *r)
{
   if (r != NULL)
   {
      printf("%d ", r->valor);
      preOrdem(r->esq);
      preOrdem(r->dir);
   }
}

//---------------------------------------------------------------------------------
// Percorre a arvore e imprime seus nós usando o percurso pós-ordem
//---------------------------------------------------------------------------------
void  posOrdem(Arvore *r)
{
   if (r != NULL)
   {
      posOrdem(r->esq);
      posOrdem(r->dir);
      printf("%d ", r->valor);
   }
}

//---------------------------------------------------------------------------------
// Soma todos os valores dos nós de uma árvore.
//---------------------------------------------------------------------------------
int soma(Arvore *r) {
    // Para uma árvore vazia a soma é ZERO
    if (r == NULL)
        return 0;

    // Soma o valor do nó com a soma das subárvores esquerda e direita
    return r->valor + soma(r->esq) + soma(r->dir);
}

//---------------------------------------------------------------------------------
// Calcula o menor elemento de uma árvore.
//---------------------------------------------------------------------------------
bool menor(Arvore *r, int *p) {
    if (r == NULL)
        return false;

    // Assume que o menor é o valor do nó raiz
    int m = r->valor, mEsq, mDir;

    // Compara o menor com o menor da subárvore esquerda
    if (menor(r->esq, &mEsq) && mEsq < m)
        m = mEsq;

    // Compara o menor com o menor da subárvore direita
    if (menor(r->dir, &mDir) && mDir < m)
        m = mDir;

    *p = m;

    return true;
}

//---------------------------------------------------------------------------------
// Calcula a altura de uma árvore.
//---------------------------------------------------------------------------------
int altura(Arvore *r) {
    // Por definição uma árvore vazia tem altura -1
    if (r == NULL)
        return -1;

    // Calcula as alturas das subárvores esquerda e direita
    int altEsq = altura(r->esq),
        altDir = altura(r->dir);

    // Soma 1 que é a altura do nó atual
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

//---------------------------------------------------------------------------------
// Conta quantos elementos existem na árvore.
//---------------------------------------------------------------------------------
int tamanho(Arvore *r) {
    // Uma árvore vazia tem 0 elementos
    if (r == NULL)
        return 0;

    // Soma 1 que é o nó atual
    return 1 + tamanho(r->esq) + tamanho(r->dir);
}

//---------------------------------------------------------------------------------
// Exclui todos os nós de uma árvore, liberando a memória.
//---------------------------------------------------------------------------------
void libera(Arvore *r) {
    // Se a árvore está vazia, então não há nada a liberar
    if (r == NULL)
        return;

    // Libera primeiro as subárvores esquerda e direita e, por último, o nó raiz
    libera(r->esq);
    libera(r->dir);
    free(r);
}
