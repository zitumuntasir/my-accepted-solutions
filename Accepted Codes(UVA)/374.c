/*#include<stdio.h>
#include<math.h>
int main()
{
	long b,p,m,a,c,d,e,i,j,k,r;
	while(scanf("%ld",&b)&&b!=0)
	{
        scanf("%ld%ld",&p,&m);
	r=1;
	while(p)
	{
		if(p%2==0)
		{
			b=(((b%m)*(b%m))%m);
		}
		else
		{
			r=(((r%m)*(b%m))%m);
			b=(((b%m)*(b%m))%m);
		}
		p/=2;
	}
	printf("%ld\n",r);
	}

	return 0;
}*/
#include<stdio.h>
long F(long N,long P,long M);
int main()
{
	long N,P,res,M;
	scanf("%ld%ld",&N,&P,&M);
	res=F(N,P,M);
	printf("%ld\n",res);
	return 0;
}
long F(long N,long P,long M)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        long ret=F(N,P/2,M);
        return ((ret%M)*(ret%M))%M;
    }
    else return ((N%M)*(F(N,P-1,M)%M))%M;
}

