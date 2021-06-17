#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento EDL;

void coda(EDL **lista, int el);
void sommatutti(EDL *lista, int *somma);
void stampa(EDL *lista);

int main(){

	int n, x, i;
	int somma=0;
	scanf("%d",&n);
	EDL *lista=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		coda(&lista,x);
	}
	stampa(lista);	
	sommatutti(lista,&somma);
	stampa(lista);


	return 0;

}


void coda(EDL **lista, int el){

	EDL *corr=*lista;
	EDL *aux=malloc(sizeof(EDL));
	aux->info=el;
	aux->next=NULL;
	if(corr==NULL) *lista=aux;
	else {
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=aux;
	}

}


void stampa(EDL *lista){

	EDL *corr=lista;
	while(corr->next!=NULL){		
		printf("%d ",corr->info);
		corr=corr->next;
	}
	printf("%d\n",corr->info);

}


void sommatutti(EDL *lista, int *somma){

	int f;
	if(lista==NULL) return;
	*somma= *somma + lista->info;
  	f= *somma - lista->info;
	sommatutti(lista->next,somma);
	lista->info= *somma - f - lista->info;

}
