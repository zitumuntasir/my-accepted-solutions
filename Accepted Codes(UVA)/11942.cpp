#include<stdio.h>
#include<iostream>
#include<algorithm>
long ara[10000],ara1[10000],ara2[100000];
using namespace std;
int main()
{
	long a,b,c,d,e,i,j,k,num,sum1,sum2,l;
	scanf("%ld",&num);
	for(i=0;i<num;i++)
	{
		sum1=0,sum2=0;
		for(j=0;j<10;j++)
		{
			scanf("%ld",&ara[j]);
			ara1[j]=ara[j];
		}
		sort(ara,ara+10);
		for(k=0;k<10;k++)
		{
			if(ara1[k]==ara[k])
			{
				sum1++;
			}
		}
			for(k=0,l=9;k<10,l>=0;k++,l--)
		{
			if(ara1[l]==ara[k])
			{
				sum2++;
			}
		}
			if(i==0)
			printf("Lumberjacks:\n");
			if(sum1==10||sum2==10)
				printf("Ordered\n");
			else
				printf("Unordered\n");
	}
	return 0;
}
