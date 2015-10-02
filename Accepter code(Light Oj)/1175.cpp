#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;
char ch[210][210];
int dist[210][210],no,res,y,dst[210][210],i,j;
bool visit[210][210];
int xara[]={0,0,-1,1};
int yara[]={1,-1,0,0};
int l,r,c;
void clr()
{
	for(i=0;i<=r;i++)
	{
		for(j=0;j<=c;j++)
		{
			visit[i][j]=0;
			dist[i][j]=0;
			dst[i][j]=0;
			ch[i][j]=NULL;
		}
	}
}
typedef struct{
	int x,y;
}node;
node p,q;
queue<node>q1,q2;
void bfs()
{
	while(!q2.empty())
	{
		p=q2.front();
		if(dist[p.x][p.y]>l)
			break;
		if((p.x==r-1||p.y==c-1||p.x==0||p.y==0)&&ch[p.x][p.y]=='J')
		{
			y=1;
			res=dist[p.x][p.y];
			break;
		}
		if(ch[p.x][p.y]=='J')
		{
		ch[p.x][p.y]='.';
		for(i=0;i<4;i++)
		{
			q.x=p.x+xara[i];
			q.y=p.y+yara[i];
			if(q.x>=0&&q.x<r&&q.y>=0&&q.y<c&&ch[q.x][q.y]=='.'&&visit[q.x][q.y]==0)
			{
				dist[q.x][q.y]=dist[p.x][p.y]+1;
				ch[q.x][q.y]='J';
				q2.push(q);
			}
		}
		}
		q2.pop();
	}
}
 void bfs1()
 {
	 while(!q1.empty())
	 {
		 p=q1.front();
		 if(dst[p.x][p.y]>l)
			 break;
		 ch[p.x][p.y]='#';
		 for(i=0;i<4;i++)
		 {
			 q.x=p.x+xara[i];
			 q.y=p.y+yara[i];
			 if(q.x>=0&&q.x<r&&q.y>=0&&q.y<c&&ch[q.x][q.y]!='#'&&visit[q.x][q.y]==0)
			 {
				 visit[q.x][q.y]=1;
				 dst[q.x][q.y]=dst[p.x][p.y]+1;
				 ch[q.x][q.y]='F';
				 q1.push(q);
			 }
		 }
		 q1.pop();
	 }
 }
int main()
{
	char s;
	int test,t,j,k;
	scanf("%d",&test);
	for(t=0;t<test;t++)
	{
		scanf("%d%d",&r,&c);
		clr();
		for(j=0;j<r;j++)
		{
			getchar();
			for(k=0;k<c;k++)
			{
				scanf("%c",&s);
				ch[j][k]=s;
				if(s=='F')
				{
					p.x=j,p.y=k;
					visit[p.x][p.y]=1;
					q1.push(p);
				}
				else if(s=='J')
				{
					p.x=j,p.y=k;
					visit[p.x][p.y]=1;
					q2.push(p);
				}
			}
			ch[j][k]=NULL;
		}
		no=y=res=0;
		for(l=0;;l++)
		{
			if(!q2.empty())
			{
			bfs();
			}
			else
				break;
			if(y==1)
			{
				printf("Case %d: %d\n",t+1,res+1);
				break;
			}
			if(!q1.empty())
			bfs1();
		}
			if(y==0)
			{
				printf("Case %d: IMPOSSIBLE\n",t+1);
			}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	}
	return 0;
}
