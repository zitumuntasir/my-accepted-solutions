#include<stdio.h>
long ara[100010];
int main()
{
	long res,test,i,n,mx,j,cas=0,y;
	scanf("%ld",&test);
	while(test--)
	{
		mx=-10000;
		y=0;
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%ld",&ara[i]);
			if(ara[i]-ara[i-1]>mx)
			{
				mx=(ara[i]-ara[i-1]);
				j=i;
			}
		}
		res=mx;
		res--;
		for(i=j+1;i<=n;i++)
		{
			if((ara[i]-ara[i-1])==res)
			{
				res--;
			}
			else if(res<ara[i]-ara[i-1])
			{
				y=1;
			}
		}
		if(y)
		{
			printf("Case %ld: %ld\n",++cas,mx+1);
		}
		else
		{
			printf("Case %ld: %ld\n",++cas,mx);
		}
	}
	return 0;
}