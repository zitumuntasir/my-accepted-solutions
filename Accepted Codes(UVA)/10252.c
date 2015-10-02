#include<stdio.h>
#include<string.h>
char ch[10000],ch1[10000],ch2[10000],ch3[10000];
long ara[10000],ara1[10000],ara2[10000];
int main()
{
	long a,b,c,d,e,i,j,k,len1,len2,max,q;
	while(gets(ch))
	{
		max=0,q=0;
		gets(ch1);
		len1=strlen(ch);
		len2=strlen(ch1);
		for(i=0;i<len1;i++)
		{
			ara[ch[i]]++;
		}
		for(i=0;i<len2;i++)
		{
			ara1[ch1[i]]++;
		}
		for(i=97;i<=122;i++)
		{
			if(ara[i]!=0&&ara1[i]!=0)
			{
				q=1;
				if(i>=max)
				{
					max=i;
				}
				if(ara[i]>=ara1[i])
				{
					ara2[i]=ara1[i];
				}
				else
				{
					ara2[i]=ara[i];
				}
			}
		}
		if(len1==0||len2==0)
			printf("\n");
		else if(q==0)
			printf("\n");
		else
		{
		for(j=97;j<max;j++)
		{
			if(ara2[j]!=0)
			{
				for(k=0;k<ara2[j];k++)
				{
					printf("%c",j);
				}
			}
		}
		if(ara2[j]!=0)
		{
				for(k=0;k<ara2[j]-1;k++)
				{
					printf("%c",j);
				}
				printf("%c\n",j);
		}
		}
		for(i=97;i<=122;i++)
		{
			ara[i]=0;
			ara1[i]=0;
			ara2[i]=0;
		}
		
	}
	return 0;
}