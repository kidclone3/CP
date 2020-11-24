#include <bits/stdc++.h>
using namespace std;

int coins[105];
int f[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("minimizingCoins.inp", "r", stdin);
    //freopen("minimizingCoins.out", "w", stdout);
    int n, x;
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
    cin>>coins[i];
    }
    sort(coins, coins+n);
    // Quy dinh: j la so tien j.
    // Khoi tao mang f dau tien voi dong xu dau tien.
    // Tieu chi: neu j = coins[0] thi f[j]=1
    // Neu j lon hon coins[0] thi sao?
    // Neu co 1 so a thuoc N sao cho a.coins[0]=j thi f[j]=a;
    // Con lai thi bo qua (de = 0)
    /*for(int j=coins[0]; j<=x; j+=coins[0])
    {
        if(j==coins[0]) f[j]=1;
        else
        {
            f[j]=f[j-coins[0]]+1;
        }
    }*/
    //for(int j=0; j<=x; j++) cout<<f[j]<<" ";
    //    cout<<'\n';

    //for(int i=1; i<=x; i++) cout<<f[i]<<" ";
    //        cout<<'\n';
    memset(f, -1, sizeof(f));
    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=x; j++){
           /* if(coins[i]==j)
            {
                f[j]=1;
            }
            else if(coins[i]<j)
            {
                if(f[j-coins[i]]==0)
                {
                    continue;
                }
                if (f[j]==0)
                {
                    f[j]=f[j-coins[0]]+1;
                }
                else {
                    f[j]=min(f[j], f[j-coins[i]]+1);
                }
            }
            */
            if(coins[i]==j) f[j]=1;
            else {
                    if(f[j]!=-1 && f[j-coins[i]]!=-1)
                        f[j]=min(f[j], f[j-coins[i]]+1);
                    else if(f[j]==-1 && f[j-coins[i]]!=-1)
                        {
                            f[j]=f[j-coins[i]]+1;
                        }
                }
            //for(int j=1; j<=x; j++)
            //cout<<f[j] <<" ";
            //    cout<<'\n';
        }
    }
    cout<<f[x];
}
