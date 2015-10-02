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
const double eps = 1e-9;
vector<long>vc[30002],cst[30002];
bool visit[30002];
long cost[30002],mx,mx1,nd,cs;
queue<long>qu;
long u,v,sz,k,n;
void clr()
{
	mx=0;
	for(k=0;k<=n;k++)
	{
		cost[k]=0;
		visit[k]=0;
	}
}
void bfs()
{
	while(!qu.empty())
	{
		u=qu.front();
		sz=vc[u].size();
		for(k=0;k<sz;k++)
		{
			v=vc[u][k];
			cs=cst[u][k];
			if(!visit[v])
			{
				visit[v]=1;
				cost[v]=cost[u]+cs;
				qu.push(v);
				if(cost[v]>mx)
				{
					mx=cost[v];
					nd=v;
				}
			}
		}
		qu.pop();
	}
}
int main()
{
	long test,i,j,a,b,c,rs1,rs2;
	scanf("%ld",&test);
	for(i=0;i<test;i++)
	{
		mx=0;
		scanf("%ld",&n);
		for(j=0;j<n-1;j++)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			vc[a].push_back(b);
			vc[b].push_back(a);
			cst[a].push_back(c);
			cst[b].push_back(c);
		}
		qu.push(0);
		visit[0]=1;
		cost[0]=0;
		bfs();
		rs1=mx;
		clr();
		qu.push(nd);
		visit[nd]=1;
		cost[nd]=0;
		bfs();
		rs2=mx;
		printf("Case %ld: %ld\n",i+1,MAX(rs1,rs2));
		for(j=0;j<=n;j++)
		{
			visit[j]=cost[j]=0;
			vc[j].clear();
			cst[j].clear();
		}
	}
	return 0;
}
