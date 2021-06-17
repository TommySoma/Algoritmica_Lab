#include <stdio.h>

int main(){
    
	int n;
    	int somma=0;
    	int trovato=0;
    	while(!trovato){
        	scanf("%d\n", &n);
        	if(n>0)somma=somma+n;
        	else trovato=1;
    	}
    	printf("%d",somma);
    
    	return 0;
    	
}
