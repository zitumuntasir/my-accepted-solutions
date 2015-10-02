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
int cot[60][60],par[60],rank[60];
int nod,cnt,u,v;
struct ss{
	int in,fn,cst;
}ara[1300];
bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}
void makepair(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
	par[i]=i;
	rank[i]=0;
	}
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
		nod+=2;
		cnt++;
	}
	else if(rank[u]==rank[v])
	{
		par[v]=u;
		cnt--;
		rank[u]+=rank[v];
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
	int test,i,j,k,l,num,ttl,sum;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		l=nod=cnt=ttl=sum=0;
		scanf("%d",&num);
			makepair(num);
		for(j=1;j<=num;j++)
		{
			for(k=1;k<=num;k++)
			{
				scanf("%d",&cot[j][k]);
				sum+=cot[j][k];
				if(k<=j)
				{
					if(cot[j][k]!=0||cot[k][j]!=0)
					{
						ara[l].in=j;
						ara[l].fn=k;
						if(cot[j][k]!=0&&cot[k][j]!=0)
						{
							ara[l].cst=MIN(cot[j][k],cot[k][j]);
						}
						else
						{
							ara[l].cst=MAX(cot[j][k],cot[k][j]);
						}
						cot[j][k]=cot[k][j]=0;
						l++;
					}
				}
				
			}
		}
		sort(ara,ara+l,cmp);
		for(j=0;j<l;j++)
		{
			u=findpar(ara[j].in);
			v=findpar(ara[j].fn);
			if(u!=v)
			{
				ttl+=ara[j].cst;
				link();
			}
		}
		if((cnt==1&&nod==num)||num==1)
		{
			printf("Case %d: %d\n",i+1,sum-ttl);
		}
		else
		{
			printf("Case %d: -1\n",i+1);
		}
		/*for(j=0;j<=num;j++)
		{
			rank[j]=par[j]=0;
			for(k=0;k<=num;k++)
			{
				cot[j][k]=0;
			}
		}*/
	}
	return 0;
}
