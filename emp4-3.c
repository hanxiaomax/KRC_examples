#include<stdio.h>
#define MAX 500
double atof(char s[]);
main()
{
	double sum,atof(char s[]);
	char line[MAX];
	int Getline(char s[],int lim);
	sum=0;
	while(Getline(line,MAX)>0)
	{	
		printf("---------------\n");
		printf("\t%g\n",sum+=atof(line));
	}
	return 0;
}

double atof(char s[])
{
	int i,sign;
	double val,power;
	for(i=0;isspace(s[i]);i++)
		;
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-')
		i++;
	for(val=0.0;isdigit(s[i]);i++)
		val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power=1.0;isdigit(s[i]);i++)
	{
		val=10.0*val+(s[i]-'0');
		power*=10;
	}
	return sign*val/power;
}

int Getline(char s[],int lim)
{
	int c,i;
	i=0;
	while(lim-->0&&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}
