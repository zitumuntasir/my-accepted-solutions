#include<stdio.h>
#include<algorithm>
using namespace std;
long ara[50010];
int main()
{
    long test,i,n,mx,cas=0,a,w,cnt=0,y;
    scanf("%ld",&test);
 
    while(test--)
    {
        cnt=0;
        scanf("%ld%ld",&n,&w);
        for(i=0;i<n;i++)
        {
            scanf("%ld%ld",&a,&ara[i]);
        }
        sort(ara,ara+n);
        for(i=0;i<n;i++)
        {
            y=0;
            cnt++;
            mx=ara[i]+w;
            while(ara[i]<=mx&&i<n)
            {
                y=1;
                i++;
            }
            if(y)
            i--;
        }
        printf("Case %ld: %ld\n",++cas,cnt);
    }
    return 0;
}