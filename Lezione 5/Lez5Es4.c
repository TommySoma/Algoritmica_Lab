#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int distribuzione(int a[], int sx, int px, int dx);
void scambio(int* a, int* b);
void quicksort( int a[], int sx, int dx );
int legge(int **a, int *len);

int main(){
  
  	int i, n, *A;
  	if(legge(&A, &n)) return 1;
	srand(time(NULL));
  	quicksort(A, 0, n-1);
  	/* Stampa l'array ordinato */
  	for(i = 0; i < n; i++) 
   		printf("%d ", A[i]);
   	printf("\n");
	
  	return 0;
}

int distribuzione(int a[], int sx, int px, int dx){ 

	int j;
	int x = a[dx];
	int i = sx-1;
	int y = i;
	for(j = sx; j <= dx-1; j++)
		if(a[j] < x){
		i++;
		y = i;
		scambio(&a[i], &a[j]);
		}
		else if(a[j] == x){
			y++;
			scambio(&a[y], &a[j]);
		}
	scambio(&a[i+1], &a[dx]);
	
	return i+1;
}

void scambio(int* a, int* b){

	int temp = *a;
	*a = *b;
	*b = temp;

}

void quicksort(int a[], int sx, int dx){
  
	int perno, pivot;
  	if(sx < dx){
    		pivot = dx;
    		perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] da quelli maggiori o uguali */
    		quicksort(a, sx, perno-1); /* Ordina ricorsivamente le due metà */
    		quicksort(a, perno+1, dx);
    
  	}

}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len){

  	int i;
  	scanf("%d", len);
  	if(*len <= 0) return 1;
  	*a = (int *) malloc(*len * sizeof(int));
  	if(*a == NULL) return 1;
  	for(i = 0; i < *len; i++) 
	  	scanf("%d", (*a)+i);
  
  	return 0;

}

