#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	int dim;
	struct elemento *next;

};
typedef struct elemento Tabella;


Tabella **crea(int n);
int hash(int a, int el, int b, int p, int n);
int cerca(Tabella *arr, int el);
int inserisci(Tabella **arr, int el, int pos);


int main(){

	int n, a, b, x, i;
	int p=999149;
	int conflitti=0;
	int maxdim=0;
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	int distinti=n;
	Tabella **arr=crea(2*n);
	for(i=0;i<n;i++){		
		scanf("%d",&x);
		int pos=hash(a,x,b,p,(2*n));
		int ok=inserisci(arr,x,pos);
		if(arr[pos]->dim > maxdim) maxdim = arr[pos]->dim;
        	if(ok==1) conflitti++;
		if(ok==-1) distinti--;
	}
	printf("%d\n",conflitti);
	printf("%d\n",maxdim);
	printf("%d\n",distinti);

	return 0;

}
		

Tabella **crea(int n){

	int i;	
	Tabella **arr=(Tabella **)malloc(n*sizeof(Tabella *));
	for(i=0;i<n;i++)
		arr[i]=NULL;
	
	return arr;

}
	

int hash(int a, int el, int b, int p, int n){

	return ((((a*el)+b)%p)%n);

}


int cerca(Tabella *arr, int el){

	Tabella *corr=arr;
	while(corr!= NULL){
		if(corr->info==el) return 0;
		corr=corr->next;
	}
	
	return 1;

}


int inserisci(Tabella **arr, int el, int pos){

	Tabella *aux=(Tabella *)malloc(sizeof(Tabella));
	aux->info=el;
	aux->dim=1;
	aux->next=NULL;
	if(arr[pos] != NULL){
		int ok=cerca(arr[pos],el); 
		if(ok){
			aux->dim=arr[pos]->dim+1;
			arr[pos]=aux;		
			return 1;
		} else return -1;
	} else aux->dim=1;
	arr[pos]=aux;
	return 0;

}
