#include<stdio.h>
#include<ctype.h>
int atoi(char a[]);
main()
{
	char s[20];
	int num;
	printf("please input the number:");
	gets(s);/*需要输入一些空格*/
	printf("convert started.....\n");
	num=atoi(s);
	printf("convert result:%d\n",num);
}

int atoi(char a[])
{
	int i,n,sign;
	for(i=0;isspace(a[i]);i++)/*跳过前面的空白（空格+tab）*/
		;
	sign=(a[i]=='-')?-1:1;/*记录符号*/
	if(a[i]=='+'||a[i]=='-')/*跳过该符号*/
		i++;
	for(n=0;isdigit(a[i]);i++)/*开始处理整数部分*/
		n=10*n+(a[i]-'0');
	return sign*n;
}
