#include <stdio.h> 
#define N (10) 

void minmax(int a[], int len, int *min, int *max){

    	int i; 
    	*min=0; // minimo in posizione 0 
    	*max=0; // massimo in posizione 0
    	for (i=0; i<len; i++){ 
        	if (a[i] < a[*min]) *min = i;    
        	if (a[i] > a[*max]) *max = i;   
    	}
}

int main(void){ 

    	int i = 0, min, max; 
    	int array[N]; 
    	for (i = 0; i < N; i++){ 
        	scanf("%d",&array[i]); 
        
    	} 
    	minmax(array, N, &min, &max); 
    	printf("%d\n",min); 
    	printf("%d\n",array[min]); 
    	printf("%d\n",max); 
    	printf("%d\n",array[max]); 
    
    	return 0;
    	
}    
