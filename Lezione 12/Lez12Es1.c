//grafo bipartito

#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	int *bordi;

};
typedef struct elemento grafo;

grafo* creagrafo(int n);
int dfs(grafo *e, int i, int *colore);
int bipartito(grafo *e, int n);

int main(){

	int n;
	scanf("%d", &n);
	grafo *e=creagrafo(n);
	printf("%d\n", bipartito(e, n));

	return 0;

}

//inizializza il grafo

grafo *creagrafo(int n){

	grafo *e=malloc(n*sizeof(grafo));
	int i, j;
	for(i=0; i<n; i++){
		scanf("%d", &e[i].info);
		e[i].bordi=malloc((e[i].info)*sizeof(int));
		for(j=0; j<e[i].info; j++){
			scanf("%d", &e[i].bordi[j]);
		}
	}

	return e;

}

int dfs(grafo *e, int i, int *colore){

	int y, j;
	for(j=0;j<e[i].info;j++){					//controllo i nodi adiacenti
		y=e[i].bordi[j];						// mi salvo il nodo corrente
		if(colore[y]==0){						//se non l'ho mai visitato
			colore[y]-=colore[i];				//lo metto a -1 (cioe lo visitato ma non processato(grigio))
			if(dfs(e,y,colore)==0) return 0;	//richiamo ricorsivo
		} else if(colore[i]==colore[y]) return 0;
	}
	
	return 1;

}



int bipartito(grafo *e, int n){

	int i;
	int *colore=malloc(n*sizeof(int));
	for(i=0;i<n;i++)								//inizzializzo l array colore
		colore[i]=0;
	for(i=0;i<n;i++){								//controllo che nodi ho visitato
    		if(colore[i]==0){						//se un nodo non l ho visitato
      			colore[i]=1;
      			if(dfs(e,i,colore)==0) return 0;	//controllo che non ci siano problemi
    		}
  	}

	return 1;

}
