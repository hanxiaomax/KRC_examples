#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
int getop(char s[]);
void push(double);
double pop(void);
/*注意输入的时候，需要用空格作为间断*/
main()
{
	int type;
	double temp; /*储存弹出的临时数据*/
	char s[MAXOP];
	printf("----------RPN calculator----------\n");
	printf("*      use ctrl+z to exit        *\n");
	printf("*      use space to split        *\n");
	printf("----------------------------------\n");
	printf("please input:");
	
	while((type=getop(s))!=EOF)
	{
		switch (type)
		{
			case NUMBER:/*不需要case0-9，因为数据是存储在s中的，只要返回一个标志，表示数据存储完毕即可push*/
				push(atof(s));/*调用atof(s)，把s数组里面的数，转换为f*/
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':/*注意顺序*/
				temp=pop();
				push(pop()-temp);
				break;
			case '/':/*注意顺序和分母不为0*/
				temp=pop();
				if(temp!=0.0)
					push(pop()/temp);
				else
					printf("error:zero divisor\n");
				break;
			case '\n':
				printf("result:\t%.8g\n",pop());
				break;
			default:
				printf("error:unknown command %s\n",s);
				break;
		}
	}
	return 0;
}



int sp=0;/*下一个空闲位置*/
double val[MAXVAL];/*push和pop函数公用的栈*/
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack overflow,can not push %g\n",f);
}

double pop(void)
{
	if(sp>0)
		return val[--sp];
	else
	{
		printf("stack empty\n");
		return 0.0;
	}

}

int getch(void);
void ungetch(int);
/*从键盘收集字符c，并收集数据到s中，或直接返回运算符或其他符*/
int getop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' '||c=='\t')/*从缓冲区或键盘读一个c，如果是空格，制表，不做任何动作，继续循环，但是都放在s[0]当中*/
		;
	s[1]='\0';
	if(!isdigit(c)&&c!='.')/*当不是空格和制表符时，进行判断，是否是数或者小数点*/
		return c;/*c不是数，直接返回，到mian中处理。*/
	i=0;
	if(isdigit(c))/*如果是数*/
		while(isdigit(s[++i]=c=getch()))/*此时还没遇到小数点，收集整数部分,当不是数时跳出*/
			;
	if(c=='.')/*跳出后如果是小数点*/
		while(isdigit(s[++i]=c=getch()))/*收集小数部分，直到不是数跳出，且此时已经读取了下一个c*/
			;
	s[i]='\0';/*数收集完毕后，为数组s添加结束符*/
	if(c!=EOF)/*跳出后，如果c不是文件结束符*/
		ungetch(c);/*把c放到缓冲区里面，此次getop(s)结束，c下次使用*/
	return NUMBER;/*返回NUMBER，表示数据收集完毕，已经完全进入s数组*/
}

char buf[BUFSIZE];
int bufp=0;/*注意：下一个空闲位子*/
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();/*如果之前有调用过ungetch，那么此时即使只有一个字符在buf中，bufp也会指向1，所以bufp>0，但是该位置是空闲位置，没有数据，要先把bufp回退一个位，再取值*/
}

void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch error:BUF is full\n");
	else
		buf[bufp++]=c;/*第一次调用前，bufp=0，c放入buf[0],然后bufp指向下一个空闲位子bufp=1*/
}
















