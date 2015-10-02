/*#include<stdio.h>
char ch[21][21];
int xaray[]={0,0,1,-1};
int yaray[]={-1,1,0,0};
int cnt;
void dfs(int x,int y)
{
	int i;
      if(ch[x][y]!='.'||ch[x][y]==NULL) return;
	   ch[x][y]='@';
	   cnt++;
	for(i=0;i<4;i++)
	{
		dfs(x+xaray[i],y+yaray[i]);
	}
}
int main()
{
	int i,j,k,test,a,b,x,y;
	scanf("%d",&test);
	for(i=1;i<=test;i++,cnt=0)
	{
		scanf("%d%d",&a,&b);
		getchar();
		for(j=0;j<b;j++)
		{
			gets(ch[j]);
			for(k=0;k<a;k++)
			{
				if(ch[j][k]=='@')
				{
					x=j,y=k;
				}
			}
		}
		ch[x][y]='.';
		dfs(x,y);
		printf("Case %d: %d\n",i,cnt);
		for(j=0;j<b;j++)
		{
			for(k=0;k<a;k++)
			{
				ch[j][k]=NULL;
			}
		}
	}
	return 0;
}
*/
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
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define pi acos(-1.0)
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
#define inf (1<<30)-1
#define SIZE 100000001
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
const double E = 2.7182818284590452353602874713527;
using namespace std;
#define eps 1e-14
char ch[22][22];
long visit[22][22];
struct node
{
	int x,y;
};
node u,v;
queue<node>qu;
int xara[]={0,0,1,-1};
int yara[]={1,-1,0,0};
int k,cnt=0;
void bfs()
{
	while(!qu.empty())
	{
		u=qu.front();
		for(k=0;k<4;k++)
		{
			v.x=u.x+xara[k];
			v.y=u.y+yara[k];
			if(ch[v.x][v.y]!=NULL&&ch[v.x][v.y]=='.'&&visit[v.x][v.y]==0)
			{
				cnt++;
				visit[v.x][v.y]=1;
				qu.push(v);
			}
		}
		qu.pop();
	}
}
int main()
{
	long test,r,c,i,j,cas=0;
	scanf("%ld",&test);
	while(test--)
	{
		cnt=1;
		scanf("%ld%ld",&c,&r);
		for(i=0;i<r;i++)
		{
			scanf("%s",ch[i]);
			for(j=0;j<c;j++)
			{
				if(ch[i][j]=='@')
				{
					u.x=i,u.y=j;
					visit[u.x][u.y]=1;
					qu.push(u);
				}
			}
		}
		bfs();
		printf("Case %ld: %ld\n",++cas,cnt);
		for(i=0;i<=r;i++)
		{
			for(j=0;j<=c;j++)
			{
				ch[i][j]=NULL;
				visit[i][j]=0;
			}
		}
	}
	return 0;
}
