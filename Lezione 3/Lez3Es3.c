#include <stdio.h>

int sottoarray(int a[], int dim_a);

int main(){

	int n, i;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d\n", sottoarray(a, n));

	return 0;

}

int sottoarray(int a[], int dim_a){

	int i;
	int max=0;
	int somma=0;
	for(i=0; i<dim_a; i++){
		if(somma>0) somma=somma+a[i];
		else somma=a[i];
		if(somma>max) max=somma;
	}

	return max;

}
