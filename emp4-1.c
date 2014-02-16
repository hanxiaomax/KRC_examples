#include<stdio.h>
#define MAX 1000
int Getline(char s[],int lim);
int strindex(char s[],char t[]);
main()
{
	char pattern[MAX];
	char text[MAX];
	int found=0;
	printf("please input the string that u wanna search:\n");
	gets(pattern);
	printf("please input the text:\n.............\n");
	while(Getline(text,MAX)>0)
	{
		if(strindex(text,pattern)>=0)
		{
			printf("%s",text);
			found++;
		}
	}
	printf("\n.................\n");
	printf("we find %s in %d lines\n.................\n",pattern,found);
}

int Getline(char s[],int lim)
{
	int i=0;
	int c;
	while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}

int strindex(char s[],char t[])
{
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;s[j]==t[k]&&t[k]!='\0';j++,k++)
			;
		if(k>0&&t[k]=='\0')
			return i;
	}
	return -1;
}




/*text
i would like to ask you
if you will go with me
could i?
yes!
but you should make it quick!
because i will leave in any time

*/
