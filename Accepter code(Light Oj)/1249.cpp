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
struct cok
{
	long p;
	char st[102];
};
cok x,y,z,ara[102];
bool cmp(cok aa,cok bb)
{
	return aa.p<bb.p;
}
int main()
{
	long test,i,j,num;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		scanf("%ld",&num);
		for(j=0;j<num;j++)
		{
			scanf("%s%ld%ld%ld",ara[j].st,&x.p,&y.p,&z.p);
			ara[j].p=(x.p*y.p*z.p);
		}
		sort(ara,ara+num,cmp);
		if(ara[0].p==ara[num-1].p)
			printf("Case %ld: no thief\n",i);
		else
		printf("Case %ld: %s took chocolate from %s\n",i,ara[num-1].st,ara[0].st);
	}
	return 0;
}
