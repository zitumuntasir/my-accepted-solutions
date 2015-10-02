#include<stdio.h>
int ara[10001],ara1[1000001];
int main()
{
	int test,i,n,no,cas=0,p;
	scanf("%d",&test);
	while(test--)
	{
		no=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&ara[i]);
			p=ara[i];
			ara1[p]++;
		}
		for(i=0;i<n;i++)
		{
			p=n-i-1;
			if(ara1[i]>0||ara1[p]>0)
			{
				if(ara1[i]>0)
				{
					ara1[i]--;
				}
				else
				{
					ara1[p]--;
				}
			}
			else
			{
				no=1;
				printf("Case %d: no\n",++cas);
				break;	
			}
		}
		if(!no)
		{
			printf("Case %d: yes\n",++cas);	
		}
		else
		for(i=0;i<=n;i++)
		{
			ara1[ara[i]]=0;
		}
	}
	return 0;
}