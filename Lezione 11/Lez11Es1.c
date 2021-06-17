#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;

struct solution{

  	int min;
  	int path;

};
typedef struct solution solution;

void insert(Node **t, int n);
solution minMaxPath (Node *t);

void main(){

  	int n, i, el;
  	Node *tr=NULL;
  	scanf("%d", &n);
  	for (i=0;i<n;i++){
    		scanf("%d", &el);
    		insert(&tr, el);
  	}
  	printf("%d\n",minMaxPath(tr).min);

}

void insert(Node **t, int n){

    if(*t==NULL){
    	Node *new=malloc(sizeof(Node));
    	new->info=n;
    	new->left=NULL;
    	new->right=NULL;
    	*t=new;

    	return;
  	}
  	if(n < (*t)->info)
    	insert(&(*t)->left, n);
  	else
    	insert (&(*t)->right, n);

}

solution minMaxPath (Node *t){

  	if(t==NULL){
    		solution res;
    		res.min=0;
    		res.path=0;
    		return res;
  	}
  	if(t->left==NULL && t->right==NULL){
    		solution leaf;
    		leaf.min= t->info;
    		leaf.path= t->info;
    		return leaf;
  	}
  	solution sx= minMaxPath(t->left);
  	solution dx= minMaxPath(t->right);
  	// scelgo il cammino maggiore
  	solution max;
  	if(sx.path > dx.path)
    		max=sx;
  	else if (sx.path < dx.path)
    			max=dx;
  		else if (sx.min < dx.min)
    			max=sx;
  			else
    				max=dx;
  	max.path=max.path + t->info;
  	if(t->info < max.min)
    		max.min=t->info;

  	return max;

}







