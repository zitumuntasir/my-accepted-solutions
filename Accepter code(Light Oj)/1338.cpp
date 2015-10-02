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
long ara[91];
int main()
{
	long test,i,cnt;
	char j;
	scanf("%ld",&test);
	getchar();
	for(i=1;i<=test;i++)
	{
		cnt=0;
		while(1)
		{
			j=getchar();
			if(j=='\n')
				break;
			else
			{
			j=toupper(j);
			if(j!=' ')
			ara[j]++;
		if(ara[j]==1)
		{
			cnt++;
		}
			}
		}
		while(1)
		{
			j=getchar();
			j=toupper(j);
			if(j=='\n')
			break;
			if(j!=' ')
			{
			ara[j]--;
			if(ara[j]==0)
			{
				cnt--;
			}
			}
		}
		if(cnt==0)
			printf("Case %ld: Yes\n",i);
		else
			printf("Case %ld: No\n",i);
		memset(ara,0,sizeof(ara));
	}
	return 0;
}
