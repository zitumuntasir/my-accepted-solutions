#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define inf 10000000
vector<int>vc[101],cst[101];
int pcost,sz,k,d[101];
void dis(int n)
{
	for(k=0;k<=n;k++)
		d[k]=inf;
}
struct data {
    int city, dist;
    bool operator<(const data&p)const{
        return dist>p.dist;
    }
};
data x,y;
priority_queue<data>q;
void dij(int src)
{
	d[src]=0;
	x.city=src;
	x.dist=0;
	q.push(x);
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		pcost=d[x.city];
		sz=vc[x.city].size();
		for(k=0;k<sz;k++)
		{
			y.city=vc[x.city][k];
			y.dist=pcost+cst[x.city][k];
			if(d[y.city]>y.dist)
			{
				d[y.city]=y.dist;
				q.push(y);
			}
		}
	}
}
int main()
{
	int a,b,test,i,j,e,w,n;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d%d",&n,&e);
		dis(n);
		for(j=0;j<e;j++)
		{
			scanf("%d%d%d",&a,&b,&w);
			vc[a].push_back(b);
			vc[b].push_back(a);
			cst[a].push_back(w);
			cst[b].push_back(w);
		}
		dij(1);
		if(d[n]==inf)
		{
			printf("Case %d: Impossible\n",i+1);
		}
		else
		{
			printf("Case %d: %d\n",i+1,d[n]);
		}
		for(j=0;j<=n;j++)
		{
			vc[j].clear();
			cst[j].clear();
		}
	}
	return 0;
}