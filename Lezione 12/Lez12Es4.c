//grafo: diametro(percorso più lungo)

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
int bfs(grafo *a, int inizio, int n);
int diametro(grafo *a, int n);


int main(){

	int n;
	scanf("%d",&n);
	grafo *a=creagrafo(n);
	printf("%d\n",diametro(a,n));
	
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


void accoda(queue *q, int inizio){	//metto l elemento in coda

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


int bfs(grafo *a, int inizio, int n){

	int *colori=malloc(n*sizeof(int));
	int *distanza=malloc(n*sizeof(int));
	int i, u, v;
	int distmax=0;
	queue q;
	for(i=0;i<n;i++){
		colori[i]=0;
		distanza[i]=-1;
	}
	iniz(&q,n);	//inizializza la coda
	accoda(&q,inizio);	//inserisce elemento alla coda
	colori[inizio]=1;
	distanza[inizio]=0;
	while(!codavuota(&q)){		//finchè la coda non è vuota
		u=decoda(&q);		//esamino elementi successivi nella coda
		for(i=0;i<a[u].info;i++){	//esamino la lista di adiacenza del nodo
			v=a[u].next[i];	//tengo conto del valore
			if(colori[v]==0){	//se non ho mai esaminato quel valore
				distanza[v]=distanza[u]+1;
				colori[v]=1;
				accoda(&q,v);		//altrimenti lo metto in coda
			}
		}
	}
	deiniz(&q);		//elimino la coda
	for(i=0;i<n;i++){
		if(!colori[i]) return -1;	//se non ho visitato tutti i nodi ritorno -1
		if(distanza[i] > distmax) distmax=distanza[i];	//se trova la distanza piu lunga la salvo
	}
	
	return distmax;	//ritorno la max distanza
	
}


int diametro(grafo *a, int n){ 	//lancio la bfs da ogni nodo per vedere qual è il cammino minimo piu lungo
  	
  	int i;
  	int diametro=-1;
  	for(i=0;i<n;i++){
    		int tmp=bfs(a,i,n);
    		if(tmp == -1) return -1;  	//se ho trovato un problema ritorno -1
    		if(tmp > diametro) diametro=tmp;	//mi salvo il massimo valore che corrisponde al diametro
  	}
  
  	return diametro;	//ritorno il diametro

}





