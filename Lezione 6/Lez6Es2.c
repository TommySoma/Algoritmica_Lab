#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int compare(char **a, char **b);

int main(){

	int i, x;
	scanf("%d",&x);
	char **a;
	a=(char **)malloc(x*sizeof(char *));
	for(i=0;i<x;i++){
		a[i]=(char *)malloc(101*sizeof(char));
		scanf("%s",a[i]);
	}
	qsort(a, x, sizeof(char*), compare);
	for(i=0; i<x; i++)
		printf("%s\n", a[i]);

	return 0;

}


int compare(char **a, char **b){

	char **a1=(char **)a;
	char **b1=(char **)b;
	return strcmp(*a1, *b1)*(-1);
	
}
