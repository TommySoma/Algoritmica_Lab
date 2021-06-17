#include <stdio.h>
#define N 1000000

void InsertionSort(int a[], int x);

int main(){

	int i, x;
	scanf("%d", &x);
	int a[N];
	for (i = 0; i < x; i++){
		scanf("%d", &a[i]);
	}
	InsertionSort(a, x);

	return 0;
}

void InsertionSort(int a[], int x){

	int i, j, temp;
	for(i = 0; i < x; i++){
		temp = a[i];
		j=i-1;
		while(j >= 0 && a[j] > temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
	for(i = 0; i < x; i++)
		printf("%d\n", a[i]);
	
}
