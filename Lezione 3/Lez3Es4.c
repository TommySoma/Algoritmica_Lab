#include <stdio.h>
#include <stdlib.h>
#define N 100000


void sorted_union(int a[], int b[], int x, int y);

int main(){

	int x, y, i;
	scanf("%d",&x);
	int a[N];
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	scanf("%d",&y);
	int b[N];
	for(i=0;i<y;i++)
		scanf("%d",&b[i]);
	sorted_union(a,b,x,y);

	return 0;

}

void sorted_union(int *x, int *y, int lenx, int leny){

	int *u=(int *)malloc((lenx+leny)*sizeof(int));
	int i=0, j=0, pos=0;
	while((i<lenx) && (j<leny)){
		if(x[i]<y[j]){
		    u[pos++]=x[i++];
		}
		if(x[i]>y[j]){
		    u[pos++]=y[j++];
		} 
	}
	if(i>=lenx){
		while(j<leny){
			u[pos++] = y[j++];
		}
	} else {
		while(i<lenx){
			u[pos++] = x[i++];
		}
	}
	for(i=0;i<lenx+leny;i++)
		printf("%d\n",u[i]);
}
