#include<stdio.h>
#define ALLCOSIZE 1000
char *allco(int n);/**/
void afree(char *p);/**/
int main()
{}

static char allocbuf[ALLCOSIZE];
static char *allocp=allocbuf;

char *allco(int n)
{
	if(allocbuf+ALLCOSIZE-allocp>=n)
	{
		allocp+=n;
		return allocp-n;
	}
	else
		return 0;
}

void afree(char *p)
{
	if(p>=allocbuf&&p<allocbuf+ALLCOSIZE)
		allcop=p;
}

