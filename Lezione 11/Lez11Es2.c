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
int solosx(Node *t);
int solodx(Node *t);
void visita(Node *t);

int main(){

	int n, i, x;
	Node *a=NULL;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &x);
		inserisce(&a, x);
	}
	visita(a);

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

int solosx(Node *t){

	if(t==NULL) return 0;
	else return 1+solosx(t->left);

}

int solodx(Node *t){

	if(t==NULL) return 0;
	else return 1+solodx(t->right);

}

void visita(Node *t){

	if(t == NULL) return;
	visita(t->left);
	int sx = solosx(t->left);
	int dx = solodx(t->right);
	if(sx>dx) printf("%d\n", t->info);
	visita(t->right);
	
	return;	


 }
 
 
 
 
