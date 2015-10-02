#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
#include<string>
 using namespace std;
char ch[10000],ch1[10000];
	map<char,string>mp;
int main()
{
	long a,b,c,d,e,i,j,k;

	mp['2']='`',mp['3']='1',mp['4']='2',mp['5']='3',mp['6']='5',mp['7']='5',mp['8']='6';
	mp['9']='7',mp['0']='8',mp['-']='9',mp['=']='0',mp['e']='q',mp['r']='w',mp['t']='e';
	mp['y']='r',mp['u']='t',mp['i']='y',mp['o']='u',mp['p']='i',mp['[']='o',mp[']']='p';
	mp['d']='a',mp['f']='s',mp['g']='d',mp['h']='f',mp['j']='g',mp['k']='h',mp['l']='j';
	mp[';']='k',mp['\'']='l',mp['\\']=';',mp['c']='z',mp['v']='x',mp['b']='c',mp['n']='v';
	mp['m']='b',mp[',']='n',mp['.']='m',mp['/']=',',mp[' ']=' ';
	
	while(gets(ch))
	{
		a=strlen(ch);
		for(i=0;i<a-1;i++)
		{
			if(ch[i]>='A'&&ch[i]<='Z')
			{
				ch[i]=ch[i]+32;
			}
			cout<<mp[ch[i]];
		}
		cout<<mp[ch[i]]<<endl;
	}
return 0;
}