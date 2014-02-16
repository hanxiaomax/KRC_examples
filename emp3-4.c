#include<stdio.h>
void shellsort(int v[],int n);
main()

{}

void shellsort(int v[],int n)
{
	int gap;/*被比较元素间的距离*/
	int i,j;
	int temp;/*临时储存容器*/
	for(gap=n/2;gap>0;gap/=2)
		for(i=gap;i<n;i++)
			for(j=i-gap;j>=0&&v[j]>v[j+gap];j-=gap)
			{
				temp=v[j];
				v[j]=v[j+gap];
				v[j+gap]=temp;
			}
}
