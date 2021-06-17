#include <stdio.h>

int main(){

	int a;
	int b;
	scanf("%d", &a);
	scanf("%d", &b);
	swap(&a,&b);
	printf("%d\n", a);
	printf("%d\n", b);

	return 0;
}

int swap(int *a, int *b){

	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}
