#include<stdio.h>
int ara[10100];
int main()
{
	int test,i,sum,j,cas=0,n;
	scanf("%d",&test);
	while(test--)
	{
		sum=0;
		for(i=0;i<6;i++)
		{
			scanf("%d",&ara[i]);
			ara[i]%=10000007;
			sum+=ara[i];
			sum%=10000007;
		}
		ara[6]=sum;
		scanf("%d",&n);
		for(j=7,i=0;j<=n;j++,i++)
		{
			ara[j]=ara[j-1]+ara[j-2]+ara[j-3]+ara[j-4]+ara[j-5]+ara[j-6];
			ara[j]%=10000007;
		}
		printf("Case %d: %d\n",++cas,ara[n]);
	}
	return 0;
}