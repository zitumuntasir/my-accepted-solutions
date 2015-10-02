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
#define pi acos(-1.0)
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
#define inf (1<<30)-1
#define SIZE 100000001
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
const double E = 2.7182818284590452353602874713527;
using namespace std;
#define eps 1e-14
char ch[210][210];
struct ss{
	int x,y;
};
vector<ss>vc;
int main()
{
	long i,j,k,test,r,c;
	scanf("%ld",&test);
	for(i=0;i<test;i++)
	{
		scanf("%ld%ld",&r,&c);
		for(j=0;j<r;j++)
		{
			getchar();
			for(k=0;k<c;k++)
			{
				scanf("%c",&ch[j][k]);
				if(ch[j][k]=='*')
				{

				}
			}
		}
	}
	return 0;
}
