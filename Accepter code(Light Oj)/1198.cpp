#include<stdio.h>
#include<algorithm>
using namespace std;
int ara[52],ara1[52],ar[52],arr[52];
int main()
{
	int test,i,j,n,res,cas=0;
	scanf("%d",&test);
	while(test--)
	{
		res=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ara[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&ara1[i]);
		}
		sort(ara,ara+n);
		sort(ara1,ara1+n);
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(ara[j]>ara1[i]&&ar[j]==0&&arr[i]==0)
				{
					res+=2;
					ar[j]=1;
					arr[i]=1;
				}
			}
		}

		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(ara[j]==ara1[i]&&ar[j]==0&&arr[i]==0)
				{
					res+=1;
					ar[j]=1;
					arr[i]=1;
				}
			}
		}
		printf("Case %d: %d\n",++cas,res);
		for(i=0;i<=n;i++)
		{
			arr[i]=ar[i]=0;
		}

	}
	return 0;
}