#include<stdio.h>
#define MAX 10
void squeeze(char s[],int c);
main()
{
	char c;
	char strings[MAX];
	printf("the word and the char u want to remove\n");/*scanf不能描述*/
	scanf("%s %c",strings,&c);
	squeeze(strings,c);/*没有返回值，不能直接用在printf里面作为参数*/
	printf("%s\n",strings);
}
void squeeze(char s[],int c)/*因为是空类型，所以要直接对s[]完成操作*/
{
	int i,j;
	for(i=0,j=0;s[i]!='\0';i++)/*逐个检查s中的字符*/
		if(s[i]!=c)/*如果不是c*/
			s[j++]=s[i];/*则把该字符复制到s[]中，然后将j下标+1*/
		s[j]='\0';
}
