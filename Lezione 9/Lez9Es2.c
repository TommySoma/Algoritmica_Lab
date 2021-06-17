//albero binario: visita

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;

Node *crea(Node **t, int el);
Node *inserisci(Node **t, int el);
int visita(Node *t);
int max(int a, int b);


int main(){

	int n, x, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr,x);
	}
		
	printf("%d\n",visita(abr));

	return 0;

}


Node *crea(Node **t, int el){

	Node *aux=(Node *)malloc(sizeof(Node));
	aux->info=el;
	aux->right=NULL;
	aux->left=NULL;
	
	return aux;

}


Node *inserisci(Node **t, int el){

	if((*t)==NULL) *t=crea(&(*t),el);
	else if(el > (*t)->info) (*t)->right=inserisci(&(*t)->right,el);
	     else (*t)->left=inserisci(&(*t)->left,el);

	return *t;

}


int max(int a, int b){

	if(a>=b) return a;
	else return b;

}


int visita(Node *t){
		
		
	if(t==NULL) return 0;
	return max(1+visita(t->left),1+visita(t->right));

}
