#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab/sizeof(struct key))
struct key
{
	char *word;
	int count;
};/*此处需要分号*/
struct key keytab[]={{"auto",0},{"break",0},{"case",0},{"char",0}};

int getword(char *,int );
int binsearch(char *,struct key *,int);

main()
{
	int n;
	char word[MAXWORD];
	while(getword(word,MAXWORD)!=EOF)
		if(isalpha(word[0]))
			if((n=binsearch(word,keytab,NKEYS))>=0)
				keytab[n].count++;
	for(n=0;n<NKEYS;n++)
		if(keytab[n].count>0)
			printf("%4d %s\n",keytab[n].count,keytab[n].word);
	return 0;
}



int binsearch(char *word,struct key keytab[],int n)
{
	int cond;
	int low,high,mid;
	low=0;/*起始*/
	high=n-1;/*末尾*/
	while(low<=high)
	{
		mid=(low+high)/2;/*中间*/
		if((cond=strcmp(word,keytab[mid].word))<0)/*比较word和该元素*/
			high=mid-1;
		else if(cond>0)
			low=mid+1;
		else
			return mid;/*返回位置*/
	}
	return -1;/*出错*/
}

int getword(char *word,int lim)
{
	int getch(void);
	int c;
	void ungetch(int);
	char *w=word;/*指向数组的指针*/
	while(isspace(c=getch()))/*跳过空白*/
		;/*while失效后多读入了一个c*/
	if(c!=EOF)/*判断这个c*/
		*w++=c;/*不是结束符的话就存放到数组中*/
	if(!isalpha(c))/*不是字母*/
	{
		*w='\0';/*添加结束符*/
		return c;/*返回c*/
	}
	for(;--lim>0;*w++)/*循环赋值*/
		if(!isalnum(*w=getch()))/*不是数字或字母*/
		{
			ungetch(*w);/*压回*w,如果是c，回出现无法结束*/
			break;/*跳出*/
		}
	*w='\0';/*添加结束符*/
	return word[0];/*返回首字母*/
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0)? buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch:too many characters\n");
	else
		buf[bufp++]=c;
}





