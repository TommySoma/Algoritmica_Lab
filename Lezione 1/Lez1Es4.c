#include <stdio.h> 
#define MAXSIZE (10000)

int main(){   

	int n, i, j, scambio;  
    	int a[MAXSIZE]; 
    	scanf("%d", &n );
    	for(i=0; i<n; i++)    
    		scanf("%d", &a[i]); 
         /* Inversione in loco */  
     	for (i=0; i<n/2; i++) {        
         	j=(n-1)-i;    
         	scambio = a[i];    
         	a[i] = a[j];    
         	a[j] = scambio;            
    	}     
      	/* Output */  
      	for ( i = 0; i < n; i++ )   
      		printf("%d\n", a[i]);  
      	printf("\n");  
      	
      	return 0; 
    
}  
