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
char ch[10],ch1[10];
map<string,long>mp;
vector<long>vc[10100];
queue<long>qu;
long ind[10100];
int main()
{
	long test,i,j,num,k,u,v,count;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		scanf("%ld",&num);
		for(j=k=count=0;j<num;j++)
		{
			scanf("%s%s",ch,ch1);
			if(mp[ch]==0)
			{
				k++;
				mp[ch]=k;
			}
			if(mp[ch1]==0)
			{
				k++;
				mp[ch1]=k;
			}
			ind[mp[ch1]]++;
			vc[mp[ch]].push_back(mp[ch1]);
		}
		for(j=1;j<=k;j++)
		{
			if(ind[j]==0)
			{
				qu.push(j);
			}
		}
		while(!qu.empty())
		{
			u=qu.front();
			count++;
			for(j=0;j<vc[u].size();j++)
			{
				v=vc[u][j];
				ind[v]--;
				if(ind[v]==0)
					qu.push(v);
			}
			qu.pop();
		}
		if(count==k)
			printf("Case %ld: Yes\n",i);
		else
			printf("Case %ld: No\n",i);
		for(j=0;j<=k;j++)
		{
			vc[j].clear();
		}
		memset(ind,0,sizeof(ind));
		mp.clear();
	}
	return 0;
}
