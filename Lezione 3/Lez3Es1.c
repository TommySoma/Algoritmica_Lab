#include <stdio.h>
	
int main(){

	int n,m;
	int i,j;
	printf("inserisci la dimensione del primo array\n");
	scanf("%d", &n);
	int array1[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &array1[i]);
	}
	printf("inserisci la dimensione del secondo array\n");
	scanf("%d", &m);
	int array2[m];
	for (int j = 0; j < m; j++){
		scanf("%d", &array2[j]);
	}
	int conta=0;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(array1[i]==array2[j]) conta=conta+1;
		}
	}
	printf("%d\n", conta);

	return 0;
}


