#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int Getline(char *line,int lim);
/*打印与第一个参数指定模式匹配的行，即argv[1]来指定要查找的模式*/
int main(int argc,char *argv[])
{
	char line[MAXLINE];
	int found=0;
	if(argc!=2)
		printf("usage:find pattern\n");
	else
		while(Getline(line,MAXLINE)>0)
			if(strstr(line,argv[1])!=NULL)/*argv[1]，在line中出现*/
			{
				printf("%s\n",line);
				found++;
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


