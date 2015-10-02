#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
long ara[1000],ara1[1000];
int main()
{
	long a,b,c,i,N,num,r,p=0,Y,q,s;
	while(scanf("%ld",&num)&&num!=0)
	{
		N=0,r=200,p=0,Y=0;
		for(i=0;i<num;i++)
		{
			scanf("%ld",&ara[i]);
		}
		sort(ara,ara+num);
		for(i=0;i<num-1;i++)
		{
			p=ara[i+1]-ara[i];
			r=p+r;
			if(p>200)
			{
				N=1;
			}
		}
		q=r-1422;
		s=1422-(r-200);
		if(q>=s)
			Y=1;
		if(N==0&&r>=1422&&Y==1)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
			
	}
	return 0;
}