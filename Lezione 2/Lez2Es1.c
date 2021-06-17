#include <stdio.h>

int* FindVal(int a[], int len, int val);


int main(){

	int a[10];
	int i;
	int *p;
	int len=10;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	int val;
	scanf("%d",&val);
	p=FindVal(&a,len,val);
	if(p!=NULL) printf("trovato\n");
	else printf("non trovato\n");

	return 0;

}


int* FindVal(int a[], int len, int val){

	int i=0;
	int trovato=0;
	while(i<10){
		if(val==a[i]) return a[i];
		else i++;
	}
	if(!trovato) return NULL;

}
