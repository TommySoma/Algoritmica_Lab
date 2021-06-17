#include <stdio.h>
#define MAX 1000000

int compare(int a[], int b[], int x, int y);
	
int main(){

	int n,m;
	int i,j;
	printf("inserisci la dimensione del primo array\n");
	scanf("%d", &n);
	int array1[MAX];
	for (int i = 0; i < n; i++){
		scanf("%d", &array1[i]);
	}
	printf("inserisci la dimensione del secondo array\n");
	scanf("%d", &m);
	int array2[MAX];
	for (int j = 0; j < m; j++){
		scanf("%d", &array2[j]);
	}
	printf("%d\n", compare(array1, array2, n, m));

	return 0;
}

int compare(int a[], int b[], int x, int y){

	int i=0;
	int j=0;
	int conta=0;
	while(i < x && j < y){
		if(a[i] > b[j]) j++;
		if(a[i] < b[j]) i++;
		if(a[i] == b[j]){
			conta++;
			i++;
			j++;
		}
	}

	return conta;
}


