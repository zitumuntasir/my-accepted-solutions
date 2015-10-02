#include<stdio.h>
#include<string.h>
char dividend[1000000];
char ch2[1000000];
char quotient[10000];
int main()
{
	long a,b,c,d,e,i,j,k,divisor,reminder,mod,len,num;
	while(scanf("%ld",&divisor)!=EOF)
	{		
		for(num=0;;num++)
		{
			mod=0,k=0;
			dividend[num]='1';
			dividend[num+1]='\0';
		len=strlen(dividend)-1;
		for(i=0;i<=len;i++)
		{
			a=dividend[i]-48;
			b=(mod*10)+a;
			c=b/divisor;
			mod=b%divisor;
			if(c>0)
			{
			quotient[k]=c+48;
			k++;
			}
			else if(k!=0)
			{
			quotient[k]=c+48;
			k++;
			}
		}
		quotient[k]='\0';
		if(mod==0)
		{
			printf("%ld\n",len+1);
			break;
		}
		}

	}
	return 0;
}
