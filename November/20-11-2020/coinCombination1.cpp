#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int N=155;

int f[1000005],c[N];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin>>n>>x;
    for (int i=0; i<n; i++)
    {
        cin>>c[i];
    }
    sort (c, c+n);
    f[0]=1;
    for (int j=1; j<=x; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (j>=c[i])
                (f[j]+=f[j-c[i]]) %=MOD;
        }
    }
    cout<<f[x];
}
