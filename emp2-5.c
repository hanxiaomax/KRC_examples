#include<stdio.h>
#define MAX 40
void Strcat(char s[],char t[]);/*s大写，避免和built-in函数冲突*/
main()
{
	char a[MAX],b[MAX];
	printf("string a is :");
	scanf("%s",a);
	printf("string b is :");
	scanf("%s",b);
	printf("\n");
	Strcat(a,b);
	printf("the string ab is: %s\n",a);
	
}
void Strcat(char s[],char t[])
{
	int i,j;
	i=j=0;
	while(s[i]!='\0')
		i++;
	while((s[i]=t[j])!=0)
	{
		i++;
		j++;
	}
}

/*简单的写法*/
/*
void Strcat(char s[],char t[])
{
	int i,j;
	i=j=0;
	while(s[i]!='\0')    /*不能写成s[i++]否则会从1开始
		i++;
	while((s[i++]=t[j++])!='\0');
}






