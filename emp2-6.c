#include<stdio.h>
unsigned getbit(unsigned x,int p,int n);
main()
{
}

unsigned getbit(unsigned x,int p,int n)
{
	return (x>>(p+1-n))&~(~0<<n);
}
/*
76543210
000xxx00
x>>(p+1-n)
00000xxx

~0
11111111
11111000
~(~0<<n)
00000111-----------屏蔽码

00000xxx   &  00000111  =00000xxx,而不论之前的0是什么，这里一定是0
