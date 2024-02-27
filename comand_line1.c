#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[100];
int j;
void * strrev(char *p)
{
	int i;
	for(i=strlen(p)-1;i>=0;i--)
	{
		str1[j++]=p[i];
	}
	str1[j++]=32;
}

int main(int argc, char * argv[])
{
	FILE *fp;
	char str[100];
	for (int i=1; i<argc; i++)
       	strrev(argv[i]);
	printf("%s",str1);
}
