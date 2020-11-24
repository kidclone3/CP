#include <bits/stdc++.h>
using namespace std;

const int N= 1e6+5;
const int MOD=1e9+7;
int f[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    f[1]=1;
    f[2]=2;
    f[3]=4;
    f[4]=8;
    f[5]=16;
    f[6]=32;
    if (n<=6)
        cout<<f[n];
    else
    {
        for (int i=7; i<=n; i++)
        {
            for (int j=1; j<=6; j++)
            {
                (f[i]+=f[i-j])%=MOD
            }
        }
        cout<<f[n];
    }
}
