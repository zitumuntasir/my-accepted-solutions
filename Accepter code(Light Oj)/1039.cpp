#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
char sr[5],ds[5],a[100],b[100],c[100],dr[5];
int wrd[5],dst,drv,i;
//map<string,int>mp;
//map<string,int>mp1[i];
//map<string,int>cst[i]
//int mp[50][262627];
bool mp1[50][262627];
int cst[50][262627];
int res,str,src;
string st;
queue<string>qu;
char s;
void bfs()
{
	while(!qu.empty())
	{
		st=qu.front();
		str=((st[0]-97)*10*10*10*10)+((st[1]-97)*10*10)+((st[2]-97));
		qu.pop();
		if(st[0]=='z') s='a';
		else
			s=st[0]+1;
		drv=((s-97)*10*10*10*10)+((st[1]-97)*10*10)+((st[2]-97));
		dr[0]=s,dr[1]=st[1],dr[2]=st[2],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}
				if(st[0]=='a') s='z';
		else
			s=st[0]-1;
		drv=((s-97)*10*10*10*10)+((st[1]-97)*10*10)+((st[2]-97));
		dr[0]=s,dr[1]=st[1],dr[2]=st[2],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}

		if(st[1]=='z') s='a';
		else
			s=st[1]+1;
		drv=((st[0]-97)*10*10*10*10)+((s-97)*10*10)+((st[2]-97));
		dr[1]=s,dr[0]=st[0],dr[2]=st[2],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}
				if(st[1]=='a') s='z';
		else
			s=st[1]-1;
		drv=((st[0]-97)*10*10*10*10)+((s-97)*10*10)+((st[2]-97));
		dr[1]=s,dr[0]=st[0],dr[2]=st[2],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}

		if(st[2]=='z') s='a';
		else
			s=st[2]+1;
		drv=((st[0]-97)*10*10*10*10)+((st[1]-97)*10*10)+(s-97);
		dr[2]=s,dr[0]=st[0],dr[1]=st[1],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}
				if(st[2]=='a') s='z';
		else
			s=st[2]-1;
		drv=((st[0]-97)*10*10*10*10)+((st[1]-97)*10*10)+(s-97);
		dr[2]=s,dr[0]=st[0],dr[1]=st[1],dr[3]=NULL;
		if(mp1[i][drv]==0&&mp1[i][drv]==0) 
		{
			mp1[i][drv]=1;
			cst[i][drv]=cst[i][str]+1;
			if(drv==dst) break;
			qu.push(dr);
		}
	}
}
int main()
{
	int p,q,r,j,num,len1,len2,len,test;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%s",sr);
		qu.push(sr);
		src=((sr[0]-97)*10*10*10*10)+((sr[1]-97)*10*10)+(sr[2]-97);
		scanf("%s",ds);
		dst=((ds[0]-97)*10*10*10*10)+((ds[1]-97)*10*10)+(ds[2]-97);
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			scanf("%s%s%s",a,b,c);
			len=strlen(a);
			len1=strlen(b);
			len2=strlen(c);
			for(p=0;p<len;p++)
			{
				for(q=0;q<len1;q++)
				{
					for(r=0;r<len2;r++)
					{
						wrd[0]=a[p]-97,wrd[1]=b[q]-97,wrd[2]=c[r]-97;
						res=(wrd[0]*10*10*10*10)+(wrd[1]*10*10)+(wrd[2]);
						mp1[i][res]=1;
					}
				}
			}
		}
		if(src==dst&&mp1[i][src]==0) printf("Case %d: 0\n",i+1);
		else if(mp1[i][src]==1) printf("Case %d: -1\n",i+1);
		else
		{
		mp1[i][src]=1;
		cst[i][src]=0;
		bfs();
		if(cst[i][dst]==0)
			printf("Case %d: -1\n",i+1);
		else
		printf("Case %d: %d\n",i+1,cst[i][dst]);
			//bfs();
		}
	//	cout<<"Case "<<i+1<<": "<<cst[i][dst]<<endl;
		while(!qu.empty()) qu.pop();
		//for(j=0;j<=262627;j++)
		//{
		//	mp1[i][j]=mp[j]=cst[i][j]=0;
		//}
	}
	return 0;
}
