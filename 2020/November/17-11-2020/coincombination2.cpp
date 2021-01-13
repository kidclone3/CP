#include<bits/stdc++.h>
using namespace std;

int f[1000006], c[105];
int MOD=1000000000+7;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int n, x;
cin>>n>>x;
for(int i=0; i<n; i++)
    {
        cin>>c[i];
    }
sort(c,c+n);
for(int i=0; i<n; i++){
    for(int j=c[i]; j<=x; j++){
        if (j==c[i]){
            f[j]%=MOD;
            f[j]++;
            f[j]%=MOD;
            }
        else{
                f[j]+=f[j-c[i]]%MOD;
                f[j]%=MOD;
            }
        }
}
cout<<f[x]%MOD;
}
