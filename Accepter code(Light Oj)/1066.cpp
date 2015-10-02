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
char ch[21][21],c='B',s,ch1[21][21],p,q;
long xaray[]={0,0,-1,1};
long yaray[]={1,-1,0,0};
long res,cnt,num,sum=1,n,ara[200],l;
queue<char>qu;
queue<long>q1,q2;
map<char,long>mp;
long bfs(long x,long y)
{
	long i;
	l=1;
	qu.push(ch[x][y]);
	q1.push(x);
	q2.push(y);
	ch[x][y]='#';
	ara[0]=1;
	while((!q1.empty())&&(!q2.empty()))
	{
		x=q1.front();
		y=q2.front();
		for(i=0;i<4;i++)
		{
			if(ch[x+xaray[i]][y+yaray[i]]=='.'||(ch[x+xaray[i]][y+yaray[i]]<=c&&ch[x+xaray[i]][y+yaray[i]]>='A'))
			{
				q1.push(x+xaray[i]);
				q2.push(y+yaray[i]);
				if(ara[l-1]!=0)
				{
					ara[l]++;
				}
				if(ch[x+xaray[i]][y+yaray[i]]==c)
				{
					p=x+xaray[i];
					q=y+yaray[i];
					return l;
				}
				ch[x+xaray[i]][y+yaray[i]]='#';
			}
		}
		ara[l-1]--;
		if(ara[l-1]==0)
		{
			l++;
		}
		q1.pop();
		q2.pop();
	}
	return 0;
}
int main()
{
	long test,i,j,k,x,y,no,sum;
	scanf("%ld",&test);
	for(i=1,no=0;i<=test;i++,c='B',cnt=res=no=0,sum=1)
	{
		scanf("%ld",&num);
		getchar();
		for(j=n=0;j<num;j++)
		{
			gets(ch[j]);
			strcpy(ch1[j],ch[j]);
			for(k=0;k<num;k++)
			{
				if(ch[j][k]=='A')
				{
					x=j,y=k;
				}
				if(ch[j][k]>='B'&&ch[j][k]<='Z')
				{
					n++;
				}
			}
		}
		while(cnt!=n)
		{
			sum=bfs(x,y);
		 res+=sum;
		 if(sum==0)
		 {
			 no=1;
		 }
		 cnt++;
		 c++;
		 while(!qu.empty()) qu.pop();
		 while(!q1.empty()) q1.pop();
		 while(!q2.empty()) q2.pop();
		for(j=0;j<num;j++)
		{
			strcpy(ch[j],ch1[j]);
		}
		for(j=0;j<=l;j++)
			ara[j]=0;
		//memset(ara,0,sizeof(ara));
		x=p,y=q;
		}
		if(no==1)
			printf("Case %ld: Impossible\n",i);
		else
		printf("Case %ld: %ld\n",i,res);
		for(j=0;j<num;j++)
		{
			memset(ch[j],NULL,sizeof(ch[j]));
			//memset(ara,0,sizeof(ara));
		}
	}
	return 0;
}
