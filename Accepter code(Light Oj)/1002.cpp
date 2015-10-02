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
int par[510],rank[510];
int u,v,dst,nod,cnt;
struct ss{
	int in,fn,cst;
}ara[16002];
struct ssa{
	int ina,fna,csta;
}araa[510];
bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}
void makepair(int n)
{
	int i;
	for(i=0;i<n;i++)
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
		rank[u]+=rank[v];
		cnt--;
	}
	else if(rank[u]>rank[v])
	{
		par[v]=u;
		if(rank[v]==0) 
		{
			rank[u]++;
			nod++;
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
	int test,i,n,m,j,k,mx,y,l;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		mx=nod=cnt=k=0;
	 scanf("%d%d",&n,&m);
	 for(j=0;j<m;j++)
	 {
		 scanf("%d%d%d",&ara[j].in,&ara[j].fn,&ara[j].cst);
	 }
	 sort(ara,ara+m,cmp);
	 makepair(n);
	 scanf("%d",&dst);
	 for(j=0;j<m;j++)
	 {
		 u=findpar(ara[j].in);
		 v=findpar(ara[j].fn);
		 if(u!=v)
		 {
			 araa[k].ina=ara[j].in;
			 araa[k].fna=ara[j].fn;
			 araa[k].csta=ara[j].cst;
			 k++;
			 link();
			 if(nod==n&&cnt==1) break;
		 }
	 }
	 printf("Case %d:\n",i+1);
		 for(l=0;l<n;l++)
		 {
			 y=mx=0;
			 makepair(n);
			 for(j=0;j<k;j++)
			 {
				   u=findpar(dst);
			       v=findpar(l);
				  if(u==v)
				  {
					  y=1;
					  printf("%d\n",mx);
					  break;
				  }
			  u=findpar(araa[j].ina);
			  v=findpar(araa[j].fna);
			  if(u!=v)
			  {
				  if(araa[j].csta>mx)
				  {
					  mx=araa[j].csta;
				  }
				  link();
			  }
			 }
			 if(y==0)
			 {
     			 u=findpar(dst);
	     		 v=findpar(l);
				  if(u==v)
				  {
					  y=1;
					  printf("%d\n",mx);
				  }
				  else
				 printf("Impossible\n");
			 }
		 }
	}

	return 0;
}
