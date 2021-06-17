#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	int colore;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;

Node *crea(Node **t, int el, int col);
Node *inserisce(Node **t, int el, int col);
int visita(Node *t, int *ok);

int main(){

	int n, i, x, y;
	Node *abr=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		inserisce(&abr, x, y);
	}
	int *ok=1;
	visita(abr, &ok);
	if(ok) printf("TRUE\n");
	else printf("FALSE\n");
	
	return 0;

}

Node *crea(Node **t, int el, int col){

	Node *aux=malloc(sizeof(Node));
	aux->info=el;
	aux->colore=col;
	aux->right=NULL;
	aux->left=NULL;

	return aux;

}

Node *inserisce(Node **t, int el, int col){

	if(*t==NULL) *t=crea(&(*t), el, col);
	else if(el > (*t)->info) (*t)->right=inserisce(&(*t)->right, el, col);
	     else (*t)->left=inserisce(&(*t)->left, el, col);

	return *t;

}

int visita(Node *t, int *ok){

	if(t==NULL) return 0;
	int sx=visita(t->left, ok);
	int dx=visita(t->right, ok);
	if((*ok)==0) return 0;
	if(abs(sx-dx) > 1){
		*ok=0;
		return 0;
	}
	int somma=sx+dx;
	if(t->left != NULL && t->right != NULL){
		if(((t->left)->colore == 0) && ((t->right)->colore == 0)) somma--;
	}
	if(t->colore == 0) return somma+1;
	
	return somma;
	
}	
	
	

	




