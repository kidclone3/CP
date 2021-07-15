#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <iostream>
#define ll long long
#define INF 0x3f3f3f
using namespace std;
const int N=300000+1000;
int a[N];
int vis[N];
int main()
{
    int n,k,m,i,st,ans;
    ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    st=1;
    for(i=st+k-1;i<=n;i++)
    {
        if(a[i]-a[st]+1<=m)
        {
            ans++;
            vis[i]=1;
        }
        else
        {
            while(vis[st+1])
            {
                st++;
            }
            st++;
        }
    }
    if(k==1)
        printf("%d\n",n);
    else printf("%d\n",ans);
}
 
 
