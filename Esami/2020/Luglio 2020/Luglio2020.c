#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 101

struct node{

  	int info;		//chiave
  	char *str;		//valore
  	struct node* next;
};  	
typedef struct node Tabella;

int Hash(x,n);
int compare_string(const void*a,const void *b);
int inserisci (Tabella **tab,int n, int x, char* val);
void cerca (Tabella **tab, int k, int n);

void main(){

    	int n, x, k, i;
    	char* valore;
    	scanf("%d", &n);
    	Tabella **tab=malloc((2*n)*sizeof(Tabella));
    	for (i=0; i<(2*n); i++){
      		tab[i]=NULL;
    	}
    	for (i=0; i<n; i++){
      		valore=malloc(MAXLEN*sizeof(char));
      		scanf("%d", &x);
      		scanf("%s", valore);
      		inserisci(tab, n, x, valore);
    	}
    	scanf("%d", &k);
    	cerca(tab, k, n);
    
}

int Hash(x,n){

  	return (x%109) % (2*n);
  	
}

int compare_string(const void*a,const void *b){

  	char* st1=*(char**)a;
  	char* st2=*(char**)b;
  	return strcmp(st1,st2);
  	
}

int inserisci (Tabella **tab,int n, int x, char* val){

  	int pos=Hash(x,n);
  	if (tab[pos]==NULL){
    		Tabella* aux=malloc(sizeof(Tabella));
    		aux->info=x;
    		aux->str=val;
    		aux->next=NULL;
    		tab[pos]=aux;
    		return;
  	}
  	Tabella *corr= tab[pos];
  	while (corr->next!=NULL){
    		if (corr->info==x){
      			corr->str=val;
      			return;
    		}
    		corr=corr->next;
  	}
  	if (corr->info==x){
    		corr->str=val;
    		return;
  	}
  	Tabella* aux=malloc(sizeof(Tabella));
  	aux->info=x;
  	aux->str=val;
  	corr->next=aux;
}

void cerca (Tabella **tab, int k, int n){

  	int pos=Hash(k,n);
  	char** strings=malloc(n*sizeof(char*));
  	Tabella *corr=tab[pos];
  	int i=0;
  	int len;
  	if (tab[pos]==NULL) {
    		printf("NESSUN VALORE SU QUESTO INDIRIZZO!\n");
    		return;
  	}
  	while (corr!=NULL){
    		strings[i]=malloc(MAXLEN*sizeof(char));
    		strings[i] = corr->str;
    		corr=corr->next;
    		i++;
  	}
  	len=i;
  	qsort(strings,len,sizeof(char*),compare_string);
  	for (i=0;i<len;i++){
    		printf("%s\n",strings[i]);
  	}
  	for (i=0;i<len;i++){
    		free(strings[i]);
  	}
  	free(strings);
}


