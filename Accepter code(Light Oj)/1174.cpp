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
long n,s,d,u,v,sz,k,cnt,res,y;
long cost[1000],visit[10000];
vector<long>vc[510];
queue<long>qu;
void bfs()
{
	while(1)
	{
		u=qu.front();
		sz=vc[u].size();
		for(k=0;k<sz;k++)
		{
			v=vc[u][k];
			if(!visit[v])
			{
				cnt++;
				visit[v]=1;
			}
			cost[v]=cost[u]+1;
			qu.push(v);
			if(cnt==n&&v==d)
			{
				y=1;
				break;
			}
		}
		if(y) break;
		qu.pop();
	}
}
int main()
{
	long test,e,i,j,a,b;
	scanf("%ld",&test);
	for(i=0;i<test;i++)
	{
		y=cnt=res=0;
		scanf("%ld%ld",&n,&e);
		for(j=0;j<e;j++)
		{
			scanf("%ld%ld",&a,&b);
			vc[a].push_back(b);
			vc[b].push_back(a);
		}
		scanf("%ld%ld",&s,&d);
		visit[s]=1;
		cnt++;
		qu.push(s);
		bfs();
		printf("%ld\n",cost[d]);
		while(!qu.empty()) qu.pop();
		for(j=0;j<=n;j++)
		{
			visit[j]=0;
			vc[j].clear();
		}
	}
	return 0;
}
