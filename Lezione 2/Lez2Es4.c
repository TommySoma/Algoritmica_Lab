#include <stdio.h>

int exist(char c,char s[]){

	int i,found;
	found=0;
	for(i=0;s[i]!='\0';i++) if (c==s[i]) found=1;
	return found;
}

int anagramma(unsigned char *s1, unsigned char *s2){

	int i;
	for(i=0;s1[i]!='\0';i++){
		if(exist(s1[i],s2)==0) return 0;
 	}
 	return 1;
}

int main(){

	char stringa1[1000],stringa2[1000];
	scanf("%s",stringa1);
	scanf("%s",stringa2);
	printf("%d",anagramma(stringa1,stringa2));
	return 0;
}
