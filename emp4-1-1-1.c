#include<stdio.h>
#define MAX 300
int Gettext(char text[],char s[][MAX]);

main()
{
	int i,j;
	int num_of_line;
	char s[MAX][MAX];
	char text[MAX]={"i would like to ask you.\nif you will go with me.\ncould i?\nyes!\nbut you should make it quick!\nbecause i will leave.\n"};
	num_of_line=Gettext(text,s);
	for(i=0;i<=num_of_line;i++)
		for(j=0;s[i][j]!='\0';j++)
			printf("%c",s[i][j]);

}
int Gettext(char text[],char s[][MAX])/*注意此处定义，可以解决数组参数类型不完全*/
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

