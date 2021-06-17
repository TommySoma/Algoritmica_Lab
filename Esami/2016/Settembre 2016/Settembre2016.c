#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

struct oggetto{

	ElementoDiLista *testa;
	ElementoDiLista *coda;
	int dim;
};
typedef struct oggetto Lista;

Lista *CreaLista();
void DistruggiLista(Lista *lista);
void InserisciTesta(Lista *lista, int el);
void CancellaTesta(Lista *lista);
void CancellaCoda(Lista *lista);
void CancellaElementoDiLista(Lista *lista, int el);
int member(Lista *lista, int el);
void Stampa(Lista *lista);

void main(){

	Lista *lru=CreaLista();
	int c, x, n;
	int fine=0;
	scanf("%d\n", &n);
	while(!fine){
		scanf("%d", &c);
		if(c==0)
			fine++;
		else if(c==1){
			scanf("%d", &x);
			if(member(lru, x)){
				CancellaElementoDiLista(lru, x);
				InserisciTesta(lru, x);
			}
			else{
				if(lru->dim==n){
					CancellaCoda(lru);
					InserisciTesta(lru, x);
				}
				else
					InserisciTesta(lru, x);
			}
		}
		else if(c==2)
			Stampa(lru);
	}
	
}					

Lista *CreaLista(){
	
	Lista *lista=malloc(sizeof(Lista));
	lista->testa=NULL;
	lista->coda=NULL;
	lista->dim=0;
	return lista;

}

void DistruggiLista(Lista *lista){

	while(lista->testa != NULL){			
		ElementoDiLista *tmp=lista->testa;	//salva l'elemento corrente
		lista->testa=lista->testa->next;	//avanza nella lista
		free(tmp);				//dealloca l'elemento
	}
	free(lista);					//dealloca la struct che conteneva la lista
	
}

void InserisciTesta(Lista *lista, int el){

	ElementoDiLista *new=malloc(sizeof(ElementoDiLista));
	new->info=el;
	if(lista->dim==0){
		lista->testa=new;
		new->next=NULL;
		lista->coda=lista->testa;
		lista->dim++;
		return;
	}
	new->next=lista->testa;
	lista->testa=new;
	lista->dim++;
	
}

void CancellaTesta(Lista *lista){

	if(lista->dim==1){
		free(lista->testa);
		lista->testa=NULL;
		lista->coda=NULL;
		lista->dim--;
		return;
	}
	if(lista->dim > 1){
		ElementoDiLista *tmp=lista->testa;
		lista->testa=lista->testa->next;
		free(tmp);
		lista->dim--;
	}
	
}

void CancellaCoda(Lista *lista){

	if(lista->dim==1){
		free(lista->coda);
		lista->testa=NULL;
		lista->coda=NULL;
		lista->dim--;
		return;
	}
	if(lista->dim > 1){
		ElementoDiLista *corr=lista->testa;
		ElementoDiLista *prec=NULL;
		while(corr->next != NULL){
			prec=corr;
			corr=corr->next;
			
		}
		free(corr);
		prec->next=NULL;
		lista->coda=prec;
		lista->dim--;
	}
	
}

void CancellaElementoDiLista(Lista *lista, int el){

	ElementoDiLista *corr=lista->testa;
	ElementoDiLista *prec=NULL;
	while(corr!=NULL && corr->info!=el){
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){
		CancellaTesta(lista);
		return;
	}
	if(corr!=NULL && corr->next==NULL){
		CancellaCoda(lista);
		return;
	}
	if(corr!=NULL){
		prec->next=corr->next;
		lista->dim--;
		free(corr);
	}
	
}

int member(Lista *lista, int el){

	ElementoDiLista *corr=lista->testa;
	while(corr!=NULL && corr->info!=el){
		corr=corr->next;
	}
	if(corr!=NULL)
		return 1;
		
	return 0;
	
}

void Stampa(Lista *lista){
	
	ElementoDiLista *corr=lista->testa;
	while(corr!=NULL){
		printf("%d ", corr->info);
		corr=corr->next;
	}
	printf("$\n");
	
}













	























	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
	
	
	
	
	
	





