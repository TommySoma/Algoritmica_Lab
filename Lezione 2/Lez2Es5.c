#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char* my_strcat1(char *s1, char *s2);

int main()

{	char s1[N], s2[N], *s4;
	scanf("%s",s1);
	scanf("%s",s2);
	s4=my_strcat1(s1,s2);
	printf("%s\n",s4);

	return 0;


}


char* my_strcat1(char *s1, char *s2)

{	int dim_s1=strlen(s1);
	int dim_s2=strlen(s2);
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
