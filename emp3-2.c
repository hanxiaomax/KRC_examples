#include<stdio.h>
main()
{
	int nwhite,nother;
	int ndigit[10];
	int i;
	int c;
	nwhite=nother=0;
	for(i=0;i<10;i++)
		ndigit[i]=0;
	while((c=getchar())!=EOF)/*use ctrl+d to make EOF*/
		switch (c)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				ndigit[c-'0']++;
				break;
			case ' ':
			case '\n':
			case '\t':
				nwhite++;
				break;
			default:
				nother++;
				break;
		}
	for(i=0;i<10;i++)
		printf("number of digits %d is %d\n",i,ndigit[i]);

	printf("number of black is %d\n",nwhite);
	printf("number of others is %d\n",nother);

}

/*case 会顺序执行，但是一般不用*/
