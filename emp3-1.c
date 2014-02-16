#include<stdio.h>
int binsearch(int x,int v[],int n);

main()
{
	int x[10];
	int i;
	int n;
	int loc;
	for(i=0;i<10;i++)
	{
		x[i]=i+15;
		printf("%d ",x[i]);
	}
	printf("\n");
	printf("i want to search:");
	scanf("%d",&n);
	loc=binsearch(n,x,10);
	printf("the location of %d is %d:\n",n,loc);


}
/*数组v必须是已经排序过的*/
int binsearch(int x,int v[],int n)
{
	int low,high,mid;
	low=0;	/*数组起始索引号*/
	high=n-1;/*数组最大索引号*/
	while(low<=high)
	{
		mid=(low+high)/2;/*中间元素索引号*/
		if(x<v[mid])/*如果x小于中间元素值*/
			high=mid-1;/*把上限缩小到中间值前一个*/
		else if (x>v[mid])/*如果x大于中间值*/
			low=mid+1;/*把下限放大到中间值后一个*/
		else
			return mid+1;/*如果x就是中间值，输入索引号+1以得到位置*/
	}
	return -1;/*当没有其他返回值时，返回-1。一个函数只能有一次return*/
}
