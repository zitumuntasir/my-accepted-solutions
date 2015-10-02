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
#define eps 1e-14
const double E = 2.7182818284590452353602874713527;
using namespace std;
vector<long>vc[10010];
long ara[10000],vs[1020][1020],k,cnt,visit[10000];
queue<long>qu;
void bfs(long node,long r)
{
	long i,sz,u,v;
	qu.push(node);
	if(visit[node]<=r&&vs[node][node]==0)
	{
		vs[node][node]=1;
		visit[node]++;
		if(r+1==k&&visit[node]==k)
		{
			cnt++;
		}
	}
	while(!qu.empty())
	{
		u=qu.front();
		sz=vc[u].size();
		for(i=0;i<sz;i++)
		{
			v=vc[u][i];
			if(visit[v]<=r&&vs[u][v]==0)
			{
				qu.push(v);
				visit[v]++;
				vs[u][v]=1;
				if(r+1==k&&visit[v]==k)
				{
					cnt++;
				}
			}
		}
		qu.pop();
	}
}
int main()
{
	long u,v,i,j,n,m,test,r,l;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		cnt=0;
		scanf("%ld%ld%ld",&k,&n,&m);
		for(j=0;j<k;j++)
		{
			scanf("%ld",&ara[j]);
		}
		for(j=0;j<m;j++)
		{
			scanf("%ld%ld",&u,&v);
			vc[u].push_back(v);
		}
		for(r=0;r<k;r++)
		{
			bfs(ara[r],r);
			for(j=0;j<=n;j++)
			{
			for(l=0;l<=n;l++)
			{
				vs[j][l]=0;
			}
			}
		}
		printf("Case %ld: %ld\n",i,cnt);
		for(j=0;j<=n;j++)
		{
			vc[j].clear();
			visit[j]=ara[j]=0;
			for(r=0;r<=n;r++)
			{
				vs[j][r]=0;
			}
		}
	}
	return 0;
}
