
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

Arv* remove(Arv* r, int valor){
	if(r==NULL){
	
		return 0;
	}else { 
		if(r->valor > valor){
		r->esq= remove(r->esq, valor);
		
		} else { 
			if (r->valor < valor ){
			r->dir= remove(r->dir, valor);
			
			}else { 
				if (r->esq==NULL && r->dir==NULL){
				free(r);
				r=NULL;
				}else{ 
					if (r->esq==NULL){
					Arv* x= r;
					r= r->dir;
					free(x);
					} else{ 
						if(r->dir==NULL){
						Arv* x=r;
						r= r->esq;
						free(x);
						}
					      }
					
						
				      }
		
				}
			
			}
			
		}
}	
int main(){
	
	Arv* a=NULL;
	a=insere(a,10);
	a=insere(a,5);
	a=insere(a,1);
	a=insere(a,2);
	a=insere(a,3);
	a=insere(a,7);
	a=insere(a,20);
	a=insere(a,30);
	a=insere(a,35);
	printf("Saida:\n");
	imprimeEmordem(a);
	a=remove(a,1);
	//a=remove(a,5);
	imprimeEmordem(a);
	a = remove(a,30);
	imprimeEmordem(a);
	
	return 0;
	
	
	
}

