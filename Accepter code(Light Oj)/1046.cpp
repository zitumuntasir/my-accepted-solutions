#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
bool visit[11][11];
int xara[]={2,2,-2,-2,1,-1,1,-1};
int yara[]={1,-1,1,-1,2,2,-2,-2};
char ch[12][12];
int ar[11][11],ar1[11][11];
int j,k,cnt,nd,tim,coun,nq,numb,y=0,trn,i,num,rs,res;
struct cor
{
    int p,q,t;
}ara[101];
struct ss{
    int x,y,n;
};
ss u,v,w;
queue<ss>qu;
void bfs(int trn)
{
    while(!qu.empty())
    {
        cnt++;
        for(tim=0;tim<trn;tim++)
        {
            nq=coun;
            coun=0;
            for(numb=0;numb<nq;numb++)
            {
                w=qu.front();
                qu.pop();
               for(nd=0;nd<8;nd++)
               {
                v.x=w.x+xara[nd];
                v.y=w.y+yara[nd];
                v.n=0;
                if(visit[v.x][v.y]==0&&ch[v.x][v.y]!=NULL)
                {
                    ar[v.x][v.y]++;
                    ar1[v.x][v.y]+=cnt;
                    if(ar[v.x][v.y]==rs)
                    {
                        if(ar1[v.x][v.y]<res)
                            res=ar1[v.x][v.y];
                    }
                    visit[v.x][v.y]=1;
                    coun++;
                    qu.push(v);
                }
               }
            }
        }
    }
}
int main()
{
    int test,i,r,c,l=0;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        res=9999999;
        rs=0;
        l=0;
        scanf("%d%d",&r,&c);
        for(j=0;j<r;j++)
        {
            getchar();
            for(k=0;k<c;k++)
            {
                scanf("%c",&ch[j][k]);
                if(ch[j][k]>='1'&&ch[j][k]<='9')
                {
                    ara[l].p=j;
                    ara[l].q=k;
                    ara[l].t=ch[j][k]-48;
                    l++;
                    rs++;
                }
            }
        }
        for(num=0;num<l;num++)
        {
            cnt=y=0;
            coun=1;
            ar[ara[num].p][ara[num].q]++;
            visit[ara[num].p][ara[num].q]=1;
            u.x=ara[num].p;
            u.y=ara[num].q;
            u.n=ara[num].t;
            qu.push(u);
            bfs(u.n);
          while(!qu.empty()) qu.pop();
          for(j=0;j<r;j++)
          {
            for(k=0;k<c;k++)
            {
              visit[j][k]=0;
            }
          }
        }
        if(rs<=1) printf("Case %d: 0\n",i+1);
        else if(res==9999999)
            printf("Case %d: -1\n",i+1);
        else
            printf("Case %d: %d\n",i+1,res);
         for(j=0;j<r;j++)
         {
             for(k=0;k<c;k++)
             {
                 ar[j][k]=0;
                     ar1[j][k]=0;
                 ch[j][k]=NULL;
             }
         }
    }
    return 0;
}