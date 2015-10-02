#include<stdio.h>
#include<math.h>
int main()
{
	long a,b,p,num,res=0;
	while(scanf("%ld",&num)&&num!=0)
	{
		p=1;
		if(num==1)
			printf("1\n");
		else if(num==2)
			printf("2\n");
		else
		{
		while(1)
		{
			a=pow(2,p);
			b=pow(2,p+1);
			if(a==num)
			{
				printf("%ld\n",num);
				break;
			}
			else if(num>a&&num<b)
			{
				printf("%ld\n",(num-a)*2);
				break;
			}
			p++;
		}
		
		}

	}
	return 0;
}