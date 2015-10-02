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
int k,ara[120],prime[120],pfact[100],l,u,v,s,d,visit[1010],cst[1010],y;
queue<int>qu;
void sieve()
{
	prime[0]=2;
	int num=110,j,i,root;
	root=sqrt(num);
	k=1;
	for(i=3;i<=num;i+=2)
	{
		if(ara[i]==0)
		{
			prime[k]=i;
			k++;
		}
		if(i<=root)
		{
			for(j=i*i;j<=num;j+=(i*2))
			{
				ara[j]=1;
			}
		}
	}

}
void pf(int n)
 {
      int root,i;
	  l=0;
      root=sqrt(n);
  for(i=0;prime[i]<=root;i++)
  {
    if(n%prime[i]==0)
	{
		pfact[l] = prime[i];
        l++;
      while( n % prime[i] == 0 )
	  {
        n /= prime[i];
	  }
	}
  }
      if( n > 1 )
	  {
      pfact[l] = n;
      l++;
	  }
  }
void bfs()
{
	int i,y=0;
	while(!qu.empty())
	{
		u=qu.front();
		qu.pop();
		pf(u);
		for(i=0;i<l;i++)
		{
			if(pfact[i]!=s)
			{
			  v=u+pfact[i];
			  if(v<=d&&visit[v]==0)
			  {
				visit[v]=1;
				cst[v]=cst[u]+1;
				if(v==d) {y=1; break;}
				qu.push(v);
			  }
			}
		}
		if(y) break;
	}
}

int main()
{
	int i,num,j;
	sieve();
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&s,&d);
		//pf(s);
		qu.push(s);
		bfs();
		if(cst[d]==0&&s!=d) printf("Case %d: -1\n",i+1);
		else
		printf("Case %d: %d\n",i+1,cst[d]);
		while(!qu.empty()) qu.pop();
		for(j=0;j<=d;j++) 
		{
			cst[j]=0;
			visit[j]=0;
		}
	}
	return 0;
}
