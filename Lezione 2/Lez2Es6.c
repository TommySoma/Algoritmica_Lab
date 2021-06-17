#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat2(int dim_s1, char *s1, int dim_s2, char *s2);

int main(){

	int dim_s1, dim_s2;
	scanf("%d", &dim_s1);
	char s1[dim_s1+1];
	scanf("%s", s1);
	scanf("%d", &dim_s2);
	char s2[dim_s2+1];
	scanf("%s", s2);
	char *s4;
	s4=my_strcat2(dim_s1, s1, dim_s2, s2);
	printf("%s\n", s4);	

	return 0;

}

char* my_strcat2(int dim_s1, char *s1, int dim_s2, char *s2){

	char *s3=(char *) malloc(sizeof(char)*(dim_s1+dim_s2+1));
	int pos=0;
	int i=0;
	for(i=0;i<dim_s1;i++)
		s3[pos++]=s1[i];
	for(i=0;i<dim_s2;i++)
		s3[pos++]=s2[i];
	s3[pos]='\0';

	return s3;

}
