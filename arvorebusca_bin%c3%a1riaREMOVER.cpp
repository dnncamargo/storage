#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// typedef int bool;
typedef int Chave;
typedef struct No{
	
	Chave valor;
	struct No *esq;
	struct No *dir;
}No;

typedef No* Ponteiro;

Ponteiro  inicializa(){            //inicializa a arvore - basta tornarmos esse endereço NULL ou usar No* inicializa();
 	return NULL;
}

Ponteiro criaNovoNo(Chave ch){
	
	Ponteiro NovoNo= (Ponteiro)malloc(sizeof(No));
	NovoNo->esq=NULL;
	NovoNo->dir=NULL;
	NovoNo->valor= ch;
	return(NovoNo);
}
//Inserção de folha
Ponteiro adiciona (Ponteiro r, Ponteiro No){
	if (r == NULL) 
		return (No);
	if((No->valor) < (r->valor))
		r->esq= adiciona(r->esq, No);
	else
		r->dir= adiciona(r->dir, No);
	
	return(r);

}

// Remoção - temos que manter a regra
// como fazer - 1. Se o nó a ser retirado possui no maximo um descendente, substitua-o por este
// Se o nó possuiu dois descendente, substituimos o nó a ser retirado pelo nó mais à direita da subarvore a esquerda OU substituimos o nó a ser retirado pelo nó mais à esquerda da subarvore à direita.
// Resumindo - precisamos saber o nó a ser removido/ seu pai/ e o seu nó substituto.
//Temos então a busca binária não recursiva, que devolve o ponteiro do nó buscado e depois abastece o ponteiro pai com o ponteiro pai deste.

Ponteiro buscando(Ponteiro r, Chave ch, Ponteiro *pai){
	Ponteiro atual=r;
	*pai= NULL;
	while(atual){
		if (atual->valor==ch) return (atual);
		*pai=atual;
		if (ch< atual->valor)atual = atual->esq;
		else 
			atual= atual->dir;
	}
	return (NULL);
	
} 
Ponteiro remove(Ponteiro r, Chave ch){
	Ponteiro pai, No,p,q;
	 No= buscando(r, ch, &pai);
	if (No==NULL) return r;
	if (!No->esq || !No->dir){
		if(!No->esq) q = No->dir;
		else q=No->esq;
	}
	else{
		p=No;
		q=No->esq;
		while (q->dir){
			p=q;
			q=q->dir;
		}
	
	if (p!= No){
		p->dir=p-> esq;
		q->esq=No->esq;
	}
		q->dir= No->dir;
	}	
	if (!pai){
		free(No);
		return q;
	}
	if (ch < pai->valor ) pai->esq =q;
	else pai->dir =q;
	free(No);
	return r;
}

void imprimeEmOrdem( Ponteiro r ){
	
	if(r!=NULL){
		imprimeEmOrdem(r->esq);
		printf("%d\n",r->valor);
		imprimeEmOrdem(r->dir);
	}
}

int main(){
	Ponteiro r = inicializa();
	Ponteiro No= criaNovoNo(10);
	r=adiciona(r,No);
	No = criaNovoNo(6);
	r= adiciona(r, No);
	No = criaNovoNo(12);
	r= adiciona(r, No);
	No = criaNovoNo(21);
	r= adiciona(r, No);
	printf("Imprime EM Ordem\n");
	imprimeEmOrdem(r); 
	Ponteiro N = remove(r,21);
	imprimeEmOrdem(r);
	printf("oiiii\n");
	Ponteiro N1 = remove(r,6);
	imprimeEmOrdem(r);	
return 0;

}
