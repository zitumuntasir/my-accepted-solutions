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
long xaray[]={0,0,1,-1};
long yaray[]={1,-1,0,0};
char ch[30][30];
long visit[30][30],m,n,l,ara[400];
typedef struct{
    long x,y;
}node;
node u,v;
queue<node>qu;
long bfs(long p,long q)
{
	long i;
	u.x=p,u.y=q;
	qu.push(u);
	ara[0]=1;
	while(!qu.empty())
	{
		u=qu.front();
		for(i=0;i<4;i++)
		{
		 v.x=u.x+xaray[i],v.y=u.y+yaray[i];
		 if((v.x>=0&&v.x<m)&&(v.y>=0&&v.y<n)&&(ch[v.x][v.y]!='#'&&ch[v.x][v.y]!='m')&&visit[v.x][v.y]==0)
		 {
			     if(ara[l-1]!=0)
					ara[l]++;
			 if(ch[v.x][v.y]=='h')
				 return l;
			 qu.push(v);
			 visit[v.x][v.y]=1;
		 }
		}
		ara[l-1]--;
		if(ara[l-1]==0) l++;
		qu.pop();

	}
	return 0;
}
int main()
{
	long test,i,j,k,u,v,p,q,r,s,t,max,res;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		max=0;
		scanf("%ld%ld",&m,&n);
		getchar();
		for(j=0;j<m;j++)
		{
			gets(ch[j]);
			for(k=0;k<n;k++)
			{
				if(ch[j][k]=='a')
				{
					p=j,q=k;
				}
				if(ch[j][k]=='b')
				{
					r=j,s=k;
				}
				if(ch[j][k]=='c')
				{
					t=j,u=k;
				}
			}
		}
		l=1;
		res=bfs(p,q);
		if(res>max)
		{
			max=res;
		}
		for(j=0;j<m;j++)
		for(k=0;k<n;k++)
		visit[j][k]=0;
		for(j=0;j<=l;j++) ara[j]=0;
		l=1;
		while(!qu.empty()) qu.pop();
  		res=bfs(r,s);
		if(res>max)
		{
			max=res;
		}
		for(j=0;j<m;j++)
		for(k=0;k<n;k++)
		visit[j][k]=0;
		for(j=0;j<=l;j++) ara[j]=0;
		while(!qu.empty()) qu.pop();
		l=1;
		res=bfs(t,u);
		if(res>max)
		{
			max=res;
		}
		for(j=0;j<m;j++)
		for(k=0;k<n;k++)
		visit[j][k]=0;
		for(j=0;j<=l;j++) ara[j]=0;
		while(!qu.empty()) qu.pop();
		l=1;
		printf("Case %ld: %ld\n",i,max);
	}
	return 0;
}
