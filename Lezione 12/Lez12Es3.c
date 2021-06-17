//grafo:percoso minimo

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	int *next;

};
typedef struct elemento grafo;

struct elemento1{

	int dim;
	int testa;
	int coda;
	int *valori;
	
};
typedef struct elemento1 queue;


grafo *creagrafo(int n);
void iniz(queue *q, int n);
void accoda(queue *q, int inizio);
int codavuota(queue *q);
int decoda(queue *q);
void deiniz(queue *q);
int bfs(grafo *a, int inizio, int fine, int n);


int main(){

	int n, i, inizio, fine, m;
	scanf("%d",&n);
	grafo *a=creagrafo(n);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&inizio,&fine);
		printf("%d\n",bfs(a,inizio,fine,n));
	}
	
	return 0;
	
}
		
	
grafo *creagrafo(int n){

	int i, x, j;
	grafo *a=malloc(n*sizeof(grafo));
	for(i=0;i<n;i++){
		scanf("%d",&x);
		a[i].info=x;
		a[i].next=malloc(x*sizeof(int));
		for(j=0;j<x;j++)
			scanf("%d",&a[i].next[j]);
	}
	
	return a;
	
}


void iniz(queue *q, int n){	//inizializzo la coda

	q->dim=n;
	q->testa=0;
	q->coda=0;
	q->valori=malloc(n*sizeof(int));
	
}


void accoda(queue *q, int inizio){	//metto l'elemento in coda

	q->valori[q->coda++]=inizio;
	
}


int codavuota(queue *q){	//controllo che la coda non sia vuota

	if(q->coda==q->testa) return 1;
	else return 0;

}


int decoda(queue *q){		//elimino la testa della coda

	return q->valori[q->testa++];
	
}


void deiniz(queue *q){		//elimino la coda

	free(q->valori);
	q->dim=0;
	q->testa=0;
	q->coda=0;
	
}	


int bfs(grafo *a, int inizio, int fine, int n){

	int *colori=malloc(n*sizeof(int));
	int *distanza=malloc(n*sizeof(int));
	int i, u, v;
	queue q;
	for(i=0;i<n;i++){
		colori[i]=0;
		distanza[i]=-1;
	}
	iniz(&q,n);	//inizializza la coda
	accoda(&q,inizio);	//inserisce elemento alla coda
	colori[inizio]=1;
	distanza[inizio]=0;
	while(!codavuota(&q)){		//finche la coda non e vuota
		u=decoda(&q);		//esamini elementi successivi nella coda
		for(i=0;i<a[u].info;i++){	//esamino la lista di adiacenza del nodo
			v=a[u].next[i];	//tengo conto del valore
			if(colori[v]==0){	//se non ho mai esaminato quel valore
				colori[v]=1;
				distanza[v]=distanza[u]+1;
				if(v==fine) return distanza[v];	//se è il nodo finale finisco
				accoda(&q,v);		//altrimenti lo metto in coda
			}
		}
	}
	deiniz(&q);		//elimino la coda
	
	return distanza[fine];		//ritorno la distanza finale
	
}
