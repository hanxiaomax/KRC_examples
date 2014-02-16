#include<stdio.h>
/*#define MAX 10  /*不能加分号*/
int strlen(char s[]);
main()
{
	char s[]={1,2,3,4};/*人工初始化数组，系统会自动加上结束符*/
	printf("The length of this string is %d",strlen(s));



}
int strlen(char s[])
{
	int i;
	i=0;
	while(s[i]!='\0')
		i++;
	return i;
}


