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
int TrovaPiuGrande(Node *t);
int TrovaSecondoPiuGrande(Node *t, int ValPadre);

int main(){

	int n, x, i;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisci(&abr,x);
	}
		
	printf("%d\n", TrovaSecondoPiuGrande(abr, -1));

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

int TrovaPiuGrande(Node *t){

	if(t==NULL)
		return -1;
	if (t->right != NULL) 
        // finché ho nodi sulla dx vado alla ricerca del più grande il nodo col valore più grande è il nodo più a dx senza figli destri
        	return TrovaPiuGrande(t->right);
     	else 
        	return t->info;
    
}

int TrovaSecondoPiuGrande(Node *t, int ValPadre){
    
    	if(t==NULL) 
		return -1;
    	if(t->right != NULL) 
        // finché ho nodi sulla dx vado alla ricerca del più grande il nodo col valore più grande è il nodo più a dx senza figli destri
        	return TrovaSecondoPiuGrande(t->right, t->info);
     	else {
        	int ValMaxFiglio=TrovaPiuGrande(t->left);
        	if(ValMaxFiglio > ValPadre) 
            		return ValMaxFiglio;
         	else
            		return ValPadre;
        
    	}
}









