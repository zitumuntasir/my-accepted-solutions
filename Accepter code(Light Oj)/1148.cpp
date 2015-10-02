#include<cstdio>
#include<map>
using namespace std;
int ara2[51];
map<int,int>ar;
	int test,i,num,n,k,res,sum,j;
int main()
{
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		sum=0;
		k=0;
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			scanf("%d",&n);
			if(ar[n+1]==0)
			{
				ara2[k]=n+1;
				k++;
			}
			ar[n+1]++;
		}
		for(j=0;j<k;j++)
		{
			res=ar[ara2[j]]/ara2[j];
			if(ar[ara2[j]]%ara2[j]) res++;
			sum+=(res*ara2[j]);
		}
		printf("Case %d: %d\n",i+1,sum);
		ar.clear();
	}
	return 0;
}
