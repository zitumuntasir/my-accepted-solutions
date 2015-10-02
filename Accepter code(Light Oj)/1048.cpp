#include<stdio.h>
#include<algorithm>
using namespace std;
long ara1[100010],ara[100010];
long sum,i,j,k,l,n,num,low,high,mid,med,test,mx,cnt,mn,cas=0,y,mx1;
void keo(long med)
{
	cnt=0;
	for(j=0;j<=n;j++)
	{
		sum=ara1[j];
		l=j;
		while(sum<=med&&j<=n)
		{
			j++;
			sum+=ara1[j];
			ara1[j]=0;
			cnt++;
		}
		if((j<=n)||(j==n&&sum>med))
		{
		  ara1[j]=ara[j];
		  ara1[l]=sum-ara1[j];
		  cnt--;
		}
		else if(j>n&&sum<=med)
		{
			ara1[l]=sum;
			cnt--;
		}
		else 
		{
			ara1[l]=sum;
		}
		j--;
		if(cnt>=num) return ;
	}
}
int main()
{
	scanf("%ld",&test);
	while(test--)
	{
		mx=-1,mx1=-1;
		sum=0,cnt=0;
		mn=1000000000;
		scanf("%ld%ld",&n,&k);
		num=n-k;
		for(i=0;i<=n;i++)
		{
			scanf("%ld",&ara[i]);
			if(ara[i]>mx)
			{
				mx=ara[i];
			}
			if(ara[i]>mx1&&i<=k)
			{
				mx1=ara[i];
			}
		}
		if(num>0)
		{
		low=mx;
		high=200000000;

			while(low<=high)
			{
			  mid=(low+high)/2;
			  keo(mid);
			  if(cnt>=num)
			  {
				  if(mid<mn)
				  {
					  mn=mid;
				  }
				  high=mid-1;
			  }
			  else
			  {
				  low=mid+1;
			  }

			  for(i=0;i<=n;i++) ara1[i]=ara[i];
			}
			printf("Case %ld: %ld\n",++cas,mn);
			sum=0;
			cnt=0;
			for(i=0;i<=n;i++)
			{
				y=0;
				sum=0;
				sum+=ara[i];
				while(sum<mn&&i<=n&&cnt<num)
				{
					i++;
					y=1;
					sum+=ara[i];
					cnt++;
				}
				if(sum>mn&&i<=n&&y)
				{
					printf("%ld\n",sum-ara[i]);
					cnt--;
					i--;
				}
				else if(sum<=mn&&y)
				{
					printf("%ld\n",sum);
				}
				else printf("%ld\n",ara[i]);

			}
		}
		else
		{
			printf("Case %ld: %ld\n",++cas,mx1);
			for(i=0;i<=k;i++) printf("%ld\n",ara[i]);
		}
		for(i=0;i<=k;i++)
		{
			ara[i]=0;
			ara1[i]=0;
		}
	}

	return 0;
}
