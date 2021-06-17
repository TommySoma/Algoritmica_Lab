//albero binario: ordinamento

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
void ordinamento(Node *t);

int main(){

	int n, x, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr,x);
	}
		
	ordinamento(abr);

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

void ordinamento(Node *t){

	if(t!=NULL){
		ordinamento(t->left);
		printf("%d\n", t->info);
		ordinamento(t->right);
	}

}
