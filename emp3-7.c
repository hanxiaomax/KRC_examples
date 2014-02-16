#include<stdio.h>
#include<string.h>
int trim(char s[]);
main()
{
	char s[20];
	int n;
	printf("input:");
	gets(s);
	n=trim(s);
	printf("result:%s\n",s);
	printf("the legth is:%d\n",n);


}
int trim(char s[])
{
	int n;
	for(n=strlen(s)-1;n>=0;n--)
		if(s[n]!=' '&&s[n]!='\t'&&s[n]!='\n')
			break;
	s[n+1]='\0';
	return n+1;
}
