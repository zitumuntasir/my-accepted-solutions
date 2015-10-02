#include<stdio.h>
#include<algorithm>
using namespace std;
long ara[100000];
long mid,med,sum,i,j,k,n,m,mx,mx1,res,high,low,test,cnt,cas=0,y;
void gdc(long med)
{
	mx1=-1;
	sum=0;
	cnt=0;
	for(k=0;k<n;k++)
	{
		y=0;
		sum=0;
		sum+=ara[k];
		while(sum<=med&&k<n)
		{
			y=1;
			k++;
			sum+=ara[k];
		}
		cnt++;
		if(sum>med&&y)
		{
			sum-=ara[k];
			k--;
		}
		  if(sum>mx1)
		  {
			mx1=sum;
		  }
	}
}
int main()
{
	scanf("%ld",&test);
	while(test--)
	{
		mx=-1;
		scanf("%ld%ld",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&ara[i]);
			if(ara[i]>mx)
			{
				mx=ara[i];
			}
		}
		if(m>=n)
		{
			printf("Case %ld: %ld\n",++cas,mx);
		}
		else
		{
			low=1;
			res=1000000000;
			high=1000000000;
			while(low<=high)
			{
				mid=(low+high)/2;
				gdc(mid);
				if(cnt<m)
				{
					high=mid-1;
				}
				else if(cnt==m)
				{
					high=mid-1;
					if(mx1<res)
					{
						res=mx1;
					}
				}
				else
				{
					low=mid+1;
				}
			}
			printf("Case %ld: %ld\n",++cas,res);
		}
		
	}

	return 0;
}