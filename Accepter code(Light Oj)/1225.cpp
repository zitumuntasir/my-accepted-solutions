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
char ch[12];
int main()
{
	long test,i,j,k,l,len,n;
	scanf("%ld",&test);
	for(i=1;i<=test;i++)
	{
		n=0;
		scanf("%s",ch);
		len=strlen(ch);
		for(j=0,k=len-1;j<len;j++,k--)
		{
			if(ch[j]!=ch[k])
			{
				n=1;
				break;
			}
		}
		if(n==1)
			printf("Case %ld: No\n",i);
		else
			printf("Case %ld: Yes\n",i);
	}
	return 0;
}
