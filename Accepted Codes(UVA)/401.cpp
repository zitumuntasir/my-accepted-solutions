#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<string.h>
using namespace std;
char ch[10000],ch1[10000],ch2[10000],ch3[10000];
map<char,char>mp;
int main()
{
	mp['E']='3',mp['3']='E',mp['J']='L',mp['L']='J',mp['S']='2',mp['2']='S',mp['Z']='5';
	mp['5']='Z',mp['A']='A',mp['H']='H',mp['I']='I',
	mp['M']='M',mp['O']='O',mp['T']='T',mp['U']='U';
	mp['V']='V',mp['W']='W',mp['X']='X',mp['Y']='Y',mp['1']='1',mp['8']='8';

	long a,b,c,d,e,i,j,k,m,l,y,n,p;
	while(gets(ch))
	{
		n=0,m=0,y=0,p=0;
		a=strlen(ch);
		for(i=0,j=a-1;i<a,j>=0;i++,j--)
		{
			ch1[i]=ch[j];
		}
		ch1[i]='\0';
		if(strcmp(ch1,ch)==0)
			p=1;
		for(i=0;i<a;i++)
		{
			if(mp[ch[i]]!='\0')
			{
			y=1;
			ch2[i]=mp[ch[i]];
			}
			else
			{
				n=1;
			}
		}
		ch2[i]='\0';
		for(k=0,l=a-1;k<a,l>=0;k++,l--)
		{
			ch3[k]=ch2[l];
		}
		ch3[k]='\0';
		if((strcmp(ch3,ch)==0)&&n==0)
		{
			m=1;
		}
		if(m==1&&p==1)
		{
			printf("%s -- is a mirrored palindrome.\n\n",ch);
		}
		else if(p==1&&m==0)
		{
			printf("%s -- is a regular palindrome.\n\n",ch);

		}
		else if(p==0&&m==1)
		{
			printf("%s -- is a mirrored string.\n\n",ch);
		}
		else if(p==0&&m==0)
		{
			printf("%s -- is not a palindrome.\n\n",ch);
		}

	}
	return 0;
}
