#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char* my_strcat(char *s1, char *s2);

int main(){

	char s1[N], s2[N];
	scanf("%s",s1);
	scanf("%s",s2);
	my_strcat(s1,s2);
	printf("%s\n",s1);

	return 0;

}


char* my_strcat(char *s1, char *s2){

	int dim_s1=strlen(s1);
	int dim_s2=strlen(s2);
	int i;
	for(i=0;i<dim_s2;i++){
		s1[dim_s1]=s2[i];
		dim_s1++;
	}
	s1[dim_s1]='\0';

	return s1;

}
