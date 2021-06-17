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
int Mediana(Node *t, int n, int* conta);
int ContaMediana(Node *t, int n);

int main(){

	int n, el, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d", &el);
		inserisci(&abr, el);
	}
	 	
	printf("%d\n", ContaMediana(abr, n));

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

int Mediana(Node *t, int n, int* conta){

	if(t==NULL)
		return -1;
	int ValoreSinistro=Mediana(t->left, n, conta);
	if(ValoreSinistro == -1){
		(*conta)++;
		if((*conta) == n/2)
			return t->info;
		return Mediana(t->right, n, conta);
	}
	else
		return ValoreSinistro;
		
}

int ContaMediana(Node *t, int n){

	int c=-1;
	return Mediana(t, n, &c);

}




