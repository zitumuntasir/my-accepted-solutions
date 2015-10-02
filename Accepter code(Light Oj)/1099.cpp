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
vector<long>vc[5002],cst[5002];
bool visit[5002];
long dst[5002],k,n,l,sz,p,q,dis,dst1[5002];
void ds()
{
	for(k=0;k<=n;k++)
	{
		dst[k]=inf;
		dst1[k]=inf;
		vc[k].clear();
		cst[k].clear();
	}
}
struct data{
	int city,dist;
	bool operator<(const data&p)const{
        return dist>p.dist;
	}
};
priority_queue<data>qu;
data u,v;
void dij()
{
 	while(!qu.empty())
	{
		u=qu.top();
		sz=vc[u.city].size();
		p=u.city;
		for(l=0;l<sz;l++)
		{
			dis=dst[p]+cst[p][l];
			q=vc[p][l];
			if(dis<dst[q])
			{
				v.city=q;
				v.dist=dis;
				dst[q]=dis;
				qu.push(v);
			}
		}
		qu.pop();
	}
}
void dij1()
{
	while(!qu.empty())
	{
		u=qu.top();
		sz=vc[u.city].size();
		p=u.city;
		for(l=0;l<sz;l++)
		{
			dis=u.dist+cst[p][l];
			q=vc[p][l];
			if((dis>=dst[q]&&dis<dst1[q]&&dst1[q]==inf)||(dst1[q]==dst[q]))
			{
				v.city=q;
				dst1[q]=dis;
				v.dist=dis;
				qu.push(v);
			}
		}
		qu.pop();
	}
}
int main()
{
	long i,j,k,test,a,b,c,e;
	scanf("%ld",&test);
	for(i=0;i<test;i++)
	{
		scanf("%ld%ld",&n,&e);
		ds();
		for(j=0;j<e;j++)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			vc[a].push_back(b);
			vc[b].push_back(a);
			cst[a].push_back(c);
			cst[b].push_back(c);
		}
		dst[1]=0;
		u.city=1;
		u.dist=0;
		qu.push(u);
		dij();
		//printf("%ld\n",dst[n]);
		while(!qu.empty()) qu.pop();
		dst1[1]=0;
		u.city=1;
		u.dist=0;
		qu.push(u);
		dij1();
		printf("%ld\n",dst1[n]);
	}
	return 0;
}
