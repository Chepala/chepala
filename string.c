#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define kk 32
int main()
{
	char a[kk];
	printf("copying\n");
	strcpy(a,"sdfghj");
	int cnt,i;
	cnt=i=0;
	printf("length\n");
	while(a[i++]!='\0')
	{
		cnt++;
	}
	printf("%d",cnt);

}
