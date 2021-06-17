#include <stdio.h> 

int odd_sum(int i){
 
    	if(i<=0) 
    		return 0; 
    	return (i*2-1)+odd_sum(i-1); 
    
} 

int main(void){
 
    	int number, res; 
    	scanf("%d", &number); 
    	res = odd_sum(number); 
    	printf("%d\n",res); 
    	
    	return 0; 
    
}
