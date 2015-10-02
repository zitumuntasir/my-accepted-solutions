#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
using namespace std;
char ch[10000][10000],ch4[10000],ch1[2],ch2[2],ch3[100],ch5[100];
map<char,char>mp;
int main()
{
	long a,b,c,test,d,e,i,j,k,len,l,t;
	scanf("%ld",&test);
	gets(ch1);
	gets(ch2);
    for(t=1;t<=test;t++)
	{
	gets(ch3);
	gets(ch4);
	len=strlen(ch3);
	strcpy(ch[0],ch4);
	strcpy(ch[1],ch3);
	for(i=0;i<len;i++)
	{
		mp[ch3[i]]=ch4[i];
	}
		k=1;
		while(gets(ch5)&&strlen(ch5)!=0)
		{
			k++;
			for(j=0;j<strlen(ch5);j++)
			{
				if(mp[ch5[j]]!=0)
				{
					ch5[j]=mp[ch5[j]];
				}
			}
			strcpy(ch[k],ch5);
		}
		for(l=0;l<=k;l++)
			puts(ch[l]);
		if(t!=test)
			printf("\n");
		mp.clear();
	}
	return 0;
}

