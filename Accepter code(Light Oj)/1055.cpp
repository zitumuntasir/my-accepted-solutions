#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
int xara[]={0,0,1,-1};
int yara[]={1,-1,0,0};
char ch[11][11];
int m,o,l,cnt,y,t,n,res;
struct ss{
	int x,y;
};
ss a,b,c,p,q,r,u,v,w,p1,q1,r1;
bool visit[11][11][11][11][11][11];
int cst[11][11][11][11][11][11];
queue<ss>qu;
void bfs()
{
  while(!qu.empty())
  {
	  	  p=qu.front();
		  p1=p;
		  qu.pop();
		  q=qu.front();
		  q1=q;
		  qu.pop();
		  r=qu.front();
		  r1=r;
		  qu.pop();
		  	visit[p.x][p.y][q.x][q.y][r.x][r.y]=1;
	  for(t=0;t<4;t++)
	  {
		  p=p1,q=q1,r=r1;
		  u.x=(xara[t]+p1.x);
		  u.y=(yara[t]+p1.y);
		  v.x=(xara[t]+q1.x);
		  v.y=(yara[t]+q1.y);
		  w.x=(xara[t]+r1.x);
		  w.y=(yara[t]+r1.y);
		  m=n=o=0;
		  for(l=0;l<3;l++)
		  {
			  if((ch[u.x][u.y]=='.'||ch[u.x][u.y]=='X')&&m==0&&(u.x!=q.x||u.y!=q.y)&&(u.x!=r.x||u.y!=r.y))
			  {
				  m=1;
				  p=u;
			  }
			  if((ch[v.x][v.y]=='.'||ch[v.x][v.y]=='X')&&n==0&&(v.x!=p.x||v.y!=p.y)&&(v.x!=r.x||v.y!=r.y))
			  {
				  n=1;
				  q=v;
			  }
			  if((ch[w.x][w.y]=='.'||ch[w.x][w.y]=='X')&&o==0&&(w.x!=p.x||w.y!=p.y)&&(w.x!=q.x||w.y!=q.y))
			  {
				  o=1;
				  r=w;
			  }
		  }
		  if(m==0) p=p1;
		  if(n==0) q=q1;
		  if(o==0) r=r1;
		  if(visit[p.x][p.y][q.x][q.y][r.x][r.y]==0)
		  {
			  visit[p.x][p.y][q.x][q.y][r.x][r.y]=1;
			  cst[p.x][p.y][q.x][q.y][r.x][r.y]=cst[p1.x][p1.y][q1.x][q1.y][r1.x][r1.y]+1;
			  if(ch[p.x][p.y]=='X'&&ch[q.x][q.y]=='X'&&ch[r.x][r.y]=='X')
			  {
				  res=cst[p.x][p.y][q.x][q.y][r.x][r.y];
				  y=1;
				  break;
			  }
			  qu.push(p);
			  qu.push(q);
			  qu.push(r);
		  }

	  }
	  if(y) break;
  }
}
int main()
{
	int test,i,j,n,num,k,c1,c2,c3,c4,c5,c6;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			getchar();
		   for(k=0;k<num;k++)
		   {
			   scanf("%c",&ch[j][k]);
			   if(ch[j][k]=='A')
			   {
				   ch[j][k]='.';
				   a.x=j;
				   a.y=k;
				   qu.push(a);
			   }
			   	if(ch[j][k]=='B')
			   {
					ch[j][k]='.';
				   b.x=j;
				   b.y=k;
				   qu.push(b);
			   }
				if(ch[j][k]=='C')
			   {
					ch[j][k]='.';
				   c.x=j;
				   c.y=k;
				   qu.push(c);
			   }
		   }
		}
		res=y=0;
		bfs();
		if(res==0)
		{
			printf("Case %d: trapped\n",i+1);
		}
		else
			printf("Case %d: %d\n",i+1,res);
		while(!qu.empty()) qu.pop();
		for(c1=0;c1<num;c1++)
		{
			for(c2=0;c2<num;c2++)
			{
				ch[c1][c2]=NULL;
				for(c3=0;c3<num;c3++)
					for(c4=0;c4<num;c4++)
						for(c5=0;c5<num;c5++)
							for(c6=0;c6<num;c6++)
								visit[c1][c2][c3][c4][c5][c6]=cst[c1][c2][c3][c4][c5][c6]=0;
		}
		}
	}
	return 0;
}
