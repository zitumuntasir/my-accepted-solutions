#include<stdio.h>
#include<algorithm>
using namespace std;
struct ss{
	long a,b;
}ara[10];
long ara1[50010][50010];
long ara2[50010][50010];
bool cmp(ss aa,ss bb)
{
	if(aa.a<bb.a) return 1;
	else if(aa.a==bb.a)
	{
		return aa.b>bb.b;
	}
	else
		return 0;
}
int main()
{
	long test,i,j,k,n,num;
	scanf("%ld",&test);
	while(test--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&ara[i].a,&ara[i].b);
		}
		sort(ara,ara+n,cmp);
		for(i=0;i<n;i++)
		{
			ara1[0][i]=ara[i].a;
			ara2[0][i]=ara[i].b;
		}
		num=n;
		while(1)
		{
			for(i=0;i<num;i++)
			{
				for(j=i+1;i<num;j++)
				{
					if(ara1[])
					if(ara[j].a<=ara[i].b)
					{

					}
				}
			}
		}
		/*for(i=0;i<n;i++)
		{
			printf("%ld %ld\n",ara[i].a,ara[i].b);
		}*/
	}
	return 0;
}