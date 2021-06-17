#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	int dim;
	struct elemento *next;

};
typedef struct elemento Tabella;

Tabella **crea(int n);
int hash(int a, int el, int b, int p, int n);
int inserire(Tabella **t, int el, int pos);

int main(){

	int n, a, b, i, x;
	int p=999149;
	int conflitti=0;
	int dimmax=0;
	scanf("%d",&n);
	Tabella **t=crea(n);
	scanf("%d %d",&a,&b);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		int pos=hash(a,x,b,p,n);
		int conflitto=inserire(t,x,pos);
		if(t[pos]->dim > dimmax) dimmax = t[pos]->dim;
        	if(conflitto) conflitti++;
        }
	printf("%d\n",dimmax);
	printf("%d\n",conflitti);

	return 0;
    
}


Tabella **crea(int n){

	int i;	
	Tabella **t=(Tabella **)malloc((2*n)*sizeof(Tabella *));
	for(i=0;i<(2*n);i++)
		t[i]=NULL;

	return t;

}


int hash(int a, int el, int b, int p, int n){

	return ((((a*el)+b)%p)%(2*n));

}


int inserire(Tabella **t, int el, int pos){

	Tabella *aux=(Tabella *)malloc(sizeof(Tabella));
	aux->info=el;
	aux->next=t[pos];
	if(t[pos] != NULL){
		aux->dim=t[pos]->dim+1;
		t[pos]=aux;		
		return 1;
	}
	else aux->dim=1;
	t[pos]=aux;
	return 0;

}




