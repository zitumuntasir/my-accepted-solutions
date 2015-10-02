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
vector<long>vc[20010];
long ara[20020],ara1[20020],visit[20020],numb[10],cst[20020];
queue<long>qu;
void bfs(long node)
{
	long k=1,u,v,i,j,size,c;
	qu.push(node);
	visit[node]=1;
	cst[node]=1;
	numb[1]++;
	while(!qu.empty())
	{
		u=qu.front();
		size=vc[u].size();
		for(i=0;i<size;i++)
		{
			v=vc[u][i];
			if(!visit[v])
			{
			  visit[v]=1;
			  c=3-cst[u];
			  cst[v]=c;
			  numb[c]++;
			  qu.push(v);
			}
		}
		qu.pop();
	}

}
int main()
{
	long test,i,j,k,num,u,v,mx,res;
	scanf("%ld",&test);
	for(i=1,res=0;i<=test;i++,res=0)
	{
		scanf("%ld",&num);
		for(j=k=0;j<num;j++)
		{
			scanf("%ld%ld",&u,&v);
			if(ara[u]==0)
			{
				ara[u]=1;
				ara1[k]=u;
				k++;
			}
			if(ara[v]==0)
			{
				ara[v]=1;
				ara1[k]=v;
				k++;
			}
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		for(j=0;j<k;j++)
		{
			if(visit[ara1[j]]==0)
			{
				bfs(ara1[j]);
			}
			mx=MAX(numb[1],numb[2]);
			res+=mx;
			numb[1]=numb[2]=0;
		}
		printf("Case %ld: %ld\n",i,res);
		for(j=0;j<=k;j++)
		{
			vc[ara1[j]].clear();
			ara[ara1[j]]=cst[ara1[j]]=visit[ara1[j]]=0;
		}
	}
	return 0;
}
