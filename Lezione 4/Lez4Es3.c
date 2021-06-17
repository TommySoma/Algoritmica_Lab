#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int InsertionSort(char **a[], int x);

int main(){

	int i, x;
	scanf("%d",&x);
	char **a;
	a=(char **)malloc(x*sizeof(char *));
	for(i=0;i<x;i++){
		a[i]=(char *)malloc(101*sizeof(char));
		scanf("%s",a[i]);
	}
	InsertionSort(a,x);

	return 0;

}


int InsertionSort(char **a[], int x){

	int j, i;
	char *temp;
	for(i=1;i<x;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && (strcmp(a[j],temp)>0)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	for(i=0;i<x;i++)
		printf("%s\n",a[i]);
}
