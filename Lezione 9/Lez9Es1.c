//albero biario: ricerca

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
void cerca(Node *t, int el, int conta);

int main(){

	int n, i, x;
	int ok=1;
	Node *abr=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisce(&abr,x);
	}
	while(ok){
		scanf("%d",&x);
		if(x>=0) cerca(abr,x,0);
		else ok=0;
	}


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

void cerca(Node *t, int el, int conta){ 			
	
	if(t==NULL){
		printf("NO\n");
		return;
	}
	if(t->info == el){
		printf("%d\n",conta);
		return;
	}
	if(el > t->info) cerca(t->right,el,conta+1);
	else cerca(t->left,el,conta+1);

}



