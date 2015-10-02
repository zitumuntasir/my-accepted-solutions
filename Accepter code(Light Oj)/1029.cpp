#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<limits>
#include<vector>
#include<stack>
#include<string>
#include<deque>
#include<set>
#include<list>
#include<bitset>
#include<ctime>
#include<functional>
#include<numeric>
#include<cfloat>
#include<sstream>
#include<complex>
#include<queue>
#include<cstring>
#include<stdexcept>
#include<utility>
#include<map>
#include<fstream>
#include<iomanip>
#include<cassert>
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
#define inf (1<<30)-1
#define SIZE 100000001
#define pi 3.14159265358979323846
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
const double E = 2.7182818284590452353602874713527;
using namespace std;
#define eps 1e-14
int par[110],rank[110],para[110],ranka[110];
int u,v,w,p,q;
struct ss{
	int in,fn,cst;
}ara[12002];
bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}
void makepair(int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		par[i]=para[i]=i;
		rank[i]=ranka[i]=0;
	}
}
int findpar(int r)
{
	if(par[r]==r) return r;
	else
		return par[r]=findpar(par[r]);
}
int findpara(int r)
{
	if(para[r]==r) return r;
	else
		return para[r]=findpara(para[r]);
}
void link()
{
	if(rank[u]==0&&rank[v]==0)
	{
		par[v]=u;
		rank[u]+=2;
	}
	else if(rank[u]==rank[v])
	{
		par[v]=u;
		rank[u]+=rank[v];
	}
	else if(rank[u]>rank[v])
	{
		par[v]=u;
		if(rank[v]==0) rank[u]++;
		else
			rank[u]+=rank[v];
	}
	else if(rank[v]>rank[u])
	{
		par[u]=v;
		if(rank[u]==0) rank[v]++;
		else
			rank[v]+=rank[u];
	}
}
void linka()
{
	if(ranka[u]==0&&ranka[v]==0)
	{
		para[v]=u;
		ranka[u]+=2;
	}
	else if(ranka[u]==ranka[v])
	{
		para[v]=u;
		ranka[u]+=ranka[v];
	}
	else if(ranka[u]>ranka[v])
	{
		para[v]=u;
		if(ranka[v]==0) ranka[u]++;
		else
			ranka[u]+=ranka[v];
	}
	else if(ranka[v]>ranka[u])
	{
		para[u]=v;
		if(ranka[u]==0) ranka[v]++;
		else
			ranka[v]+=ranka[u];
	}
}
int main()
{
	int test,i,l,n,j,k,cost,costa,res;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		l=k=cost=costa=0;
		scanf("%d",&n);
		makepair(n);
		while(scanf("%d%d%d",&u,&v,&w)&&(u!=0||v!=0||w!=0))
		{
			ara[l].in=u;
			ara[l].fn=v;
			ara[l].cst=w;
			l++;
		}
		sort(ara,ara+l,cmp);
		for(j=0,k=l-1;j<l;j++,k--)
		{
			u=findpar(ara[j].in);
			v=findpar(ara[j].fn);
			if(u!=v)
			{
				cost+=ara[j].cst;
				link();
			}
			u=findpara(ara[k].in);
			v=findpara(ara[k].fn);
			if(u!=v)
			{
				costa+=ara[k].cst;
				linka();
			}
		}
		res=cost+costa;
		if(even(res))
		{
			printf("Case %d: %d\n",i+1,res/2);
		}
		else
		{
			printf("Case %d: %d/2\n",i+1,res);
		}
	}
	return 0;
}
