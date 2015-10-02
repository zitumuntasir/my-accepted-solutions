#include<stdio.h>
int main()
{
	double r1,r2,p,h;
	int test,cas=1;
	scanf("%d",&test);
	double r,res;
	while(test--)
	{
		scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
		r=(((r1-r2)/h)*p)+r2;
		res=((((r*r)+(r2*r2)+(r*r2))*p*3.14159265358979323846)/3)+.000000001;
		printf("Case %d: %.10lf\n",cas++,res);
	}
	return 0;
}
