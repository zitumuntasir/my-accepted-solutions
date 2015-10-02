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
int rank[210],par[210];
int j,u,v,nod,cnt;
struct ss{
	int in,fn,cst;
}ara[6001];
struct ssa{
	int ina,fna,csta,inb,fnb,cstb;
}araa[202];
bool cmp(ss aa,ss bb)
{
	return aa.cst<bb.cst;
}
bool cmpa(ssa aa,ssa bb)
{
	return aa.csta<bb.csta;
}
bool cmpb(ssa aa,ssa bb)
{
	return aa.cstb<bb.cstb;
}
void makepair(long n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		par[i]=i;
	}
}
long findpar(int r)
{
	if(par[r]==r) return r;
	else
		return par[r]=findpar(par[r]);
}
void clr(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		rank[i]=par[i]=0;
	}
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
	int test,i,w,c,k,n,l,cost,ys,y,t,r,costa;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		ys=y=l=0;
		scanf("%d%d",&n,&w);
		printf("Case %d:\n",i+1);
		for(j=0;j<w;j++)
		{
			cost=nod=cnt=0;
			scanf("%d%d%d",&ara[j].in,&ara[j].fn,&ara[j].cst);
			if(ys==0)
			{
				l=0;
				//cost=nod=cnt=0;
				clr(n);
				makepair(n);
				sort(ara,ara+j+1,cmp);
				for(k=0;k<=j;k++)
				{
					u=findpar(ara[k].in);
					v=findpar(ara[k].fn);
					if(u!=v)
					{
						link();
						araa[l].ina=ara[k].in;
						araa[l].fna=ara[k].fn;
						araa[l].csta=ara[k].cst;
						cost+=ara[k].cst;
						l++;
					}
				}
					if(cnt==1&&nod==n)
					{
						y=1;
						ys=1;
						printf("%d\n",cost);
						l++;
					}
					   
					else 
					{
						printf("-1\n");
					}
			}
			else
			{
				r=l;
				if(y==1)
				{
					nod=cnt=cost=k=0;
					araa[r-1].ina=ara[j].in;
					araa[r-1].fna=ara[j].fn;
					araa[r-1].csta=ara[j].cst;
					sort(araa,araa+r,cmpa);
					clr(n);
					makepair(n);
					for(l=0;l<r;l++)
					{
						u=findpar(araa[l].ina);
						v=findpar(araa[l].fna);
						if(u!=v)
						{
							link();
							araa[k].inb=araa[l].ina;
							araa[k].fnb=araa[l].fna;
							araa[k].cstb=araa[l].csta;
							k++;
							cost+=araa[l].csta;
						}
					}
					if(cnt==1&&nod==n)
					{
						y=0;
						printf("%d\n",cost);
					}
					else
					{
						printf("-1\n");
					}
				}
				else
				{
					nod=cnt=cost=k=0;
					araa[r-1].inb=ara[j].in;
					araa[r-1].fnb=ara[j].fn;
					araa[r-1].cstb=ara[j].cst;
					sort(araa,araa+r,cmpb);
					clr(n);
					makepair(n);
					for(l=0;l<r;l++)
					{
						u=findpar(araa[l].inb);
						v=findpar(araa[l].fnb);
						if(u!=v)
						{
							link();
							araa[k].ina=araa[l].inb;
							araa[k].fna=araa[l].fnb;
							araa[k].csta=araa[l].cstb;
							k++;
							cost+=araa[l].cstb;
						}
					}
					if(cnt==1&&nod==n)
					{
						y=1;
						printf("%d\n",cost);
					}
					else
					{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}
