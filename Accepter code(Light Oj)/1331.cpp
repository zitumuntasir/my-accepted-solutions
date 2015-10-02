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
int main()
{
	long test,cas=0;
	double r1,r2,r3,a,b,c,s,ara,x,y,z,ara1,ara2,ara3;
	scanf("%ld",&test);
	while(test--)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a=r1+r2;
		b=r1+r3;
		c=r2+r3;
		s=(a+b+c)/2;
		ara=sqrt(s*(s-a)*(s-b)*(s-c));
		x=acos(((b*b+c*c-a*a)/(2*b*c)))*180/pi;
		y=acos(((c*c+a*a-b*b)/(2*c*a)))*180/pi;
		z=acos(((a*a+b*b-c*c)/(2*a*b)))*180/pi;
		ara1=(pi*r1*r1*x)/360;
		ara2=(pi*r2*r2*y)/360;
		ara3=(pi*r3*r3*z)/360;
		printf("Case %ld: %.10lf\n",++cas,ara-ara1-ara2-ara3+.00000001);
	}
	return 0;
}
