#include<stdio.h>
#include<string.h>
#define MAX 20
int bitcount(unsigned x);
int bi_input(char s[]);
void to2(int x,char s[]);
main()
{
	char a[MAX];
	int num;
	printf("please input the number:");
	scanf("%s",a);
	num=bitcount(bi_input(a));
	printf("the number of 1 is: %d\n",num);
}

int bitcount(unsigned x)
{
	int b;
	for(b=0;x!=0;x>>=1) /*只要x不为0，则将x右移1位并赋值给x*/
	{
		if(x&01)/*x和0001按位与，如果x最右边一位是1，则结果为1*/
			b++;/*计数器+1*/
	}

	return b;

}

int bi_input(char s[])
{
	int n,i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='0'||s[i]=='1')
		{
			n<<=1;
			n+=s[i]-'0';
		}
		else
			return -1;
	}
	return n;
}
/*本题不需要此函数*/
void to2(int x,char s[])
{
	int yu,shang;
	int i=0;
	shang=x;
	while(shang!=0)
	{
		yu=shang%2;
		shang/=2;
		s[0]=yu;
		i++;
	}
	s[i]='\0';
	for(i=strlen(s);i>=0;i--)
		printf("%d",s[i]);
	printf("\n");
}
		
	


















