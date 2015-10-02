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
char ch[51],ch1[51];
int rank[51],par[51],cnt,nod,u,v;
map<string,int>mp;
struct ss{
	int in,fn,cst;
}ara[51];
bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}
void makepair(int n)
{
	par[n]=n;
	rank[n]=0;
}
int findpar(int r)
{
	if(par[r]==r) return r;
	else
		return par[r]=findpar(par[r]);
}
void link()
{
	if(rank[u]==0&&rank[v]==0)
	{
		par[v]=u;
		rank[u]+=2;
		cnt++;
		nod+=2;
	}
	else if(rank[u]==rank[v])
	{
		par[v]=u;
		rank[u]+=rank[v];
		cnt--;
	}
	else if(rank[u]>rank[v])
	{
		par[v]=u;
		if(rank[v]==0)
		{
			nod++;
			rank[u]++;
		}
		else
		{
			cnt--;
			rank[u]+=rank[v];
		}
	}
	else if(rank[v]>rank[u])
	{
		par[u]=v;
		if(rank[u]==0)
		{
			nod++;
			rank[v]++;
		}
		else
		{
			cnt--;
			rank[v]+=rank[u];
		}
	}
}
int main()
{
	int test,i,j,k,n,cost;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		k=1;
		nod=cnt=cost=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%s%s%d",ch,ch1,&ara[j].cst);
			if(mp[ch]==0)
			{
				mp[ch]=k;
				makepair(k);
				k++;
			}
			if(mp[ch1]==0)
			{
				mp[ch1]=k;
				makepair(k);
				k++;
			}
			ara[j].in=mp[ch];
			ara[j].fn=mp[ch1];
		}
		sort(ara,ara+n,cmp);
		for(j=0;j<n;j++)
		{
			u=findpar(ara[j].in);
			v=findpar(ara[j].fn);
			{
				if(u!=v)
				{
					cost+=ara[j].cst;
					link();
				}
			}
		}
		if(cnt==1&&nod==k-1)
		{
			printf("Case %d: %d\n",i+1,cost);
		}
		else
		{
			printf("Case %d: Impossible\n",i+1);
		}
		mp.clear();
	}

	return 0;
}
