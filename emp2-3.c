#include<stdio.h>
int lower(int c);
main()
{
	int c;
	while((c=getchar())!=EOF)
    	putchar(lower(c));   

}

int lower(int c)
{
	if(c<='Z'&&c>='A')
		return c+('a'-'A');
	else
		return c;
}
/*
main()
{
	int c;
	while((c=getchar())!=EOF)
	{	
		lower(c);   /*这样写是错误的，因为lower函数不是void类型，要么赋值，要么直接做参数
    	putchar(c);   
	}
}
*/
