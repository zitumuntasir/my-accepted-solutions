#include<stdio.h>
#include<string.h>
char ch[1000000];
long ara[1000],ara1[1000];
int main()
{
	long a,b,c,d,e,i,j,k,max1,max2,p,q;
	while(gets(ch))
	{
		max1=0,max2=0;
		a=strlen(ch);
		for(i=0;i<a;i++)
		{
			if((ch[i]>='A'&&ch[i]<='Z')&&ch[i]!=' ')
			{
				ara[ch[i]]++;
				if(max1<=ara[ch[i]])
				{
					max1=ara[ch[i]];
					p=ch[i];
				}
			}
		else if((ch[i]>='a'&&ch[i]<='z')&&ch[i]!=' ')
			{
				ara1[ch[i]]++;
				if(max2<=ara1[ch[i]])
				{
					max2=ara1[ch[i]];
					q=ch[i];
				}
			}
		}


		if(max1!=0||max2!=0)
		{
		if(max1==max2)
		{
			for(i=65;i<=90;i++)
			{
				if(ara[i]==max1)
				{
					printf("%c",i);
				}
			}
			for(i=97;i<=122;i++)
			{
				if(ara1[i]==max2)
				{
					printf("%c",i);
				}
			}
			printf(" %ld\n",max1);
		}
		else if(max1<max2)
		{
			for(i=97;i<=122;i++)
			{
				if(ara1[i]==max2)
				{
					printf("%c",i);
				}
			}
			printf(" %ld\n",max2);
		}
		else if(max1>max2)
		{
			for(i=65;i<=90;i++)
			{
				if(ara[i]==max1)
				{
					printf("%c",i);
				}
			}
			printf(" %ld\n",max1);
		}
		}
		if(max1==0&&max2==0)
		{
			for(i=65;i<=90;i++)
				printf("%c",i);
			for(i=97;i<=122;i++)
				printf("%c",i);
			printf(" 0\n");
		}
		for(i=65,j=97;i<=90;i++,j++)
		{
			ara[i]=0,ara1[j]=0;
		}
	}
	return 0;
}