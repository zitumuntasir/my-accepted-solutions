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
typedef struct{
    long x,y;
}node;
queue<node>qu,q1;
node u,v;
long xaray[]={0,0,1,-1};
long yaray[]={1,-1,0,0};
long cnt,m,n;
char ch[1010][1010];
long visit[1010][1010],cst[1000][1000];
long dfs(long p,long q)
{
	long i;
	u.x=p,u.y=q;
	qu.push(u);
	q1.push(u);
	if(ch[u.x][u.y]=='C') cnt++;
	visit[u.x][u.y]=1;
	while(!qu.empty())
	{
		u=qu.front();
		for(i=0;i<4;i++)
		{
			v.x=u.x+xaray[i],v.y=u.y+yaray[i];
			if((v.x>=0&&v.x<m)&&(v.y>=0&&v.y<n)&&(ch[v.x][v.y]!='#'))
			{
				if(cst[v.x][v.y]!=0)
				{
					cnt+=(cst[v.x][v.y]);
					return cnt;
				}
			}
			if(v.x<0||v.x>=m||v.y<0||v.y>=n||ch[v.x][v.y]=='#'||visit[v.x][v.y]==1)
			{
			}
			else
			{
				if(ch[v.x][v.y]=='C') cnt++;
				qu.push(v);
				q1.push(v);
				visit[v.x][v.y]=1;
			}
		}
		qu.pop();
	}
	return cnt;
}
int main()
{
	long test,q,i,j,a,b,k,l,sum;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		sum=0;
		scanf("%ld%ld%ld",&m,&n,&q);
		getchar();
		for(j=0;j<m;j++)
		{
			gets(ch[j]);
		}
		printf("Case %ld:\n",i);
		for(j=0;j<q;j++)
		{
			cnt=0;
			scanf("%ld%ld",&a,&b);
			sum=dfs(a-1,b-1);
			printf("%ld\n",sum);
			while(!q1.empty())
			{
				u=q1.front();
				cst[u.x][u.y]=sum;
				q1.pop();
			}
			while(!qu.empty()) qu.pop();
		}
		for(k=0;k<m;k++)
			{
				for(l=0;l<n;l++)
				{
					visit[k][l]=cst[k][l]=0;
				}
			}

	}
	return 0;
}
