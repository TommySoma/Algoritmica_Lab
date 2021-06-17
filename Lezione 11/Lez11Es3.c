#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{

	char *nome;
	int valore;

};
typedef struct elemento Oggetto;


struct elemento1{

	Oggetto info;
	struct elemento1 *next;

};
typedef struct elemento1 Lista;


Lista **crea(int n);
int hash(char *nom, int n);
void push(Lista **a, char *nom, int val);
void inserisci(Lista **a, char *nom, int val, int pos);
void ins_arr(Lista **a, Oggetto *arr, int n, int *len);
int compare(const void *a,const void *b);


int main(){

	int n, i, len;
	scanf("%d",&n);
	Oggetto *arr=malloc(n*sizeof(Oggetto));
	Lista **a=crea(2*n);
	for(i=0;i<n;i++){
		char *nom=(char *)malloc(101*sizeof(char));
		scanf("%s",nom);
		int v;
		scanf("%d",&v);
		int pos=hash(nom,(2*n));
		inserisci(a,nom,v,pos);
	}
	ins_arr(a,arr,(2*n),&len);
	qsort(arr,len,sizeof(Oggetto),compare);
	if(len>15){
    		for(i=0;i<15;i++)
      			printf("%s\n",arr[i].nome);
  	} else {
    		for(i=0;i<len;i++)
      			printf("%s\n",arr[i].nome);
    
  	}

	return 0;

}


Lista **crea(int n){

	Lista **a=malloc(n*sizeof(Lista));
	int i;
	for(i=0;i<n;i++)
		a[i]=NULL;

	return a;

}


int hash(char *nom, int n){

	int somma=0;
	int i;
	for(i=0;i<strlen(nom);i++)
		somma+=(unsigned int) nom[i];
	
	return (somma%n);

}


void push(Lista **a, char *nom, int val){
  
	Lista *new=malloc(sizeof(Lista));
  	new->info.nome=nom;
  	new->info.valore=val;
  	if ((*a)==NULL){
    		new->next=NULL;
    		(*a)=new;
  	} else {
    		new->next=*a;
    		*a=new;
  	}
}


void inserisci(Lista **a, char *nom, int val, int pos){

	Lista *corr=a[pos];
	while(corr!=NULL){
		if(!strcmp(corr->info.nome,nom)){
			if(corr->info.valore < val){
				corr->info.valore=val;			
				return;
			} else return;
		} else corr=corr->next;
	}
	
	push(&(a[pos]),nom,val);
	
	return;

}


void ins_arr(Lista **a, Oggetto *arr, int n, int *len){

	int i;
	int j=0;
	for(i=0;i<n;i++){
		Lista *corr=a[i];
		while(corr!=NULL){
			arr[j]=corr->info;
			j++;
			corr=corr->next;
		}
	}
	*len=j;

}
	

int compare(const void *a,const void *b){
	
	Oggetto a1= *(Oggetto*)a;
	Oggetto b1= *(Oggetto*)b;
  	if(a1.valore == b1.valore) return strcmp(a1.nome,b1.nome);
  	return b1.valore - a1.valore;

}





