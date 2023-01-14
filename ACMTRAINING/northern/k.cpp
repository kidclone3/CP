#include<bits/stdc++.h>
using namespace std;
long long n,t,i,j,k,a[1001],dp[1001],s,x,y,z;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    if(a[1]==0 || a[1]==1) dp[1]=1;
    else dp[1]=0;
    for(i=2;i<=n;i++){
        s=0;
        for(j=i;j>0;j--){
            if(a[j]!=0){
                s=a[j];
                if(i<a[j] || j<=i-a[j]) break;
                for(k=i;k>i-a[j];k--) if(a[k]!=0 && a[k]!=s){s=-1;break;}
                if(s==-1) break;
                dp[i]=dp[i]+dp[i-a[j]];
            }
            if(s==0) dp[i]=dp[i]+dp[j-1];
            if(dp[i]>2) dp[i]=2;
        }
        if(dp[i]>2) dp[i]=2;
    }
    // for(i=1;i<=n;i++) cout<<dp[i]<<" ";
    if (dp[n] == 1) cout << "YES"; else cout << "NO";
}
