#include<stdio.h>
#include<iostream>
#include<map>
#include<iomanip>
#include<string>
#include<string.h>
using namespace std;
char ch[100],ch1[20];
map<string,string>mp;
map<char,char>mp1;
int main()
{
	long a,b,c,d,e,i=0,j,k,l,p,len,t,len1;
	mp1['B']='1',mp1['P']='1',mp1['F']='1',mp1['V']='1';
    mp1['C']='2',mp1['S']='2',mp1['K']='2',mp1['G']='2';mp1['J']='2',mp1['Q']='2',mp1['X']='2',mp1['Z']='2';
    mp1['D']='3',mp1['T']='3';
    mp1['L']='4';
    mp1['M']='5',mp1['N']='5';
    mp1['R']='6';
	cout<<setw(13)<<"NAME"<<setw(33)<<"SOUNDEX CODE"<<endl;
	while(gets(ch))
	{
		i++;
     	l=1;
		len=strlen(ch);
		ch1[0]=ch[0];
		for(k=1;k<len;k++)
		{
			if(mp1[ch[k]]!=0&&(mp1[ch[k]]!=mp1[ch[k-1]]))
			{
				ch1[l]=mp1[ch[k]];
				l++;
				if(l>3)
					break;
			}
		}
		if(l<4)
		{
			for(p=l;p<4;p++)
			{
				ch1[p]='0';
			}
		}
		ch1[4]='\0';
		cout<<setw(9+len)<<ch<<setw(38-(9+len))<<ch1<<endl;
	}
	mp.clear();
    mp1.clear();
	cout<<setw(32)<<"END OF OUTPUT"<<endl;
	return 0;
}
