//Arvore Binaria
#include<stdio.h>
#include<stdlib.h>






typedef struct No{
	
	int valor;
	struct No *esq;
	struct No *dir;
} Arv;
void imprimeEmordem(Arv* a){
	if(a!= NULL){
		imprimeEmordem(a->esq);
		printf("%d\n", a->valor);
		imprimeEmordem(a->dir);
		
	}	
}
Arv* insere(Arv* a, int valor){
	if(a==NULL){
		a= (Arv*) malloc (sizeof(Arv));
		a->valor=valor;
		a->esq=NULL;
		a->dir= NULL;
		}else{ if (valor < a->valor){
			a->esq = insere(a->esq, valor);
			} else{ if (valor > a->valor){
				a->dir=insere(a->dir, valor);	
				}
			      }
		       }	
	return a;
}
//Arv* retira (Arv* r, int valor);
int main(){
	Arv* a =NULL;
	a=insere(a,10);
	a=insere(a,5);
	a=insere(a,3);
	a=insere(a,7);
	a=insere(a,20);
	printf("Saida:\n");
	imprimeEmordem(a);
	return 0;	
}

