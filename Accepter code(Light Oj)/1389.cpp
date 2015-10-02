#include<stdio.h>
#include<string.h>
char ch[103];
int main()
{
	int test,i,j,n,cnt,cas=0;
	scanf("%d",&test);
	while(test--)
	{
		cnt=0;
		scanf("%d",&n);
		scanf("%s",ch);
		for(i=0;i<n;i++)
		{
			if(i&&ch[i]=='.'&&ch[i-1]=='.')
			{
				ch[i-1]='#';
				ch[i+1]='#';
				ch[i]='#';
				cnt++;
				i++;
			}
			else if(i&&ch[i]=='#'&&ch[i-1]=='.')
			{
				ch[i-1]='#';
				ch[i+1]='#';
				cnt++;
			}
		}
		if(ch[n-1]=='.') cnt++;
		printf("Case %d: %d\n",++cas,cnt);
	}
	return 0;
}
