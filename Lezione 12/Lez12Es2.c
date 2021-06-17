//grafo connesso

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	int *next;

};
typedef struct elemento grafo;


grafo *creagrafo(int n);
int connesso(grafo *a, int n);
void DFS(grafo *a, int cerc, int **c);


int main(){

	int n;
	scanf("%d",&n);
	grafo *a=creagrafo(n);
	printf("%d\n",connesso(a,n));

	return 0;

}

grafo *creagrafo(int n){

	int i, j;
	grafo *a=(grafo *)malloc(n*sizeof(grafo));
	for(i=0;i<n;i++){
		scanf("%d",&a[i].info);
			if(a[i].info!=0){
			a[i].next=malloc(a[i].info*sizeof(int));
			for(j=0;j<a[i].info;j++)
				scanf("%d",&a[i].next[j]);
		} else a[i].next=NULL;
	}

	return a;

}

int connesso(grafo *a, int n){

	int i;	
	int *c=malloc(n*sizeof(int));		//creo array colori
	for(i=0;i<n;i++)			//lo inizializzo tutto a 0
		c[i]=0;
	DFS(a,0,&c);				//richiamo la dfs partendo dal primo nodo per vedere se e connesso
	i=0;
	while(i<n){
		if(c[i]!=0) i++;		//controllo array colori, se tutti 1 visitato tutto
		else return 0;			//se trovo uno 0 vuol dire che il grafo non e connesso
	}

	return 1;

}

void DFS(grafo *a, int cerc, int **c){

	int i, corr;
	for(i=0;i<a[cerc].info;i++){		//cerco nei nodi adiacenti
		corr=a[cerc].next[i];
		if((*c)[corr]==0){		//se non l'ho mai visitato lo visito
			(*c)[corr]=1;
			DFS(a,corr,&(*c));	//richiamo ricorsivamente
		}
	}

}
