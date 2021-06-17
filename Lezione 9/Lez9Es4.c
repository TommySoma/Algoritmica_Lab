#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;

Node *crea(Node **t, int el);
Node *inserisci(Node **t, int el);
int confronto(Node *t, Node *m, int el, int conta);


int main(){

	int n, k, i, x;
	scanf("%d %d",&n,&k);
	Node *abr1=NULL;
	Node *abr2=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr1,x);
	}
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr2,x);
	}
	printf("%d\n",confronto(abr1,abr2,k,0));

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

int confronto(Node *t, Node *m, int el, int conta){
	
	if(conta==el) return 1;	
	if(t->info != m->info) return 0;
	else {		
		if(el > t->info && el < m->info) return confronto(t->right,m->left,el,conta+1);
		if(el < t->info && el > m->info) return confronto(t->left,m->right,el,conta+1);
		if(el > t->info && el > m->info) return confronto(t->right,m->right,el,conta+1);
		else return confronto(t->left,m->left,el,conta+1);
	}
	 

}
