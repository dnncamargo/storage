#include <stdio.h>
#include <stdlib.h>
/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct arvore
{
  int num;
  struct arvore* sad;
  struct arvore* sae;
} arvore;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
arvore* createarvore()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int arvorevazia(arvore* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void mostraarvore(arvore* t)
{
  /* Essa função imprime os elementos de forma recursiva */
  
  printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!arvorevazia(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    printf("%d ", t->num); /* mostra a raiz */
    mostraarvore(t->sae); /* mostra a sae (subárvore à esquerda) */
    mostraarvore(t->sad); /* mostra a sad (subárvore à direita) */
  }
  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void inserarvore(arvore** t, int num)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (arvore*)malloc(sizeof(arvore)); /* Aloca memória para a estrutura */
    (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
    (*t)->sad = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      inserarvore(&(*t)->sae, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      inserarvore(&(*t)->sad, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInarvore(arvore* t, int num) {
  
  if(arvorevazia(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }
  
  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInarvore(t->sae, num) || isInarvore(t->sad, num);
}

int main()
{
  arvore* t = createarvore(); /* cria uma árvore */
  
  inserarvore(&t, 12); /* insere o elemento 12 na árvore */
  inserarvore(&t, 15); /* insere o elemento 15 na árvore */
  inserarvore(&t, 10); /* insere o elemento 10 na árvore */
  inserarvore(&t, 13); /* insere o elemento 13 na árvore */
   
  mostraarvore(t); /* Mostra os elementos da árvore em pré-ordem */
  
  if(arvorevazia(t)) /* Verifica se a árvore está vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }
  
  if(isInarvore(t, 15)) { /* Verifica se o número 15 pertence a árvore */
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }
  
  if(isInarvore(t, 22)) { /* Verifica se o número 22 pertence a árvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }
  
  free(t); /* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}
