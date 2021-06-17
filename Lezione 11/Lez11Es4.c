#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{

	char *contatto;
	char *numero;

};
typedef struct elemento Rubrica;

struct elemento1{

	Rubrica record;
	struct elemento1 *next;

};
typedef struct elemento1 Tabella;

int hash(char *c, int n);
void inserisci(Tabella **a, int pos, char *c, char *n);
void stampa(Tabella *a);


int main(){

	int n, i;
	scanf("%d",&n);
	Tabella** a=malloc(2*n*sizeof(Tabella));
	for(i=0;i<(2*n);i++)
		a[i]=NULL;	//inizializzo
	for(i=0;i<n;i++){
		char *cont=(char *)malloc(101*sizeof(char));		
		scanf("%s",cont);
		char *num=(char *)malloc(21*sizeof(char));
		scanf("%s",num);
		inserisci(a, n, cont, num);
	}
	int k;
	scanf("%d",&k);	
	stampa(a[k]);


	return 0;

}



int hash(char *c, int n){

	int somma=0;
	int i=0;
	for(i=0;i<strlen(c);i++)
		somma+=(unsigned int)c[i];
	
	
	return somma % (2*n);

}


void inserisci(Tabella **a, int dim, char *c, char *n){

	Rubrica aux;
	aux.contatto=c;
	aux.numero=n;
	Tabella *new=(Tabella *)malloc(sizeof(Tabella));
	new->record=aux;
	int pos=hash(c,dim);
	Tabella *corr=a[pos];
	Tabella *prec=NULL;
	if(a[pos]==NULL){
		a[pos]=new;
		a[pos]->next=NULL;
		return;
	}
	while(corr!=NULL && strcmp(corr->record.contatto,c)<0){
		prec=corr;
		corr=corr->next;
	}
	if(prec==NULL){
		new->next=a[pos];
		a[pos]=new;
		return;
	}
	prec->next=new;
	new->next=corr;

}
	


void stampa(Tabella *testa){

	if (testa==NULL) return;
	printf("%s %s\n",testa->record.contatto,testa->record.numero);
	stampa(testa->next);
	

}





