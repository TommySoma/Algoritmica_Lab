#include <stdio.h>

void reset (int array[], int len);
void add(int array[], int len, int val);

int main(){

	int a[100];
	int b[10];
	int len=0;
	int x;
	int i=0;
	int trovato=0;
	reset(b,10);
	while(!trovato){
		scanf("%d",&x);
		if(x>=0){
			a[i]=x;			
			i++;
			len++;
		} else trovato=1;
	}
	for(i=0;i<len;i++)
		add(b,len,a[i]);
	for(i=0;i<10;i++)
		printf("%d\n",b[i]);


	return 0;

}


void reset(int array[], int len){
	
	int i;
	for(i=0;i<len;i++)
		array[i]=0;

}

void add(int array[], int len, int val){

	array[val]+=1;

}
