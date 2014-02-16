#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int Getline(char *line,int lim);
/*打印与第一个参数指定模式匹配的行，即argv[1]来指定要查找的模式*/
/*支持带-号的可选参数*/
/*-x:打印不含模式的行*/
/*-n:打印行号*/
int main(int argc,char *argv[])/* argc:参数计数，指针数组*argv[]：储存参数*/
{
	char line[MAXLINE];
	long lineno=0;/*行数*/
	int c;
	int found=0;
	int except=0;/*-x功能开关*/
	int number=0;/*-n功能开关*/
	while(--argc>0&&(*++argv)[0]=='-')/*取指针数组的第一个元素看是否为-*/
/*argc自减，若大于0表示还有参数没有处理，同时处理该参数并指向下一个参数*/
		while(c=*++argv[0])/*满足条件，开始处理可选参数，读入-后面字符*/
			switch (c)
			{
				case 'x':
					except=1;
					break;
				case 'n':
					number=1;
					break;
				default:
					printf("find:illegal option %c\n",c);
					argc=0;
					found=-1;
					break;
			}
	if(argc!=1)/*如果参数处理完成后。argc不等于1（正常应该是1，即程序名）*/
		{
			printf("usage:find -x -n pattern\n");
			printf("--------------------------------------\n");
			printf("*        -x:打印不含模式的行         *\n");
			printf("*        -n:打印行号                 *\n");
			printf("--------------------------------------\n");
		}
	else/*argc=1，运行程序*/
		while(Getline(line,MAXLINE)>0)
		{
			lineno++;/*每读一行，行数+1*/
			if((strstr(line,*argv)!=NULL)^except)/*出现模式。选择-x时except=1，无-x时excpet=0，可以用异或或者!=操作，不能用且*/

			{
				if(number)/*需要打印行数*/
					printf("No.%ld",lineno);
				printf("%s",line);
				found++;
			}
		}
	return found;
	
}
/*strstr(s,t)返回一个指针，指向t在s中出现的第一个位置的地址*/


int Getline(char *line,int lim)
{
	int c;
	char *b=line;
	while(lim--&&(c=getchar())!=EOF&&c!='\n')
		*line++=c;
	if(c=='\n')
		*line++=c;
	*line='\0';
	return line-b;/*注意要返回长度*/

}
/*
if((strstr(line,*argv)!=NULL)!=except) 只能是!=except不能用且

(strstr(line,*argv)!=NULL)是一个判断，返回0或1，如果是1，except=1的时候，则相等，总的结果是0，不进行。
如果except=0，则不等，总的结果是1，进行操作

而如果是用&&，if((strstr(line,*argv)!=NULL)&&!except)
则在0&&1时不能输出，而0&&1也就是except=1+不存在，是需要输出的情况

*/





