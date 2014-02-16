#include<stdio.h>
#include<string.h>
#include<stddef.h>

#define MAXLINE 1000/*能处理的最大行数*/
char *lineptr[MAXLINE];/*指向文本行的指针*/
int readlines(char *lineptr[],int maxlines);
void writelines(char *lineptr[],int nlines);
void qsort(char *lineptr[],int left,int right,int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc,char *argv[])
{
	int nlines;/*输入行的数目*/
	int numeric=0;

	if(argc>1&&strcmp(argv[1],"-n")==0)
		numeric=1;
	if((nlines=readlines(lineptr,MAXLINE))>=0)
	{
		qsort((void **)lineptr,0,nlines-1,
(int (*)(void *,void *))(numeric?numcmp:strcmp));/*调用qsort对该指针数组排序*/
		writelines(lineptr,nlines);
		return 0;
	}
	else/*nline<0,即readlines返回-1*/
	{
		printf("error:input too big to sort!\n");
		return 1;
	}
}

#define MAXLEN 100 /*每行最大长度*/
int Getline(char *,int lim);
char *alloc(int);
/*输入函数：读取每行的字符，创建指针数组保存每行的指针，返回行数*/
int readlines(char *lineptr[],int maxlines)
{
	int len;/*各行的长度*/
	int nlines=0;/*行数*/
	char *p;
	char line[MAXLEN];
	while((len=Getline(line,MAXLEN))>0)
	{
		if(nlines>=maxlines||(p=alloc(len))==NULL)
			return -1;/*如果行数超出，或....返回-1*/
		else
		{
			line[len-1]='\0';/*删除换行符*/
			strcpy(p,line);/*复制line，首地址保存在p，返回指针p*/
			lineptr[nlines++]=p;/*把指针p存放进指针数组*/
		}
	}
	return nlines;/*返回行数，即指针数组的元素序数+1*/
}
	
	

/*打印函数*/
void writelines(char *lineptr[],int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",lineptr[i]);/*循环打印所有指针*/
}	

/*排序函数*/
void qsort(char *v[],int left,int right,int (*comp)(void *,void*))
{
	int i,last;
	void swap(void *v[],int i,int j);
	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if(strcmp(v[i],v[left])<0)
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1,comp);
	qsort(v,last+1,right,comp);
}
#include<stdlib.h>
int numeric(char *s1,char *s2)
{
	float v1,v2;
	v1=atof(s1);
	v2=atof(s2);
	if(v1<v2)
		return -1;
	else if(v1>v2)
		return 1;
	else
		return 0;
}
void swap(void *v[],int i,int j)/*指针声明为void类型*/
{
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

int Getline(char s[],int lim)
{
	int c;
	int i=0;
	while(lim--&&(c=getchar())!=EOF&&c!='\n')
		s[i++]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}
#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;/*指向lineptr首地址的指针*/
char *alloc(int n)/*负责分配空间*/
{
	if(allocbuf+ALLOCSIZE-allocp>=n)
	{
		allocp+=n;
		return allocp-n;
	}
	else
		return 0;
}


















