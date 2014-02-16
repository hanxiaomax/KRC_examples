#include<stdio.h>
#include<string.h>
void reverse(char s[]);
main()
{
	char s[10];
	printf("please input:\n");
	gets(s);
	printf("reversing...\n");
	reverse(s);
	printf("%s\n",s);
}

void reverse(char s[])
{
	int temp,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
		temp=s[i],s[i]=s[j],s[j]=temp;
}
