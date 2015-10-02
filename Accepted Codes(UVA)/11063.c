#include<stdio.h>
#include<math.h>
long ara[10000000],ara3[10000000],ara2[10000000];
int main()
{
long N,a,b,c,num,d,e,i,j,k,t=0,l;
	while(scanf("%ld",&num)!=EOF)
	{
		k=0;
		t++;
		N=0;
	for(i=0;i<num;i++)
	{
		scanf("%ld",&ara[i]);
	}
	for(i=0;i<num;i++)
	{
		for(j=i;j<num;j++)
		{
			if((ara[i]>ara[j])||(ara[i]<1||ara[j]<1))
			{
				N=1;
				break;
			}
			else
			{
			a=ara[i]+ara[j];
			ara2[k]=a;
			k++;
			if(ara3[a]!=0)
			{
				N=1;
				break;
			}
			else
			{
				ara3[a]=1;
			}
			}
		}
	}
	if(N==0)
		printf("Case #%ld: It is a B2-Sequence.\n\n",t);
	else
		printf("Case #%ld: It is not a B2-Sequence.\n\n",t);
	for(l=0;l<k;l++)
	{
		ara3[ara2[l]]=0;
	}
	}
	return 0;
}