#include <stdio.h>
#include <stdlib.h>
#define N 10000

int ord_cres(int *a, int *b);
int ord_pp(int *a, int *b);

int main(){

	int x, i;
	scanf("%d",&x);
	int a[N];
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	qsort(a,x,sizeof(int),ord_cres);
	qsort(a,x,sizeof(int),ord_pp);
	for(i=0;i<x;i++)
		printf("%d\n",a[i]);

	return 0;

}	


int ord_cres(int *a, int *b){

	return(*a-*b);

}

int ord_pp(int *a, int *b){

	if(*a%2==0 && *b%2!=0)
		return -1;
	if(*a%2!=0 && *b%2==0)
		return 1;
	if(*a%2==0 && *b%2==0)
		return 0;
	if(*a%2!=0 && *b%2!=0)
		return 1;

}
