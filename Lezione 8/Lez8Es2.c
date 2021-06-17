#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *prev;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void inserisci_testa(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);

int main(){

	ElementoDiLista **lista=NULL;
	ElementoDiLista **lista_finita=NULL;
	int len;
	scanf("%d", &len);
	int i, n;
	for(i=0; i<len; i++){
		scanf("%d", &n);
		inserisci_coda(&lista, &lista_finita, n);
	}
	stampa(lista_finita);

	return 0;
	
}

void inserisci_coda(ElementoDiLista **lista, ElementoDiLista **newlista, int x){

	ElementoDiLista *aux;
	aux=malloc(sizeof(ElementoDiLista));
	aux->info=x;
	aux->next=NULL;
	aux->prev=NULL;
	if(*lista==NULL){
		*lista=aux;
		*newlista=*lista;
	} else {
		aux->prev=*newlista;
		(*newlista)->next=aux;
		*newlista=aux;
		}

}

void stampa(ElementoDiLista *lista){
	
	ElementoDiLista *aux=lista;
	while(aux != NULL){
		printf("%d\n",aux->info);
		aux=aux->prev;
	}
}


