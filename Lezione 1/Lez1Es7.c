#include <stdio.h>

int tswap(int *x, int *y, int *z);

int main(){

	int x,y,z;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	tswap(&x, &y, &z);
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", z);

	return 0;
}

int tswap(int *x, int *y, int *z){

	int temp1;
	int temp2;
	temp1=*x;
	temp2=*z;
	*x=temp2;
	temp2=*y;
	*y=temp1;
	*z=temp2;

}
