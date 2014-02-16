#include<stdio.h>
#include<ctype.h>
#define SIZE 10

main()
{
	int Getint(int *);/*Getint是通过指针修改array的，返回的是读入的字符*/
	int array[SIZE];/*初始化数组*/
	int i;
	for(i=0;i<SIZE;i++)
		array[i]=1;
	for(i=0;i<SIZE&&Getint(&array[i])!=EOF;i++)
		;
	for(i=0;i<SIZE;i++)/*如果这里判断条件是i<SIZE，则多余的0会打印*/
		printf("%d\n",array[i]);/*出现错误的数字是因为没有初始化*/

}

int getch(void);
void ungetch(int);

int Getint(int *pn)
{
	int c,sign;
	while(isspace(c=getch()))
		;
	if(!isdigit(c)&&c!=EOF&&c!='+'&&c!='-')
	{
		ungetch(c);/*c不是数字，压入缓冲区*/
		return 0;/*返回0，则进行逻辑判断的时候为非*/
	}
	sign=(c=='-')?-1:1;/*当遇到负号时，把sign赋值为-1*/
	if(c=='+'||c=='-')/*当遇到正负号时*/
		c=getch();/*读入下一个字符*/
	for(*pn=0;isdigit(c);c=getch())/*如果是数字，则开始给*pn赋值*/
		*pn=(*pn)*10+(c-'0');/*把连续的数字字符组成int*/
	*pn *=sign;
	if(c!=EOF)
		ungetch(c);
	return c;
}
#define BUFSIZE 10
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("error:buf is full\n");
	else
		buf[bufp++]=c;
}










