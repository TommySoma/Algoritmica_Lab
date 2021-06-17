#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;

Node *crea(Node **t, int el);
Node *inserisce(Node **t, int el);
int dimensione_sx(Node *t);
int dimensione_dx(Node *t);

int main(){

	int n, i, x;
	Node *abr=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisce(&abr,x);
	}
	int dimsx;
	int dimdx;
	dimsx=dimensione_sx(abr);
	dimdx=dimensione_dx(abr);
	int dim=dimsx-dimdx;
	if(dim>=0)
		printf("%d\n", dim);
	else
		printf("%d\n", (-1)*dim);
		
	return 0;

}

Node *crea(Node **t, int el){

	Node *aux=malloc(sizeof(Node));
	aux->info=el;
	aux->right=NULL;
	aux->left=NULL;

	return aux;

}

Node *inserisce(Node **t, int el){

	if(*t==NULL) *t=crea(&(*t),el);
	else if(el > (*t)->info) (*t)->right=inserisce(&(*t)->right,el);
	     else (*t)->left=inserisce(&(*t)->left,el);

	return *t;

}

int dimensione_sx(Node *t){ 			
	
	if(t==NULL)
		return 0;
	int dim=1;
	if(t->left != NULL)
		dim=dim + dimensione_sx(t->left);

	return dim;		

}

int dimensione_dx(Node *t){ 			
	
	if(t==NULL)
		return 0;
	int dim=1;
	if(t->right != NULL)
		dim=dim + dimensione_dx(t->right);

	return dim;		

}




		

	
