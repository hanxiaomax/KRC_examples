#include<stdio.h>
#define MAX 1000
int Gettext(char text[],char s[][MAX]);
int strindex(char s[],char t[]);

main()
{
	char text[MAX]={" i would like to ask you.\n if you will go with me.\n could i?\n yes!\n but you should make it quick!\n because i will leave.\n"};
	char pattern[MAX];
	int found=0;
	char s[MAX][MAX];
	int i,j,num_of_line,t;
	t=0;

	num_of_line=Gettext(text,s);/*是否可以不赋值？*/

	printf("-------The Text is--------\n");
	for(i=0;i<num_of_line;i++)
		for(j=0;s[i][j]!='\0';j++)
			printf("%c",s[i][j]);
	printf("...........................\n");
	printf("there are %d lines\n",num_of_line);
	printf("...........................\n");
	printf("please input the string that u wanna search:\n");
	gets(pattern);
	printf("........................\n");
	while(t<num_of_line)
	{
		if(strindex(s[t],pattern)>0)/*注意此处二维数组做参数*/
		printf("%s",s[t]);
		t++;
	}
	printf("...........EXIT.............\n");
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


int Gettext(char text[],char s[][MAX])
{
	int i=0;
	int c;
	int j=0;
	int t=0;
	while((c=text[j++])!='\0')
	{
		if(c!='\n')
			s[t][i++]=c;
		else
		{
			s[t][i++]=c;
			s[t][i]='\0';
			t++;
			i=0;
		}
	}
	return t;/*返回行数*/
}


/*首个字母不能正确处理*/
