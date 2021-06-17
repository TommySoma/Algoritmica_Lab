//albero ternario

#include <stdio.h>
#include <stdlib.h>

struct elemento {

	int info;
	struct elemento *right;
	struct elemento *centr;
	struct elemento *left;

};
typedef struct elemento Node;

Node *crea(Node **t, int el);
Node *inserisci(Node **t, int el);
int conteggio(Node *t);


int main(){

	int n, x, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr,x);
	}
	printf("%d\n",conteggio(abr));

	return 0;

}

Node *crea(Node **t, int el){

	Node *aux=(Node *)malloc(sizeof(Node));
	aux->info=el;
	aux->right=NULL;
	aux->centr=NULL;
	aux->left=NULL;
	
	return aux;

}

Node *inserisci(Node **t, int el){

	if((*t)==NULL) *t=crea(&(*t),el);
	else if((el)%((*t)->info)==0) (*t)->centr=inserisci(&(*t)->centr,el);
	     else if(el > (*t)->info) (*t)->right=inserisci(&(*t)->right,el);
			  else (*t)->left=inserisci(&(*t)->left,el);

	return *t;

}

int conteggio(Node *t){
	
	if(t==NULL) return 0;
	if(t->right != NULL && t->centr != NULL && t->left != NULL) return 1+conteggio(t->right)+conteggio(t->centr)+conteggio(t->left);
	return conteggio(t->right)+conteggio(t->centr)+conteggio(t->left);

}




