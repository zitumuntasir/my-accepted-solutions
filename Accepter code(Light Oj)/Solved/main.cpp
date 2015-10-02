#include <bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define fsf fscanf
#define fpf fprintf
#define ret return
#define ll long long
#define inf 1e13
#define pi 3.14159265358979323846
#define eps 1e-9
#define even(a) ((a)%2==0)
#define odd(a) ((a)%2==1)
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
long numOfTraversal[3048580];
bool currentStatus[3048580];
long limit(long D)
{
    long val = 1, i;
    for(i = 0; i < D; i++)
    {
        val *= 2;
    }
    ret (val - 1);
}
bool CurrentStatus()
{

}
long TraverseTree(long l)
{
    long res, i, rootTraverse;
    for(i = 1;;)
    {
        res = i;
        if(currentStatus[i] == false)
        {
            rootTraverse = numOfTraversal[i];
            i *= 2;
            numOfTraversal[i] = rootTraverse / 2;
            if(odd(rootTraverse)) numOfTraversal[i]++;
            currentStatus[i] = numOfTraversal[i] % 2;
        }
        else
        {
            rootTraverse = numOfTraversal[i];
            i = (i * 2) + 1;
            numOfTraversal[i] = rootTraverse / 2;
            currentStatus[i] = numOfTraversal[i] % 2;
        }
        if(i > l) ret res;
    }
}
int main()
{
    long i, I, test, rootTraverse, D, l;
    while(sf("%ld",&test) && test > 0)
    {
    while(test--)
    {
     sf("%ld %ld", &D, &I);
     numOfTraversal[1] = I - 1;
     currentStatus[1] = numOfTraversal[1] % 2;
     l = limit(D);
     pf("%ld\n", TraverseTree(l));
    }
    }
    ret 0;
}
