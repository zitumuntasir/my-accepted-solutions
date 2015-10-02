#include<stdio.h>
#include<math.h>
int a[5],ara[5];
int main()
{
	char ch;
	int y=0,test,i,j,k,sum,md,l;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		y=0;
		scanf("%d%c%d%c%d%c%d",&a[0],&ch,&a[1],&ch,&a[2],&ch,&a[3]);
		scanf("%d%c%d%c%d%c%d",&ara[0],&ch,&ara[1],&ch,&ara[2],&ch,&ara[3]);
		for(k=0;k<4;k++)
		{
			sum=l=0;
			while(ara[k]!=0)
			{
			md=ara[k]%10;
			ara[k]/=10;
			sum+=(md*pow(2,l));
			l++;
			}
		  if(a[k]!=sum)
		  {
			  y=1;
			  printf("Case %d: No\n",i+1);
			  break;
		  }
		}
		if(y==0)
			printf("Case %d: Yes\n",i+1);
	}
	return 0;
}