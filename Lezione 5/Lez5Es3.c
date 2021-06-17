#include <stdio.h>
#include <stdlib.h>
#define N 10000

int partiziona(int a[], int sx, int dx, int px);
void quicksort(int a[], int sx, int dx);
void swap(int *a, int *b);
int compare(int *a, int *b);

int main(){

	int a[N];
	int i, x;
	scanf("%d",&x);
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,x-1);
	qsort(a,x,sizeof(int),compare);
	for(i=0;i<x;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;

}


int compare(int *a, int *b){

	if(*a%2==0 && *b%2!=0)
		return -1;
	if(*a%2!=0 && *b%2==0)
		return 1;
	if(*a%2==0 && *b%2==0)
		return 0;
	if(*a%2!=0 && *b%2!=0)
		return -1;
}

void swap(int *a, int *b){

	int temp=*a;
	*a=*b;
	*b=temp;

}

int partiziona(int a[], int sx, int dx, int px){

	int j;
  	int x=a[px];
  	int i=sx-1;
  	for(j=sx;j<=dx-1;j++)
    	if(a[j]<=x){
      	i++;
      	swap(&a[i],&a[j]);
    	}
  	swap(&a[i+1],&a[dx]);
  	return i+1;
}


void quicksort(int a[], int sx, int dx){

 	int perno, pivot;
  	if(sx<dx){
    	pivot=dx;
    	perno=partiziona(a,sx,pivot,dx);
    	quicksort(a,sx,perno-1);
    	quicksort(a,perno+1,dx);
    }
}
