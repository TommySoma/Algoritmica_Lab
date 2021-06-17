#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define MAXSIZE (1001)
 
char* product(char *str, int k){ 
  
    	int i;   
    	int len=strlen(str);    
    	int plen=len*k+1;   
    	char *prod=malloc(plen*sizeof(char));   
    	for(i=0; i<plen-1; i++){     
        	prod[i]= str[ i%len ];  
     	}   
      	prod[plen-1] = '\0';   
      	
      	return prod; 
    
}

int main(void){
   
    	char str[MAXSIZE], *prod;   
    	int k;   
    	scanf("%s", str);   
    	scanf("%d", &k);   
    	prod=product(str, k);   
    	printf("%s\n", prod);
    	   
    	return 0; 
    
} 
