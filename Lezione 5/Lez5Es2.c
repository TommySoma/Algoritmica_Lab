#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 100

int distribuzione(char **a, int sx, int px, int dx);
void quicksort(char **a, int sx, int dx);

int main(){
  
  	int i, n;
  	scanf("%d", &n);
  	char **a;
  	a = (char **)malloc(n*sizeof(char *));
  	for(i = 0; i < n; i++){
  		a[i] = (char *)malloc(101*sizeof(char));
  		scanf("%s", a[i]);
  	}
  	quicksort(a, 0, n-1);
  	for(i = 0; i < n; i++) 
   		printf("%s\n ", a[i]);
	
  	return 0;
  	
}

int distribuzione(char **a, int sx, int px, int dx){ 

	int j;
	int i = sx-1;
	char *x = a[px];
	char *temp;
	for(j = sx; j <= dx-1; j++)
		if(strcmp(a[j], x) <= 0){
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	temp = a[i+1];
	a[i+1] = a[dx];
	a[dx] = temp;
		
	return i+1;
	
}

void quicksort(char **a, int sx, int dx){
  
	int perno, pivot;
  	if(sx < dx){
    		pivot = dx;
    		perno = distribuzione(a, sx, pivot, dx);
    		quicksort(a, sx, perno-1);
    		quicksort(a, perno+1, dx);
    
  	}

}
