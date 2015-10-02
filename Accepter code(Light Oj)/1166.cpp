#include<stdio.h>
#include<algorithm>
using namespace std;
int ara[102],ara1[102],ara2[102];
int main()
{
	int test,i,n,cnt,cas=0;
	scanf("%d",&test);
	while(test--)
	{
		cnt=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ara[i]);
			ara1[i]=ara[i];
			ara2[ara[i]]=i;
		}
		sort(ara1+1,ara1+n+1);
		for(i=1;i<=n;i++)
		{
			if(ara[i]!=ara1[i])
			{
				swap(ara[i],ara[ara2[ara1[i]]]);
				swap(ara2[ara[i]],ara2[ara[ara2[ara1[i]]]]);
				cnt++;
			}
		}
		printf("Case %d: %d\n",++cas,cnt);
		for(i=0;i<=n;i++)
		{
			ara[i]=ara1[i]=ara2[i]=0;
		}
	}
	return 0;
}
