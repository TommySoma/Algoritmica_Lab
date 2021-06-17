#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    int num;
    char *info;
    struct elemento *right;
    struct elemento *left;
};
typedef struct elemento Node;

Node *crea(int num, char *info);
void inserisci(Node **t, char *info, int num);
void minimo(Node *t, int *a);
void cerca(Node *t, char *str, int *a);


int main(){

    	Node *abr = NULL;
    	int n, num, a = 5555;
    	char *info, *str;
	scanf("%d", &n);
    	for(int i=0; i<n; i++) {
        	info=(char *)malloc(101 * sizeof(char));
        	scanf("%s", info);
        	scanf("%d", &num);
        	inserisci(&abr, info, num);
   	}

    	str=(char *)malloc(101 * sizeof(char));
    	scanf("%s", str);
    	cerca(abr, str, &a);
    	printf("%d\n", a);

    	return 0;
}

Node *crea(int num, char *info){

	Node *aux=(Node *)malloc(sizeof(Node));
	aux->info=info;
	aux->num=num;
	aux->right=NULL;
	aux->left=NULL;
	
	return aux;

}

void inserisci(Node **t, char *info, int num){

	if((*t)==NULL) *t=crea(num,info);
	else if(strcmp((*t)->info, info) > 0) inserisci(&(*t)->left, info, num);
	     else inserisci(&(*t)->right, info, num);

	return;

}

void minimo(Node *t, int *a){

	if(t!=NULL){
		if(t->num < *a)
			*a=t->num;
		minimo(t->left, a);
		minimo(t->right, a);
	}
}

void cerca(Node *t, char *str, int *a){

    	if(t == NULL) return;
    	if(!strcmp(t->info, str)) {
        	minimo(t, &(*a));
        	return;
    	}
    	else if(strcmp(t->info, str) > 0)
        	cerca(t->left, str, a);
    	else cerca(t->right, str, a);
}









