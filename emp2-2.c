#include<stdio.h>
#define MAX 100
int atoi(char s[]);
main()
{
	char s[MAX];
	scanf("%s",s);/*此处s是一个数组，s就表示了第一个元素的地址，不需要&符号*/
	printf("the number is %d\n",atoi(s));
}

int atoi(char s[])
{
	int i,n;
	n=0;
	for(i=0;s[i]>='0'&&s[i]<='9';i++)
		n=10*n+(s[i]-'0');
/*依次把求到的n，放到更高的位上去，此处必须要减去‘0‘，否则得到的是s[i]这个字符的ASCII码，只有减去‘0’的ASCII码，得到的才是真实值*/
	return n;
}
