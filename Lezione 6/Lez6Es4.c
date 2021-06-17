#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {

	char *a;
	int b;
};
typedef struct elemento Parole;

int compare(Parole *x, Parole *y);

int main(){

	int n, i, tot;
	char *w;
	scanf("%d",&n);
	Parole *arr;
	arr=(Parole *)malloc(n*sizeof(Parole ));
	for(i=0;i<n;i++){
		w=(char *)malloc(101*sizeof(char));
		scanf("%s",w);
		arr[i].a=w;
		tot=strlen(arr[i].a);
		arr[i].b=tot;
	}
	qsort(arr,n,sizeof(Parole),compare);
	for(i=0;i<n;i++)
		printf("%s\n",arr[i].a);

	return 0;
}


int compare(Parole *x, Parole *y){

	Parole *x1=(Parole *)x;
	Parole *y1=(Parole *)y;
	if(x1->b==y1->b) return strcmp(x1->a,y1->a);
	return ((x1)->b - (y1)->b);

}


