#include<stdio.h>
void Reverse(char s[]);
void itoa(int n,char s[]);
main()
{
	int n;
	char s[20],a[20];
	printf("input: \n");
	//gets(a);
	//Reverse(a);
	scanf("%d",&n);
	itoa(n,s);
	printf("%s\n",s);
	//printf("%s\n",a);
}

void itoa(int n,char s[])
{
	int i=0;/*如果不给定初值就会出现段错误*/
	int sign;
	if((sign=n)<0)/*如果n是负数*/
		n=-n;/*反号用正数运算*/
	do
	{
		s[i++]=n%10+'0';  /*数字变字符加，字符变数字减*/
	}
	while((n/=10)>0);/*do-while:注意分号位置*/
	
	if(sign<0)
		s[i++]='-';/*重新添加负号*/
	s[i]='\0';/*仍然是在最后添加结束符，不需要在最前添加*/
	Reverse(s);/*Reverse函数并不会把结束符也倒序到前面*/
	
	
}
void Reverse(char s[])
{
	int i,j;
	int temp;
	i=j=0;
	while(s[i]!='\0')
		i++;
	--i;
	if(s[i]=='\n')
		i--;
	while(j<i)
	{
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		i--;
		j++;
	}
}
/*
321-





*/
