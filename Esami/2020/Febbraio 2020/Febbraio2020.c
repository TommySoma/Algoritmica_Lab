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
void cerca(Node *t, int livello_scelto, int livello_corrente);

int main(){

	int n, i, x, k;
	Node *abr=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisce(&abr,x);
	}
	scanf("%d", &k);
	cerca(abr, k, 0);

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

void cerca(Node *t, int livello_scelto, int livello_corrente){ 			
	
	if(t==NULL)
		return;
	cerca(t->left, livello_scelto, livello_corrente + 1);
	if(livello_corrente == livello_scelto) printf("%d\n", t->info);
	cerca(t->right, livello_scelto, livello_corrente + 1);

}




