#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

void inserisci_ultimo(ElementoDiLista **lista, int el){

	ElementoDiLista *ultimo; //puntatore per la scansione
	ElementoDiLista *new_el;
	new_el=malloc(sizeof(ElementoDiLista)); //creazione nuovo elemento
	new_el->info=el;
	new_el->next=NULL;
	if(*lista==NULL)
		*lista=new_el;
	else{
		ultimo=*lista;
		while(ultimo->next!=NULL)
			ultimo=ultimo->next; //concatenazione nuovo elemento in fondo alla lista
		ultimo->next=new_el;
	}
}

void RecStampaInversa(ElementoDiLista *lista){

	if(lista!=NULL){
		RecStampaInversa(lista->next);
		printf("%d\n", lista->info);	
	}
	
}

int main(){

	ElementoDiLista **lista=NULL;
	int len;
	scanf("%d", &len);
	int i, n;
	for(i=0; i<len; i++){
		scanf("%d", &n);
		inserisci_ultimo(&lista, n);
	}
	RecStampaInversa(lista);

	return 0;
	
}








