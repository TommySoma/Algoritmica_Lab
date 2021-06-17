#include <stdio.h>
#define N 1000000

void SelectionSort(int a[], int len);

int main(){

	int i, x;
	scanf("%d", &x);
	int a[N];
	for (i = 0; i < x; i++){
		scanf("%d", &a[i]);
	}
	SelectionSort(a, x);

	return 0;
}

void SelectionSort(int a[], int x){

	int i, j, min, temp;
	for(i = 0; i < x-1; i++){
		min=i;
		for(j = i+1; j < x; j++){
			if(a[j] < a[min])
				min=j;
		}
		if(min!=i){
			temp = a[i]; //trovo l'elemento più piccolo dell'array e lo scambio con l'elemento alla posizione i
			a[i] = a[min];
			a[min] = temp;
		}
	}
	for( i = 0; i < x; i++){
		printf("%d\n", a[i]);
	}	
}
