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
int LCA(Node *t, int x, int y);

int main(){

	int n, el, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d", &el);
		inserisci(&abr, el);
	}
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);
	if(x>y){
		int tmp=x;
		x=y;
		y=tmp;
	}
	 	
	printf("%d\n", LCA(abr, x, y));

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

int LCA(Node *t, int x, int y){ 	//x deve sempre essere <= di y

	if(t==NULL)
		return -1;
	if(t->info >= x && t->info <= y)
		return t->info;
	if(t->info < x)
		return LCA(t->right, x, y);
	if(t->info > y)
		return LCA(t->left, x, y);
		
}






